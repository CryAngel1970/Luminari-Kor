/****************************************************************************
 *  Realms of Luminari
 *  File:     hl_events.c
 *  Usage:    alternate event system
 *  Header:   hl_events.h
 *  Authors:  Eric Green (ejg3@cornell.edu)
 *            Ported to Luminari by Zusuk
 ****************************************************************************/

#include "conf.h"
#include "sysdep.h"

#include "structs.h"
#include "utils.h"
#include "hl_events.h"

/* number of queues to use (reduces enqueue cost) */
#define NUM_EVENT_QUEUES 10

struct queue *event_q; /* the event queue */

/**************/
/* queue code */

/**************/

struct queue
{
  struct q_element *head[NUM_EVENT_QUEUES], *tail[NUM_EVENT_QUEUES];
};

struct q_element
{
  void *data;
  long key;
  struct q_element *prev, *next;
};

/* external variables */
extern unsigned long pulse;

/* returns a new, initialized queue */
struct queue *queue_init(void)
{
  struct queue *q;

  CREATE(q, struct queue, 1);

  return q;
}

/* add data into the priority queue q with key */
struct q_element *queue_enq(struct queue *q, void *data, long key)
{
  struct q_element *qe, *i;
  int bucket;

  CREATE(qe, struct q_element, 1);
  qe->data = data;
  qe->key = key;

  bucket = key % NUM_EVENT_QUEUES; /* which queue does this go in */

  if (!q->head[bucket])
  { /* queue is empty */
    q->head[bucket] = qe;
    q->tail[bucket] = qe;
  }
  else
  {
    for (i = q->tail[bucket]; i; i = i->prev)
    {

      if (i->key < key)
      { /* found insertion point */
        if (i == q->tail[bucket])
          q->tail[bucket] = qe;
        else
        {
          qe->next = i->next;
          i->next->prev = qe;
        }

        qe->prev = i;
        i->next = qe;
        break;
      }
    }

    if (i == NULL)
    { /* insertion point is front of list */
      qe->next = q->head[bucket];
      q->head[bucket] = qe;
      qe->next->prev = qe;
    }
  }

  return qe;
}

/* remove queue element qe from the priority queue q */
void queue_deq(struct queue *q, struct q_element *qe)
{
  int i;

  assert(qe);

  i = qe->key % NUM_EVENT_QUEUES;

  if (qe->prev == NULL)
    q->head[i] = qe->next;
  else
    qe->prev->next = qe->next;

  if (qe->next == NULL)
    q->tail[i] = qe->prev;
  else
    qe->next->prev = qe->prev;

  free(qe);
}

/*
 * removes and returns the data of the
 * first element of the priority queue q
 */
void *queue_head(struct queue *q)
{
  void *data;
  int i;

  i = pulse % NUM_EVENT_QUEUES;

  if (!q->head[i])
    return NULL;

  data = q->head[i]->data;
  queue_deq(q, q->head[i]);
  return data;
}

/*
 * returns the key of the head element of the priority queue
 * if q is NULL, then return the largest unsigned number
 */
long queue_key(struct queue *q)
{
  int i;

  i = pulse % NUM_EVENT_QUEUES;

  if (q->head[i])
    return q->head[i]->key;
  else
    return LONG_MAX;
}

/* returns the key of queue element qe */
long queue_elmt_key(struct q_element *qe)
{
  return qe->key;
}

/* free q and contents */
void queue_free(struct queue *q)
{
  int i;
  struct q_element *qe, *next_qe;

  for (i = 0; i < NUM_EVENT_QUEUES; i++)
    for (qe = q->head[i]; qe; qe = next_qe)
    {
      next_qe = qe->next;
      free(qe);
    }

  free(q);
}

/**************/
/* event code */
/**************/

/* initializes the event queue */
void event_init(void)
{
  event_q = queue_init();
}

/* creates an event and returns it */
struct event *event_create(EVENTFUNC(*func), void *event_obj, long when)
{
  struct event *new_event;

  if (when < 1) /* make sure its in the future */
    when = 1;

  CREATE(new_event, struct event, 1);
  new_event->func = func;
  new_event->event_obj = event_obj;
  new_event->q_el = queue_enq(event_q, new_event, when + pulse);

  return new_event;
}

/* removes the event from the system */
void event_cancel(struct event *event)
{
  if (!event)
  {
    log("SYSERR:  Attempted to cancle a NULL event");
    return;
  }

  queue_deq(event_q, event->q_el);

  if (event->event_obj)
    free(event->event_obj);
  free(event);
}

/* Process any events whose time has come. */
void event_process(void)
{
  struct event *the_event;
  long new_time;

  while ((long)pulse >= queue_key(event_q))
  {
    if (!(the_event = (struct event *)queue_head(event_q)))
    {
      log("SYSERR: Attempt to get a NULL event");
      return;
    }

    /* call event func, reenqueue event if retval > 0 */
    if ((new_time = (the_event->func)(the_event, the_event->event_obj)) > 0)
      the_event->q_el = queue_enq(event_q, the_event, new_time + pulse);
    else
    {
      if (new_time == 0 && the_event)
        free(the_event);
      if (new_time < 0)
        return;
    }
  }
}

/* returns the time remaining before the event */
long event_time(struct event *event)
{
  long when;

  when = queue_elmt_key(event->q_el);

  return (when - pulse);
}

/* frees all events in the queue */
void event_free_all(void)
{
  struct event *the_event;

  while ((the_event = (struct event *)queue_head(event_q)))
  {
    if (the_event->event_obj)
      free(the_event->event_obj);
    free(the_event);
  }

  queue_free(event_q);
}
