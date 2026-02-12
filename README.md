# LuminariMUD

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-lightgrey.svg)](https://github.com/LuminariMUD/Luminari-Source)

Pathfinder/D&D 3.5 메커니즘을 구현한 텍스트 기반 멀티플레이어 온라인 롤플레잉 게임(MUD) 서버로, 강력한 tbaMUD/CircleMUD 기반 위에 광범위한 커스텀 확장이 이루어졌습니다.

## 목차

- [빠른 시작](#빠른-시작) - [docs/GETTING_STARTED.md](docs/GETTING_STARTED.md)도 참고하세요.
- [개요](#개요)
- [특징](#특징)
- [설치](#설치)
- [사용법](#사용법)
- [문서](#문서)
- [기여하기](#기여하기)
- [커뮤니티](#커뮤니티)
- [라이선스](#라이선스)
- [감사 인사](#감사-인사)

## 빠른 시작

다음의 간단한 단계를 통해 LuminariMUD를 빠르게 실행해 보세요:

### 필수 요구 사항

먼저 필요한 라이브러리들을 설치합니다:

```bash
# Ubuntu/Debian/WSL2
sudo apt-get update
sudo apt-get install -y build-essential git make autoconf automake \
                        libcrypt-dev libgd-dev libmariadb-dev \
                        libcurl4-openssl-dev libssl-dev mariadb-server \
                        cmake libtool pkg-config gdb valgrind
```

### 설치

```bash
# 1. 저장소 클론
git clone [https://github.com/LuminariMUD/Luminari-Source.git](https://github.com/LuminariMUD/Luminari-Source.git)
cd Luminari-Source

# 2. 배포 스크립트 실행
#    의존성, 데이터베이스, 월드 데이터, 빌드 등 모든 것을 처리합니다.
#    실행 중 MySQL root 비밀번호 입력을 요청받을 수 있습니다.
./scripts/deploy.sh

# 3. MUD 서버 시작
./bin/circle -d lib
```

이제 끝났습니다! 아무 MUD 클라이언트를 사용하여 `localhost:4000`으로 접속하세요.

### `deploy.sh`가 하는 일

배포 스크립트는 자동으로 다음 작업을 수행합니다:
- 설정 파일 복사 (.example.h → .h)
- 누락된 의존성 설치
- MariaDB 데이터베이스 설정 (root 비밀번호 요청)
- 생성된 비밀번호로 데이터베이스 및 사용자 생성
- 월드 데이터 초기화 (구역, 방, 몹, 아이템)
- autotools(권장) 또는 CMake를 사용하여 MUD 빌드
- 필요한 모든 디렉토리 및 심볼릭 링크 생성

**선택적 플래그:**
- `--auto` - 가능한 경우 확인 절차 생략 (여전히 MySQL root 비밀번호는 필요함)
- `--skip-db` - 데이터베이스 설정 건너뛰기 (권장하지 않음)
- `--dev` - 디버그 심볼이 포함된 개발용 빌드
- `--prod` - 프로덕션 최적화 빌드

자세한 정보는 [docs/deployment/DEPLOYMENT_GUIDE.md](docs/deployment/DEPLOYMENT_GUIDE.md)를 참조하세요.

## 개요

LuminariMUD는 텍스트 기반 멀티플레이어 환경에서 사랑받는 Pathfinder/D&D 3.5 규칙 시스템을 구현한 기능 풍부한 MUD 서버입니다. 검증된 tbaMUD/CircleMUD 코드베이스를 바탕으로 구축되었으며, 성경, 드래곤랜스(Dragonlance), 포가튼 렐름(Forgotten Realms) 이야기에서 영감을 받은 독창적인 세계를 특징으로 합니다.

### 프로젝트 비전

Pathfinder/d20/D&D 3.5 메커니즘을 충실히 구현한 MUD를 만들고, 뜻이 맞는 게이머들이 안전하고 친근한 커뮤니티를 형성할 수 있는 독창적인 세계를 제공하는 것입니다. 우리의 주요 목표는 협력적인 스토리텔링과 모험을 통해 의미 있는 연결을 구축하는 것입니다.

### 프로젝트 철학

이 프로젝트는 헌신, 자기 주도적 동기 부여, 그리고 도전을 극복하는 인내를 상징합니다. MUD를 만드는 것은 플레이어 수와 상관없이 그 자체로 보람 있는 일입니다. 우리는 초기 비전과 프로젝트를 성공시키기 위해 필요한 노력을 지속해 나갈 것입니다.

## 특징

### 핵심 게임 시스템
- **정통 Pathfinder/D&D 3.5 메커니즘**: 익숙한 규칙 시스템의 완벽한 구현
- **고급 캐릭터 시스템**: 다양한 종족, 클래스, 피트(feats), 스킬 제공
- **역동적인 전투**: 전술적 배치가 포함된 우선권(Initiative) 기반 전투
- **주문 시스템**: 주문 준비와 재료가 포함된 포괄적인 마법 시스템
- **제작 및 연금술**: 광범위한 아이템 제작 및 강화 시스템

### 월드 및 콘텐츠
- **독창적인 월드 디자인**: 성경, 드래곤랜스, 포가튼 렐름에서 영감을 받은 고유한 설정
- **퀘스트 중심의 성장**: 스토리 중심의 발전 시스템
- **살아있는 세계**: 역동적이고 반응적인 환경을 위한 강력한 스크립팅 적용
- **구역 간 이동**: 탈것을 지원하는 월드 맵 내비게이션
- **고품질 콘텐츠**: 기본(Stock) 콘텐츠를 대체하는 커스텀 구역들

### 기술적 특징
- **MySQL 통합**: 영구적인 플레이어 데이터 및 월드 상태 저장
- **DG 스크립팅 시스템**: NPC, 아이템, 방을 위한 강력한 스크립팅
- **온라인 레벨 제작 (OLC)**: 게임 내 월드 빌딩 도구
- **고급 네트워킹**: MSDP를 포함한 현대적인 MUD 프로토콜 지원
- **성능 모니터링**: C++ 최적화를 통한 내장 프로파일링 및 디버깅 도구
- **보안 강화**: 모든 PHP 도구에 대한 감사 및 보안 조치 완료 (2025년 1월)
- **메모리 관리**: Valgrind 통합을 통한 고급 디버깅

## 빠른 시작

### 필수 요구 사항
- **운영 체제**: Linux 또는 Unix 계열 시스템 (WSL2 Ubuntu 포함)
- **컴파일러**: GCC 또는 Clang (GNU 확장이 포함된 C90/C89)
- **빌드 시스템**: CMake 3.12+ 또는 Autotools
- **데이터베이스**: MariaDB 10.0+ 또는 MySQL 5.7+ (필수 - 선택 사항 아님)
- **라이브러리**:
  - libmariadb-dev (MariaDB 클라이언트 라이브러리 - 필수)
  - libcrypt, libgd, libm, libcurl, libssl, libcrypto, libpthread

#### Ubuntu/WSL2 빠른 설치:
```bash
# 필요한 모든 의존성 설치 (MariaDB용 업데이트 완료)
sudo apt-get update
sudo apt-get install -y build-essential libcrypt-dev libgd-dev libmariadb-dev \
                        libcurl4-openssl-dev libssl-dev mariadb-server git make cmake \
                        autoconf automake libtool pkg-config

# 강력 권장: 디버깅 도구 설치 (debug_game.sh 및 vgrind.sh에서 사용)
sudo apt-get install -y gdb valgrind
```

### 빌드 및 실행
```bash
# 저장소 클론
git clone [https://github.com/LuminariMUD/Luminari-Source.git](https://github.com/LuminariMUD/Luminari-Source.git)
cd Luminari-Source

# 필수 헤더 설정 (최초 1회)
cp src/campaign.example.h src/campaign.h
cp src/mud_options.example.h src/mud_options.h
cp src/vnums.example.h src/vnums.h
# 설정에 맞게 이 파일들을 편집하세요.

# 옵션 1: CMake로 빌드 (권장)
cmake -S . -B build/
cmake --build build/ -j$(nproc)

# 옵션 2: Autotools를 이용한 전통적인 빌드
autoreconf -fvi  # configure 스크립트가 없을 경우에만 실행
./configure
make

# 서버 실행 (설정 완료 후)
bin/circle

# 또는 자동 재시작을 위해 autorun 스크립트 사용
./autorun
```

## 설치

시스템 요구 사항, 의존성, 데이터베이스 설정 및 구성을 포함한 자세한 설치 지침은 **[설정 및 빌드 가이드](docs/guides/SETUP_AND_BUILD_GUIDE.md)**를 참조하세요.

Windows 사용자 (WSL): 특정 WSL 배포판을 대상으로 하거나 자동 WSL 동작을 일시적으로 비활성화/재활성화하는 방법은 설정 및 빌드 가이드의 "Auto-WSL integration (Windows)" 섹션을 참조하세요.


## 사용법

### 기본 명령

#### 빌드 및 개발
```bash
# 전체 빌드
make all

# 빌드 결과물 정리
make clean

# autotools 파일 정리 (Makefile 및 config.h 유지)
make scrub

# 완전 정리 (모든 것 삭제, autoreconf 필요)
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
# 서버 직접 시작
bin/circle

# 특정 포트로 시작
bin/circle -p 4000

# autorun 스크립트로 실행 (프로덕션 환경 권장)
./autorun

# 백그라운드에서 실행
nohup bin/circle &
```

### 설정 파일

- **`campaign.h`**: 핵심 게임 설정 및 월드 구성
- **`mud_options.h`**: 서버 옵션 및 기능 토글
- **`vnums.h`**: 아이템, 방, NPC에 대한 가상 번호(VNUM) 할당

### 일반적인 사용 사례

#### 플레이어용
- 텔넷 접속: `telnet your-server-ip 4000`
- 향상된 경험을 위해 MUSHclient, TinTin++, Mudlet과 같은 MUD 클라이언트 사용 권장

#### 빌더(콘텐츠 제작자)용
- 게임 내 OLC (Online Level Creation) 명령 사용
- `/docs/` 내의 빌딩 문서 확인
- 빌딩 표준 및 가이드라인 준수

#### 개발자용
- 모듈화된 C 파일의 코드 검토
- 고급 기능을 위해 DG 스크립팅 시스템 활용
- GitHub 풀 리퀘스트(PR)를 통해 기여

## 문서

### 빠른 접근
- **[🔧 기술 문서 마스터 인덱스](docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)**: 전체 기술 문서 개요
- **[시작하기](docs/GETTING_STARTED.md)**: 신규 사용자를 위한 빠른 시작 가이드

### 기술 문서
- **[아키텍처](docs/systems/CORE_SERVER_ARCHITECTURE.md)**: 서버 아키텍처 및 디자인 패턴
- **[개발자 가이드](docs/guides/DEVELOPER_GUIDE_AND_API.md)**: 코딩 표준 및 API 참조
- **[빌드 가이드](docs/development/CMAKE_BUILD_GUIDE.md)**: CMake 빌드 시스템 세부 정보

### 게임 문서
- **[전투 시스템](docs/systems/COMBAT_SYSTEM.md)**: 전투 메커니즘 및 계산
- **[플레이어 관리](docs/systems/PLAYER_MANAGEMENT_SYSTEM.md)**: 캐릭터 생성 및 성장
- **[함선 시스템](docs/systems/VESSEL_SYSTEM.md)**: 배, 비공정 및 항해

### 추가 리소스
- **[테스트 가이드](docs/guides/TESTING_GUIDE.md)**: 품질 보증 및 테스트 절차
- **[문제 해결](docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md)**: 일반적인 문제 및 해결책
- **[궁극의 작법 가이드](docs/guides/ultimate-mud-writing-guide.md)**: 구역 구축 및 콘텐츠 제작
- **[AI 어시스턴트 가이드](CLAUDE.md)**: AI 지원 개발을 위한 포괄적 가이드

## 기여하기

개발자, 빌더, 커뮤니티 멤버의 기여를 환영합니다! 기여하기 전에 가이드라인을 읽어주세요.

### 기여 방법

1. **저장소 포크(Fork)**
   ```bash
   # GitHub에서 포크한 후, 포크한 저장소를 클론합니다.
   git clone [https://github.com/YOUR_USERNAME/Luminari-Source.git](https://github.com/YOUR_USERNAME/Luminari-Source.git)
   cd Luminari-Source
   ```

2. **기능 브랜치 생성**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **변경 사항 적용**
   - 코딩 표준을 준수하세요 ([개발자 가이드](docs/guides/DEVELOPER_GUIDE_AND_API.md) 참조)
   - 새로운 기능에 대한 테스트를 추가하세요
   - 필요에 따라 문서를 업데이트하세요

4. **변경 사항 테스트**
   ```bash
   make clean
   make all
   make cutest  # 유닛 테스트 실행
   ```

5. **풀 리퀘스트 제출**
   - 브랜치를 자신의 포크 저장소로 푸시합니다.
   - 명확한 설명과 함께 풀 리퀘스트를 생성합니다.
   - 관련 이슈가 있다면 참조를 포함합니다.

### 기여 가이드라인

#### 코드 기여
- **코딩 표준**: 기존 코드 스타일과 컨벤션을 따릅니다.
- **문서화**: 새로운 기능에 대해 관련 문서를 업데이트합니다.
- **테스트**: 새로운 기능에 대한 유닛 테스트를 포함합니다.
- **커밋 메시지**: 명확하고 설명적인 커밋 메시지를 사용합니다.

#### 콘텐츠 기여
- **월드 빌딩**: 확립된 로어(Lore)와 빌딩 표준을 따릅니다.
- **도움말 파일**: 기존 도움말 시스템과의 일관성을 유지합니다.
- **스크립트**: DG 스크립팅 모범 사례를 따릅니다.

#### 버그 보고
- 버그 보고는 GitHub Issues를 사용하세요.
- 재현 단계를 포함하세요.
- 시스템 정보와 에러 메시지를 제공하세요.
- 새로운 이슈를 만들기 전에 기존 이슈를 확인하세요.

### 개발 팀 구조

#### 핵심 개발 (Core Development)
- **리드 프로그래머**: 코드 표준 및 개발 워크플로우 관리
- **게임 디자이너**: 게임 메커니즘 및 프로젝트 방향 정의
- **프로그래머**: 게임 메커니즘 및 기능 구현

#### 콘텐츠 제작 (Content Creation)
- **월드 디자이너**: 맵, 구역 및 빌딩 표준 설계
- **로어 디자이너**: 월드 배경 및 이야기 개발
- **퀘스트 디자이너**: 퀘스트 콘텐츠 및 보상 제작
- **빌더**: 월드 콘텐츠, 스크립트 및 퀘스트 제작
- **리드 스크립터**: 범용 스크립트 개발 및 지원 제공

#### 커뮤니티 관리 (Community Management)
- **리드 관리자**: 스태프 및 커뮤니티 표준 관리
- **관리자**: 플레이어 관계 지원 및 가이드라인 집행
- **도움말 파일 리드**: 도움말 시스템 및 문서 정리

### 기여자 라이선스 동의서

이 프로젝트에 대한 기여는 기여자 라이선스 동의서와 함께 이루어져야 합니다. 기여물에 대한 저작권은 귀하가 보유하며, 이는 프로젝트의 일부로서 귀하의 기여물을 사용하고 재배포할 수 있는 권한을 우리에게 부여하는 것입니다.

## 커뮤니티

### 커뮤니티 참여하기
- **Discord**: [커뮤니티 참여](https://discord.gg/Me3Tuu4) - 주요 소통 허브
- **GitHub Discussions**: 개발 관련 토론에 사용
- **Issues**: 버그 보고 및 기능 요청

### 커뮤니티 가이드라인
- **존중**: 모든 커뮤니티 멤버를 존중과 친절로 대하십시오.
- **협업**: 공통의 목표를 향해 함께 노력하십시오.
- **건설적 피드백**: 도움이 되고 실행 가능한 피드백을 제공하십시오.
- **포용성**: 신규 사용자를 환영하고 그들이 시작할 수 있도록 돕습니다.

### 도움받기
- **Discord**: 적절한 채널에서 질문하십시오.
- **문서**: 먼저 포괄적인 문서들을 확인하십시오.
- **GitHub Issues**: 버그 보고 및 기능 요청용
- **게임 내 도움말**: 내장된 도움말 시스템을 사용하십시오.

## 문제 해결

### 일반적인 문제

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

#### 실행 시간(Runtime) 문제
```bash
# 데이터베이스 연결 문제
# MariaDB 서비스 상태 확인
sudo systemctl status mariadb
# 또는 구형 시스템의 경우:
sudo systemctl status mysql

# 포트가 이미 사용 중임
# 4000번 포트를 사용 중인 프로세스 확인
netstat -tulpn | grep :4000
```

#### 설정 문제
- 모든 `.h` 설정 파일이 올바르게 설정되었는지 확인하십시오.
- 설정 파일의 파일 권한을 확인하십시오.
- 데이터베이스 인증 정보가 정확한지 확인하십시오.

### 지원 받기
1. [문제 해결 가이드](docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md) 확인
2. 기존 GitHub Issues 검색
3. 커뮤니티 지원을 위해 Discord에서 질문
4. 버그나 기능 요청을 위해 GitHub Issue 생성

## 라이선스

이 프로젝트는 이중 라이선스 방식을 채택하고 있습니다:

### tbaMUD/CircleMUD 코드
tbaMUD 프로젝트에서 기여한 코드는 해당 라이선스 약관을 따릅니다. 자세한 내용은 [tbamud.com](https://tbamud.com)을 참조하세요.

### LuminariMUD 커스텀 코드
LuminariMUD를 위해 개발된 커스텀 코드는 **퍼블릭 도메인(Public Domain)**으로 공개됩니다:

> 이것은 퍼블릭 도메인으로 출시된 자유롭고 제약 없는 소프트웨어입니다.
>
> 누구든지 상업적 또는 비상업적 목적으로, 소스 코드 형태나 컴파일된 바이너리 형태로 이 소프트웨어를 복제, 수정, 게시, 사용, 컴파일, 판매 또는 배포할 수 있습니다.

전체 라이선스 세부 정보는 [LICENSE](LICENSE) 파일을 참조하세요.

## 감사 인사

### 기반 프로젝트
- **[tbaMUD](https://tbamud.com)**: 기본 MUD 코드베이스
- **[CircleMUD](http://www.circlemud.org)**: 독창적인 토대
- **CWG (Copper) MUD**: 추가적인 개선 및 기능들

### 영감
- **성경 이야기**: 영적이고 도덕적인 테마
- **드래곤랜스(Dragonlance)**: 서사적인 판타지 요소
- **포가튼 렐름(Forgotten Realms)**: 풍부한 월드 빌딩 전통

### 버전 정보
- **현재 버전**: LuminariMUD 2.5001-beta (tbaMUD 3.64)
- **저장소**: https://github.com/LuminariMUD/Luminari-Source
- **생성일**: 2019년 7월 16일
- **언어**: C (ANSI C90/C89 표준) 및 C++11 성능 모니터링
- **최종 업데이트**: 2026년 1월

> 버전 정의 위치: `src/constants.c` (정식), `src/structs.h`, `configure.ac`, `CMakeLists.txt`

**기억하세요**: *작업 그 자체가 보상입니다. 커뮤니티를 위해 의미 있는 것을 만드는 데 집중하십시오.*

더 많은 정보를 원하시면 [기술 문서](docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)를 방문하거나 [Discord 커뮤니티](https://discord.gg/Me3Tuu4)에 참여하세요.

```
