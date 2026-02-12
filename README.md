번역된 마크다운 문서의 형식이 기존과 다르게 보이는 이유는 크게 두 가지입니다. 첫째는 **앵커 링크(목차 클릭 시 이동)의 규칙** 때문이고, 둘째는 **마크다운의 줄바꿈(Line Break) 특성** 때문입니다.

요청하신 대로 **기존 영문 README의 공백, 빈 행, 구조를 1:1로 완벽하게 유지**하면서, 한글 제목에 맞게 링크가 정상 작동하도록 수정한 최종 버전을 드립니다. 아래 내용을 그대로 복사해서 사용하세요.

---

# LuminariMUD

Pathfinder/D&D 3.5 시스템을 구현한 텍스트 기반 멀티플레이어 온라인 롤플레잉 게임(MUD) 서버입니다. 견고한 tbaMUD/CircleMUD 기반 위에 광범위한 커스텀 기능이 추가되었습니다.

## 목차

* [빠른 시작](https://www.google.com/search?q=%23%EB%B9%A0%EB%A5%B8-%EC%8B%9C%EC%9E%91) - [docs/GETTING_STARTED.md](https://www.google.com/search?q=docs/GETTING_STARTED.md)도 참고하세요.
* [개요](https://www.google.com/search?q=%23%EA%B0%9C%EC%9A%94)
* [주요 기능](https://www.google.com/search?q=%23%EC%A3%BC%EC%9A%94-%EA%B8%B0%EB%8A%A5)
* [설치 방법](https://www.google.com/search?q=%23%EC%84%A4%EC%B9%98-%EB%B0%A9%EB%B2%95)
* [사용법](https://www.google.com/search?q=%23%EC%82%AC%EC%9A%A9%EB%B2%95)
* [문서](https://www.google.com/search?q=%23%EB%AC%B8%EC%84%9C)
* [기여하기](https://www.google.com/search?q=%23%EA%B8%B0%EC%97%AC%ED%95%98%EA%B8%B0)
* [커뮤니티](https://www.google.com/search?q=%23%EC%BB%A4%EB%AE%A4%EB%8B%88%ED%8B%B0)
* [라이선스](https://www.google.com/search?q=%23%EB%9D%BC%EC%9D%B4%EC%84%A0%EC%8A%A4)
* [감사의 말](https://www.google.com/search?q=%23%EA%B0%90%EC%82%AC%EC%9D%98-%EB%A7%90)

## 빠른 시작

다음의 간단한 단계를 통해 LuminariMUD를 빠르게 실행할 수 있습니다:

### 사전 요구 사항

먼저 필요한 라이브러리를 설치합니다:

```bash
# Ubuntu/Debian/WSL2
sudo apt-get update
sudo apt-get install -y build-essential git make autoconf automake \
                        libcrypt-dev libgd-dev libmariadb-dev \
                        libcurl4-openssl-dev libssl-dev mariadb-server \
                        cmake libtool pkg-config gdb valgrind

```

### 설치 방법

```bash
# 1. 저장소 클론
git clone https://github.com/LuminariMUD/Luminari-Source.git
cd Luminari-Source

# 2. 배포 스크립트 실행
#    이 스크립트가 의존성, 데이터베이스, 월드 데이터, 빌드 등 모든 것을 처리합니다.
#    실행 중 MySQL 루트 비밀번호 입력 프롬프트가 나타납니다.
./scripts/deploy.sh

# 3. MUD 서버 시작
./bin/circle -d lib

```

이제 끝났습니다! 아무 MUD 클라이언트를 사용하여 `localhost:4000`으로 접속하세요.

### `deploy.sh`가 하는 일

배포 스크립트는 다음 작업을 자동으로 수행합니다:

* 설정 파일 복사 (.example.h → .h)
* 누락된 의존성 설치
* MariaDB 데이터베이스 설정 (루트 비밀번호 입력 필요)
* 생성된 비밀번호로 데이터베이스 및 사용자 생성
* 월드 데이터 초기화 (존, 방, 몹, 아이템)
* Autotools(권장) 또는 CMake를 사용하여 MUD 빌드
* 필요한 모든 디렉토리 및 심볼릭 링크 생성

**선택적 플래그:**

* `--auto` - 가능한 경우 프롬프트 건너뛰기 (MySQL 루트 비번은 여전히 필요)
* `--skip-db` - 데이터베이스 설정 건너뛰기 (권장하지 않음)
* `--dev` - 디버그 심볼이 포함된 개발용 빌드
* `--prod` - 프로덕션 최적화 빌드

자세한 정보는 [docs/deployment/DEPLOYMENT_GUIDE.md](https://www.google.com/search?q=docs/deployment/DEPLOYMENT_GUIDE.md)를 참조하세요.

## 개요

LuminariMUD는 텍스트 기반 멀티플레이어 환경에서 Pathfinder/D&D 3.5 규칙 시스템을 구현한 기능 풍부한 MUD 서버입니다. 검증된 tbaMUD/CircleMUD 코드베이스를 기반으로 구축되었으며 성경, 드래곤랜스(Dragonlance), 포가튼 렐름(Forgotten Realms) 이야기에서 영감을 받은 독창적인 세계를 특징으로 합니다.

### 프로젝트 비전

지향점이 비슷한 게이머들이 안전하고 친근한 커뮤니티를 형성할 수 있도록, 독창적인 세계관과 정통 Pathfinder/d20/D&D 3.5 시스템을 갖춘 MUD를 만드는 것입니다. 우리의 주요 목표는 협력적인 스토리텔링과 모험을 통해 의미 있는 연결을 구축하는 것입니다.

### 프로젝트 철학

이 프로젝트는 도전 과제에 대한 헌신, 자기 동기 부여 및 인내를 구현합니다. MUD를 만드는 것은 플레이어 수와 상관없이 그 자체로 보람 있는 일입니다. 우리는 초기 비전과 이 프로젝트를 성공시키기 위해 필요한 노력을 지속할 것입니다.

## 주요 기능

### 핵심 게임 시스템

* **정통 Pathfinder/D&D 3.5 메커닉**: 익숙한 규칙 시스템의 완전한 구현
* **고급 캐릭터 시스템**: 다양한 종족, 클래스, 피트(Feats) 및 스킬
* **역동적인 전투**: 전술적 배치가 포함된 우선권(Initiative) 기반 전투
* **주문 시스템**: 주문 준비 및 재료가 포함된 종합적인 마법 시스템
* **제작 및 연금술**: 광범위한 아이템 제작 및 강화 시스템

### 월드 및 콘텐츠

* **독창적인 월드 디자인**: 성경, 드래곤랜스, 포가튼 렐름에서 영감을 받은 고유 설정
* **퀘스트 중심 진행**: 스토리 지향적 발전 시스템
* **살아있는 세계**: 헤비 스크립팅을 통한 동적이고 반응적인 환경
* **지역 간 이동**: 탈것 지원이 포함된 월드맵 네비게이션
* **고품질 콘텐츠**: 기존 기본 콘텐츠를 대체하는 커스텀 존

### 기술적 특징

* **MySQL 통합**: 영구적인 플레이어 데이터 및 월드 상태 저장
* **DG 스크립팅 시스템**: NPC, 아이템, 방을 위한 강력한 스크립팅
* **Online Level Creation (OLC)**: 게임 내 월드 빌딩 도구
* **고급 네트워킹**: MSDP를 포함한 현대적인 MUD 프로토콜 지원
* **성능 모니터링**: C++ 최적화가 포함된 내장 프로파일링 및 디버깅 도구
* **보안 강화**: 모든 PHP 도구 보안 감사 및 조치 완료 (2025년 1월)
* **메모리 관리**: Valgrind 통합을 통한 고급 디버깅

## 빠른 시작

### 사전 요구 사항

* **운영 체제**: Linux 또는 Unix 계열 시스템 (WSL2 Ubuntu 포함)
* **컴파일러**: GCC 또는 Clang (GNU 확장이 포함된 C90/C89)
* **빌드 시스템**: CMake 3.12+ 또는 Autotools
* **데이터베이스**: MariaDB 10.0+ 또는 MySQL 5.7+ (필수 사항)
* **라이브러리**:
  - libmariadb-dev (MariaDB 클라이언트 라이브러리 - 필수)
  - libcrypt, libgd, libm, libcurl, libssl, libcrypto, libpthread

#### Ubuntu/WSL2 빠른 설치:

```bash
# 필요한 모든 의존성 설치 (MariaDB용 업데이트)
sudo apt-get update
sudo apt-get install -y build-essential libcrypt-dev libgd-dev libmariadb-dev \
                        libcurl4-openssl-dev libssl-dev mariadb-server git make cmake \
                        autoconf automake libtool pkg-config

# 권장 사항: 디버깅 도구 설치 (debug_game.sh 및 vgrind.sh에서 사용)
sudo apt-get install -y gdb valgrind

```

### 빌드 및 실행

```bash
# 저장소 클론
git clone https://github.com/LuminariMUD/Luminari-Source.git
cd Luminari-Source

# 필요한 헤더 설정 (최초 1회)
cp src/campaign.example.h src/campaign.h
cp src/mud_options.example.h src/mud_options.h
cp src/vnums.example.h src/vnums.h
# 필요에 따라 이 파일들을 편집하십시오.

# 옵션 1: CMake로 빌드 (권장)
cmake -S . -B build/
cmake --build build/ -j$(nproc)

# 옵션 2: 전통적인 Autotools 빌드
autoreconf -fvi  # configure 스크립트가 없을 경우에만 실행
./configure
make

# 서버 실행 (설정 완료 후)
bin/circle

# 또는 자동 재시작을 위해 autorun 스크립트 사용
./autorun

```

## 설치 방법

시스템 요구 사항, 의존성, 데이터베이스 설정 및 구성에 대한 자세한 설치 지침은 **[설치 및 빌드 가이드](https://www.google.com/search?q=docs/guides/SETUP_AND_BUILD_GUIDE.md)**를 참조하세요.

Windows 사용자 (WSL): 특정 WSL 배포판을 대상으로 하거나 자동 WSL 동작을 일시적으로 비활성화/재활성화하는 방법은 설치 가이드의 "Auto-WSL integration (Windows)" 섹션을 참조하세요.

## 사용법

### 기본 명령어

#### 빌드 및 개발

```bash
# 전체 빌드
make all

# 빌드 산출물 제거
make clean

# Autotools 파일 정리 (Makefile 및 config.h 유지)
make scrub

# 전체 정리 (모든 파일 제거, 다시 시작하려면 autoreconf 필요)
make distclean

# 유닛 테스트 실행
make cutest

# 의존성 생성
make depend

# 처음부터 다시 빌드
autoreconf -fiv && ./configure && make all

```

#### 서버 관리

```bash
# 서버 직접 실행
bin/circle

# 특정 포트로 실행
bin/circle -p 4000

# autorun 스크립트 실행 (프로덕션 환경 권장)
./autorun

# 백그라운드에서 실행
nohup bin/circle &

```

### 설정 파일

* **`campaign.h`**: 핵심 게임 설정 및 월드 구성
* **`mud_options.h`**: 서버 옵션 및 기능 토글
* **`vnums.h`**: 아이템, 방, NPC에 대한 가상 번호(Vnum) 할당

### 일반적인 사용 사례

#### 플레이어용

* 텔넷 접속: `telnet your-server-ip 4000`
* 향상된 경험을 위해 MUSHclient, TinTin++, Mudlet 등의 MUD 클라이언트 사용 권장

#### 빌더(제작자)용

* 게임 내 OLC(Online Level Creation) 명령어 사용
* `/docs/` 디렉토리의 빌딩 문서 참조
* 빌딩 표준 및 가이드라인 준수

#### 개발자용

* 모듈화된 C 파일 코드 검토
* 고급 기능을 위해 DG 스크립팅 시스템 사용
* GitHub 풀 리퀘스트를 통한 기여

## 문서

### 빠른 액세스

* **[🔧 기술 문서 마스터 인덱스](https://www.google.com/search?q=docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)**: 전체 기술 문서 개요
* **[시작하기](https://www.google.com/search?q=docs/GETTING_STARTED.md)**: 신규 사용자를 위한 빠른 시작 가이드

### 기술 문서

* **[아키텍처](https://www.google.com/search?q=docs/systems/CORE_SERVER_ARCHITECTURE.md)**: 서버 아키텍처 및 디자인 패턴
* **[개발자 가이드](https://www.google.com/search?q=docs/guides/DEVELOPER_GUIDE_AND_API.md)**: 코딩 표준 및 API 참조
* **[빌드 가이드](https://www.google.com/search?q=docs/development/CMAKE_BUILD_GUIDE.md)**: CMake 빌드 시스템 상세 정보

### 게임 문서

* **[전투 시스템](https://www.google.com/search?q=docs/systems/COMBAT_SYSTEM.md)**: 전투 메커니즘 및 계산
* **[플레이어 관리](https://www.google.com/search?q=docs/systems/PLAYER_MANAGEMENT_SYSTEM.md)**: 캐릭터 생성 및 성장
* **[함선 시스템](https://www.google.com/search?q=docs/systems/VESSEL_SYSTEM.md)**: 배, 비행정 및 항해

### 추가 리소스

* **[테스트 가이드](https://www.google.com/search?q=docs/guides/TESTING_GUIDE.md)**: 품질 보증 및 테스트 절차
* **[문제 해결](https://www.google.com/search?q=docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md)**: 일반적인 문제 및 해결책
* **[궁극의 라이팅 가이드](https://www.google.com/search?q=docs/guides/ultimate-mud-writing-guide.md)**: 구역(Zone) 구축 및 콘텐츠 제작
* **[AI 어시스턴트 가이드](CLAUDE.md)**: AI 지원 개발을 위한 종합 가이드

## 기여하기

개발자, 빌더, 커뮤니티 구성원 모두의 기여를 환영합니다! 기여하기 전에 가이드라인을 읽어주세요.

### 기여 방법

1. **저장소 포크(Fork)**
   `bash    # GitHub에서 포크한 후, 포크한 저장소를 클론합니다.    git clone https://github.com/YOUR_USERNAME/Luminari-Source.git    cd Luminari-Source    `
2. **기능 브랜치 생성**
   `bash    git checkout -b feature/your-feature-name    `
3. **변경 사항 적용**
   - 코딩 표준을 준수하세요 ([개발자 가이드](https://www.google.com/search?q=docs/guides/DEVELOPER_GUIDE_AND_API.md) 참조)
   - 새로운 기능에 대한 테스트를 추가하세요
   - 필요한 경우 문서를 업데이트하세요
4. **변경 사항 테스트**
   `bash    make clean    make all    make cutest  # 유닛 테스트 실행    `
5. **풀 리퀘스트(PR) 제출**
   - 브랜치를 포크한 저장소에 푸시합니다.
   - 명확한 설명과 함께 풀 리퀘스트를 생성합니다.
   - 관련 이슈가 있다면 참조를 포함하세요.

### 기여 가이드라인

#### 코드 기여

* **코딩 표준**: 기존 코드 스타일 및 규칙 준수
* **문서화**: 새로운 기능에 대한 관련 문서 업데이트
* **테스트**: 새로운 기능에 대한 유닛 테스트 포함
* **커밋 메시지**: 명확하고 설명적인 커밋 메시지 사용

#### 콘텐츠 기여

* **월드 빌딩**: 설정된 로어(Lore) 및 빌딩 표준 준수
* **도움말 파일**: 기존 도움말 시스템과의 일관성 유지
* **스크립트**: DG 스크립팅 모범 사례 사용

#### 버그 보고

* GitHub 이슈를 통해 버그 보고
* 재현 단계 포함
* 시스템 정보 및 에러 메시지 제공
* 중복된 이슈가 있는지 미리 확인

### 개발팀 구조

#### 핵심 개발

* **리드 프로그래머**: 코드 표준 및 개발 워크플로우 관리
* **게임 디자이너**: 게임 메커니즘 및 프로젝트 방향 정의
* **프로그래머**: 게임 메커니즘 및 기능 구현

#### 콘텐츠 제작

* **월드 디자이너**: 맵, 존, 빌딩 표준 설계
* **로어 디자이너**: 세계관 배경 및 스토리 개발
* **퀘스트 디자이너**: 퀘스트 콘텐츠 및 보상 제작
* **빌더**: 월드 콘텐츠, 스크립트, 퀘스트 제작
* **리드 스크립터**: 공용 스크립트 개발 및 지원

#### 커뮤니티 관리

* **총괄 관리자**: 스태프 및 커뮤니티 표준 관리
* **관리자**: 플레이어 관계 지원 및 가이드라인 집행
* **도움말 담당**: 도움말 시스템 및 문서 정리

### 기여 라이선스 동의

이 프로젝트에 대한 기여는 기여자 라이선스 동의(CLA)가 수반되어야 합니다. 기여물에 대한 저작권은 기여자가 보유하되, 프로젝트의 일부로 사용하고 재배포할 수 있는 권한을 프로젝트에 부여하게 됩니다.

## 커뮤니티

### 우리 커뮤니티에 참여하세요

* **Discord**: [커뮤니티 참여하기](https://discord.gg/Me3Tuu4) - 주요 소통 허브
* **GitHub Discussions**: 개발 관련 논의 시 사용
* **Issues**: 버그 보고 및 기능 요청

### 커뮤니티 가이드라인

* **존중**: 모든 커뮤니티 구성원을 존중과 친절로 대하세요.
* **협력**: 공통의 목표를 향해 함께 일하세요.
* **건설적 피드백**: 도움이 되고 실행 가능한 피드백을 제공하세요.
* **포용성**: 신입 회원을 환영하고 정착을 도와주세요.

### 도움 받기

* **Discord**: 적절한 채널에서 질문하세요.
* **문서**: 먼저 종합 문서를 확인하세요.
* **GitHub Issues**: 버그 보고 및 기능 요청용
* **게임 내 도움말**: 내장된 도움말(help) 시스템 사용

## 문제 해결

### 일반적인 이슈

#### 빌드 문제

```bash
# 누락된 의존성
sudo apt-get install build-essential mariadb-server libmariadb-dev libgd-dev

# 권한 문제
chmod +x configure
chmod +x licheck

# 클린 빌드
make clean && make

```

#### 런타임 이슈

```bash
# 데이터베이스 연결 문제
# MariaDB 서비스 상태 확인
sudo systemctl status mariadb
# 또는 구형 시스템의 경우:
sudo systemctl status mysql

# 포트가 이미 사용 중인 경우
# 4000번 포트를 사용하는 프로세스 확인
netstat -tulpn | grep :4000

```

#### 설정 문제

* 모든 `.h` 설정 파일이 올바르게 구성되었는지 확인
* 설정 파일의 파일 권한 확인
* 데이터베이스 자격 증명이 정확한지 확인

### 기술 지원 받기

1. [문제 해결 가이드](https://www.google.com/search?q=docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md) 확인
2. 기존 GitHub Issues 검색
3. 커뮤니티 지원을 위해 Discord에서 질문
4. 버그나 기능 요청을 위해 GitHub 이슈 생성

## 라이선스

이 프로젝트는 이중 라이선스 방식을 채택하고 있습니다:

### tbaMUD/CircleMUD 코드

tbaMUD 프로젝트에서 기여한 코드는 해당 라이선스 약관을 따릅니다. 상세 내용은 [tbamud.com](https://tbamud.com)을 참조하세요.

### LuminariMUD 커스텀 코드

LuminariMUD를 위해 개발된 커스텀 코드는 **퍼블릭 도메인(Public Domain)**으로 배포됩니다:

> 이 소프트웨어는 어떠한 제한 없이 퍼블릭 도메인으로 배포됩니다.
> 누구나 상업적 또는 비상업적 목적으로, 어떤 수단으로든 이 소프트웨어를 소스 코드 형태나 컴파일된 바이너리 형태로 복사, 수정, 게시, 사용, 컴파일, 판매 또는 배포할 수 있는 자유가 있습니다.

전체 라이선스 세부 사항은 [LICENSE](https://www.google.com/search?q=LICENSE) 파일을 참조하세요.

## 감사의 말

### 기반이 된 프로젝트

* **[tbaMUD](https://tbamud.com)**: 베이스 MUD 코드베이스
* **[CircleMUD](http://www.circlemud.org)**: 오리지널 기반
* **CWG (Copper) MUD**: 추가 개선 및 기능

### 영감을 준 작품들

* **성경 이야기**: 영적 및 도덕적 주제
* **드래곤랜스**: 서사적 판타지 요소
* **포가튼 렐름**: 풍부한 월드 빌딩 전통

### 버전 정보

* **현재 버전**: LuminariMUD 2.5001-beta (tbaMUD 3.64)
* **저장소**: [https://github.com/LuminariMUD/Luminari-Source](https://github.com/LuminariMUD/Luminari-Source)
* **생성일**: 2019년 7월 16일
* **언어**: C (ANSI C90/C89 표준) 및 C++11 성능 모니터링
* **최종 업데이트**: 2026년 1월

> 버전 정의 위치: `src/constants.c` (정식), `src/structs.h`, `configure.ac`, `CMakeLists.txt`

---

**기억하세요**: *작업 그 자체가 보상입니다. 커뮤니티를 위해 의미 있는 것을 만드는 데 집중하십시오.*

더 자세한 정보는 [기술 문서](https://www.google.com/search?q=docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)를 방문하거나 [Discord 커뮤니티](https://discord.gg/Me3Tuu4)에 가입하세요.

