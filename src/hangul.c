/* 한글처리용입니다. */
#include "conf.h"
#include "sysdep.h"
#include "wchar.h"
#include "locale.h"
#include "locale.h"

int is_hangul(str)
char *str;
{
  if((str[0] & 0x80) != 0 && (str[1] & 0x80) != 0 && (str[2] & 0x80) != 0)
    return 1;
  return 0;
}

int is_han(str)
char *str;
{
  int i;
  for (i = 0; i < strlen(str);i += 3) {
    if (!is_hangul(str+i)) return 0;
  }
  return 1;
}

int under_han(str)
wchar_t str;
{
    setlocale(LC_ALL, "");	

    if (str >= 0xAC00 && str <= 0xD7A3) {
	
    int josa = (str - 0xAC00) % 28;

    if (josa == 0) 
	{
		return 0;
	} else {
		return 1;
	}
	  }
    return 0;
}

char *check_josa(char *str, int m)
{
    setlocale(LC_ALL, "");	
    int required_size = mbstowcs(NULL, str, 0) + 1;	
	int yn = 0;
	
	char *josalist[7][2] =  {
		{ "이", "가" }, { "을", "를" }, { "과", "와" }, 
		{ "이라고", "라고" }, { "은", "는" }, { "으로", "로" }, { "\n", "\n"}}; 
	char *re=NULL;

	if(!str || !*str) {
		re = "<에러!>";
		return(re);
	}

    wchar_t *han_str = (wchar_t *)malloc(required_size * sizeof(wchar_t));	
	mbstowcs(han_str, str, required_size);
	if(under_han(han_str[wcslen(han_str) - 1]))
		yn = 0;
	else   
		yn = 1;
	re = josalist[m][yn];
    free(han_str);
    return(re);         
}
