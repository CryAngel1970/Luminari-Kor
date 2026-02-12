# LuminariMUD
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-lightgrey.svg)](https://github.com/LuminariMUD/Luminari-Source)
텍스트 기반 다중 사용자 온라인 롤플레잉 게임 (MUD) 서버로, Pathfinder/D&D 3.5 메카니즘을 구현하며, 견고한 tbaMUD/CircleMUD 기반에 광범위한 사용자 정의 향상 기능을 추가하여 구축되었습니다.
## 목차
- [빠른 시작](#quick-start) - [docs/GETTING_STARTED.md](docs/GETTING_STARTED.md)도 참조하세요
- [개요](#overview)
- [기능](#features)
- [설치](#installation)
- [사용법](#usage)
- [문서](#documentation)
- [기여](#contributing)
- [커뮤니티](#community)
- [라이선스](#license)
- [감사 인사](#acknowledgments)
## 빠른 시작
다음 간단한 단계로 LuminariMUD를 빠르게 실행하세요:
### 필수 조건
필수 라이브러리를 먼저 설치하세요:
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
# 1. 저장소 복제
git clone https://github.com/LuminariMUD/Luminari-Source.git
cd Luminari-Source
# 2. 배포 스크립트 실행
# 이는 모든 것을 처리합니다: 종속성, 데이터베이스, 세계 데이터, 빌드
# MySQL 루트 비밀번호를 입력하라는 메시지가 표시됩니다
./scripts/deploy.sh
# 3. MUD 서버 시작
./bin/circle -d lib
```
이제 끝났습니다! MUD 클라이언트로 `localhost:4000`에 연결하세요.
### `deploy.sh`가 하는 일
배포 스크립트는 자동으로 다음을 수행합니다:
- 구성 파일 복사 (.example.h → .h)
- 누락된 종속성 설치
- MariaDB 데이터베이스 설정 (루트 비밀번호 입력 요청)
- 생성된 비밀번호로 데이터베이스 및 사용자 생성
- 세계 데이터 초기화 (구역, 방, 몹, 객체)
- autotools (권장) 또는 CMake를 사용하여 MUD 빌드
- 모든 필요한 디렉토리 및 심볼릭 링크 생성
**선택적 플래그:**
- `--auto` - 가능한 한 프롬프트를 건너뜀 (여전히 MySQL 루트 비밀번호 필요)
- `--skip-db` - 데이터베이스 설정 건너뜀 (권장하지 않음)
- `--dev` - 디버그 심볼이 포함된 개발 빌드
- `--prod` - 프로덕션 최적화 빌드
자세한 정보는 [docs/deployment/DEPLOYMENT_GUIDE.md](docs/deployment/DEPLOYMENT_GUIDE.md)를 참조하세요.
## 개요
LuminariMUD는 텍스트 기반 다중 사용자 환경에서 사랑받는 Pathfinder/D&D 3.5 규칙 시스템을 생생하게 구현하는 기능이 풍부한 MUD 서버입니다. 검증된 tbaMUD/CircleMUD 코드베이스 위에 구축되었으며, 성경, Dragonlance, Forgotten Realms 이야기에서 영감을 받은 독창적인 세계를 특징으로 합니다.
### 프로젝트 비전
동일한 생각을 가진 게이머들을 위한 안전하고 친근한 커뮤니티를 육성하는 독창적인 세계를 특징으로 하는 정통 Pathfinder/d20/D&D 3.5 메카니즘을 가진 MUD를 생성합니다. 우리의 주요 목표는 협력적인 스토리텔링과 모험을 통해 의미 있는 연결을 구축하는 것입니다.
### 프로젝트 철학
이 프로젝트는 도전을 통한 헌신, 자기 동기 부여, 인내를 구현합니다. MUD 생성은 플레이어 기반 규모와 상관없이 본질적으로 보람 있는 작업입니다. 우리는 초기 비전과 이 프로젝트를 성공적으로 만들기 위해 필요한 노고에 전념합니다.
## 기능
### 핵심 게임 시스템
- **정통 Pathfinder/D&D 3.5 메카니즘**: 친숙한 규칙 시스템의 완전한 구현
- **고급 캐릭터 시스템**: 여러 종족, 클래스, 피트, 스킬
- **동적 전투**: 전술적 위치 지정이 포함된 이니셔티브 기반 전투
- **주문 시스템**: 주문 준비 및 구성 요소가 포함된 포괄적인 마법 시스템
- **제작 및 연금술**: 광범위한 아이템 생성 및 향상 시스템
### 세계 및 콘텐츠
- **독창적인 세계 디자인**: 성경, Dragonlance, Forgotten Realms에서 영감을 받은 독특한 설정
- **퀘스트 중심 진행**: 스토리 지향적인 발전 시스템
- **살아 있는 세계**: 동적이고 반응형 환경을 위한 중점 스크립팅
- **구역 간 이동**: 차량 지원이 포함된 세계 지도 탐색
- **고품질 콘텐츠**: 스톡 콘텐츠를 대체하는 사용자 정의 구역
### 기술 기능
- **MySQL 통합**: 영구 플레이어 데이터 및 세계 상태
- **DG 스크립팅 시스템**: NPC, 객체, 방을 위한 강력한 스크립팅
- **온라인 레벨 생성 (OLC)**: 게임 내 세계 빌딩 도구
- **고급 네트워킹**: MSDP를 포함한 현대 MUD 프로토콜 지원
- **성능 모니터링**: C++ 최적화가 포함된 내장 프로파일링 및 디버깅 도구
- **보안 강화**: 모든 PHP 도구 감사 및 보안 (2025년 1월)
- **메모리 관리**: Valgrind 통합이 포함된 고급 디버깅
## 빠른 시작
### 필수 조건
- **운영 체제**: Linux 또는 Unix-like 시스템 (WSL2 Ubuntu 포함)
- **컴파일러**: GCC 또는 Clang (C90/C89 with GNU extensions)
- **빌드 시스템**: CMake 3.12+ 또는 Autotools
- **데이터베이스**: MariaDB 10.0+ 또는 MySQL 5.7+ (필수 - 선택 사항 아님)
- **라이브러리**:
  - libmariadb-dev (MariaDB 클라이언트 라이브러리 - 필수)
  - libcrypt, libgd, libm, libcurl, libssl, libcrypto, libpthread
#### Ubuntu/WSL2용 빠른 설치:
```bash
# 모든 필수 종속성 설치 (MariaDB용 업데이트됨)
sudo apt-get update
sudo apt-get install -y build-essential libcrypt-dev libgd-dev libmariadb-dev \
                        libcurl4-openssl-dev libssl-dev mariadb-server git make cmake \
                        autoconf automake libtool pkg-config
# 강력 추천: 디버깅 도구 설치 (debug_game.sh 및 vgrind.sh에서 사용)
sudo apt-get install -y gdb valgrind
```
### 빌드 및 실행
```bash
# 저장소 복제
git clone https://github.com/LuminariMUD/Luminari-Source.git
cd Luminari-Source
# 필수 헤더 구성 (한 번 설정)
cp src/campaign.example.h src/campaign.h
cp src/mud_options.example.h src/mud_options.h
cp src/vnums.example.h src/vnums.h
# 구성에 따라 이 파일들을 편집하세요
# 옵션 1: CMake로 빌드 (권장)
cmake -S . -B build/
cmake --build build/ -j$(nproc)
# 옵션 2: Autotools로 전통적인 빌드
autoreconf -fvi # configure 스크립트가 누락된 경우에만
./configure
make
# 서버 실행 (구성 후)
bin/circle
# 자동 재시작을 위한 autorun 스크립트 사용
./autorun
```
## 설치
시스템 요구 사항, 종속성, 데이터베이스 설정 및 구성을 포함한 자세한 설치 지침은 **[설치 및 빌드 가이드](docs/guides/SETUP_AND_BUILD_GUIDE.md)**를 참조하세요.
Windows 사용자 (WSL): 특정 WSL 배포를 대상으로 하거나 Auto-WSL 동작을 일시적으로 비활성화/재활성화하려면 설치 및 빌드 가이드의 "Auto-WSL 통합 (Windows)" 섹션을 참조하세요.
## 사용법
### 기본 명령어
#### 빌드 및 개발
```bash
# 모든 것 빌드
make all
# 빌드 아티팩트 정리
make clean
# autotools 파일 정리 (Makefile 및 config.h 유지)
make scrub
# 전체 정리 (모든 것 제거, autoreconf 필요)
make distclean
# 단위 테스트 실행
make cutest
# 종속성 생성
make depend
# 처음부터 재빌드
autoreconf -fiv && ./configure && make all
```
#### 서버 관리
```bash
# 서버 직접 시작
bin/circle
# 특정 포트로 시작
bin/circle -p 4000
# 프로덕션용 autorun 스크립트 사용 (권장)
./autorun
# 백그라운드 실행
nohup bin/circle &
```
### 구성 파일
- **`campaign.h`**: 핵심 게임 설정 및 세계 구성
- **`mud_options.h`**: 서버 옵션 및 기능 토글
- **`vnums.h`**: 객체, 방, NPC를 위한 가상 번호 할당
### 일반적인 사용 사례
#### 플레이어용
- telnet으로 연결: `telnet your-server-ip 4000`
- 향상된 경험을 위해 MUSHclient, TinTin++, 또는 Mudlet 같은 MUD 클라이언트 사용
#### 빌더용
- 게임 내 OLC (온라인 레벨 생성) 명령어 사용
- `/docs/`에서 빌딩 문서 접근
- 빌딩 표준 및 지침 준수
#### 개발자용
- 모듈식 C 파일에서 코드 검토
- 고급 기능을 위한 DG 스크립팅 시스템 사용
- GitHub 풀 리퀘스트를 통해 기여
## 문서
### 빠른 접근
- **[🔧 기술 마스터 인덱스](docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)**: 완전한 기술 문서 개요
- **[시작하기](docs/GETTING_STARTED.md)**: 신규 사용자용 빠른 시작 가이드
### 기술 문서
- **[아키텍처](docs/systems/CORE_SERVER_ARCHITECTURE.md)**: 서버 아키텍처 및 디자인 패턴
- **[개발자 가이드](docs/guides/DEVELOPER_GUIDE_AND_API.md)**: 코딩 표준 및 API 참조
- **[빌드 가이드](docs/development/CMAKE_BUILD_GUIDE.md)**: CMake 빌드 시스템 세부 사항
### 게임 문서
- **[전투 시스템](docs/systems/COMBAT_SYSTEM.md)**: 전투 메카니즘 및 계산
- **[플레이어 관리](docs/systems/PLAYER_MANAGEMENT_SYSTEM.md)**: 캐릭터 생성 및 진행
- **[선박 시스템](docs/systems/VESSEL_SYSTEM.md)**: 배, 비행선, 및 항해
### 추가 자원
- **[테스트 가이드](docs/guides/TESTING_GUIDE.md)**: 품질 보증 및 테스트 절차
- **[문제 해결](docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md)**: 일반적인 문제 및 해결책
- **[궁극적인 쓰기 가이드](docs/guides/ultimate-mud-writing-guide.md)**: 구역 빌딩 및 콘텐츠 생성
- **[AI 어시스턴트 가이드](CLAUDE.md)**: AI 지원 개발을 위한 포괄적인 가이드
## 기여
개발자, 빌더, 커뮤니티 멤버의 기여를 환영합니다! 기여 전에 지침을 읽어주세요.
### 기여 방법
1. **저장소 포크**
   ```bash
   # GitHub에서 포크한 후, 포크 복제
   git clone https://github.com/YOUR_USERNAME/Luminari-Source.git
   cd Luminari-Source
   ```
2. **기능 브랜치 생성**
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **변경 사항 적용**
   - 우리의 코딩 표준 준수 ( [개발자 가이드](docs/guides/DEVELOPER_GUIDE_AND_API.md) 참조)
   - 새로운 기능에 대한 테스트 추가
   - 필요 시 문서 업데이트
4. **변경 사항 테스트**
   ```bash
   make clean
   make all
   make cutest # 단위 테스트 실행
   ```
5. **풀 리퀘스트 제출**
   - 브랜치를 포크로 푸시
   - 명확한 설명으로 풀 리퀘스트 생성
   - 관련 이슈 참조
### 기여 지침
#### 코드 기여
- **코딩 표준**: 기존 코드 스타일 및 규칙 준수
- **문서**: 새로운 기능에 대한 관련 문서 업데이트
- **테스트**: 새로운 기능에 대한 단위 테스트 포함
- **커밋 메시지**: 명확하고 설명적인 커밋 메시지 사용
#### 콘텐츠 기여
- **세계 빌딩**: 확립된 로어 및 빌딩 표준 준수
- **도움말 파일**: 기존 도움말 시스템과 일관성 유지
- **스크립트**: DG 스크립팅 모범 사례 사용
#### 버그 보고
- GitHub Issues를 사용하여 버그 보고
- 문제 재현 단계 포함
- 시스템 정보 및 오류 메시지 제공
- 새로운 이슈 생성 전에 기존 이슈 확인
### 개발 팀 구조
#### 핵심 개발
- **리드 프로그래머**: 코드 표준 및 개발 워크플로 관리
- **게임 디자이너**: 게임 메카니즘 및 프로젝트 방향 정의
- **프로그래머**: 게임 메카니즘 및 기능 구현
#### 콘텐츠 생성
- **세계 디자이너**: 지도, 구역, 빌딩 표준 디자인
- **로어 디자이너**: 세계 배경 및 스토리 개발
- **퀘스트 디자이너**: 퀘스트 콘텐츠 및 보상 생성
- **빌더**: 세계 콘텐츠, 스크립트, 퀘스트 생성
- **리드 스크립터**: 범용 스크립트 개발 및 지원 제공
#### 커뮤니티 관리
- **리드 관리자**: 스태프 및 커뮤니티 표준 관리
- **관리자**: 플레이어 관계 지원 및 지침 시행
- **도움말 파일 리드**: 도움말 시스템 및 문서 조직
### 기여자 라이선스 계약
이 프로젝트에 대한 기여는 기여자 라이선스 계약을 동반해야 합니다. 기여에 대한 저작권은 유지되며, 이는 프로젝트의 일부로 기여를 사용하고 재배포할 수 있는 권한을 우리에게 부여합니다.
## 커뮤니티
### 우리 커뮤니티 참여
- **Discord**: [커뮤니티 참여](https://discord.gg/Me3Tuu4) - 주요 커뮤니케이션 허브
- **GitHub Discussions**: 개발 관련 토론 사용
- **Issues**: 버그 보고 및 기능 요청
### 커뮤니티 지침
- **존중**: 모든 커뮤니티 멤버를 존중과 친절로 대하세요
- **협력**: 공통 목표를 향해 함께 일하세요
- **건설적 피드백**: 도움이 되고 실행 가능한 피드백 제공
- **포용성**: 신규 사용자를 환영하고 시작을 돕습니다
### 도움 받기
- **Discord**: 적절한 채널에서 질문
- **문서**: 먼저 포괄적인 문서 확인
- **GitHub Issues**: 버그 보고 및 기능 요청용
- **게임 내 도움말**: 내장 도움말 시스템 사용
## 문제 해결
### 일반적인 문제
#### 빌드 문제
```bash
# 누락된 종속성
sudo apt-get install build-essential mariadb-server libmariadb-dev libgd-dev
# 권한 문제
chmod +x configure
chmod +x licheck
# 클린 빌드
make clean && make
```
#### 런타임 문제
```bash
# 데이터베이스 연결 문제
# MariaDB 서비스 상태 확인
sudo systemctl status mariadb
# 또는 이전 시스템용:
sudo systemctl status mysql
# 포트 이미 사용 중
# 포트 4000을 사용하는 것 확인
netstat -tulpn | grep :4000
```
#### 구성 문제
- 모든 `.h` 구성 파일이 제대로 설정되었는지 확인
- 구성 파일의 파일 권한 확인
- 데이터베이스 자격 증명이 올바른지 확인
### 지원 받기
1. [문제 해결 가이드](docs/guides/TROUBLESHOOTING_AND_MAINTENANCE.md) 확인
2. 기존 GitHub Issues 검색
3. Discord에서 커뮤니티 지원 요청
4. 버그 또는 기능 요청을 위한 GitHub Issue 생성
## 라이선스
이 프로젝트는 이중 라이선스 접근 방식을 사용합니다:
### tbaMUD/CircleMUD 코드
tbaMUD 프로젝트에서 기여된 코드는 그들의 라이선스 조건을 따릅니다. 자세한 내용은 [tbamud.com](https://tbamud.com)을 참조하세요.
### LuminariMUD 사용자 정의 코드
LuminariMUD를 위해 개발된 사용자 정의 코드는 **공개 도메인**으로 릴리스됩니다:
> 이는 공개 도메인으로 릴리스된 무료이고 무제한 소프트웨어입니다.
>
> 누구든지 이 소프트웨어를 소스 코드 형태 또는 컴파일된 바이너리 형태로 복사, 수정, 게시, 사용, 컴파일, 판매 또는 배포할 수 있으며, 상업적 또는 비상업적 목적으로, 어떤 수단으로든 가능합니다.
완전한 라이선스 세부 사항은 [LICENSE](LICENSE) 파일을 참조하세요.
## 감사 인사
### 기반
- **[tbaMUD](https://tbamud.com)**: 기본 MUD 코드베이스
- **[CircleMUD](http://www.circlemud.org)**: 원래 기반
- **CWG (Copper) MUD**: 추가 향상 기능 및 특징
### 영감
- **성경 이야기**: 영적 및 도덕적 테마
- **Dragonlance**: 서사적 판타지 요소
- **Forgotten Realms**: 풍부한 세계 빌딩 전통
### 버전 정보
- **현재 버전**: LuminariMUD 2.5001-beta (tbaMUD 3.64)
- **저장소**: https://github.com/LuminariMUD/Luminari-Source
- **생성일**: 2019년 7월 16일
- **언어**: C (ANSI C90/C89 표준) with C++11 performance monitoring
- **마지막 업데이트**: 2026년 1월
> 버전은 다음에서 정의됨: `src/constants.c` (공식), `src/structs.h`, `configure.ac`, `CMakeLists.txt`
---
**기억하세요**: *작업 자체가 보상입니다. 커뮤니티를 위한 의미 있는 것을 생성하는 데 집중하세요.*
더 많은 정보는 우리의 [기술 문서](docs/TECHNICAL_DOCUMENTATION_MASTER_INDEX.md)를 방문하거나 [Discord 커뮤니티](https://discord.gg/Me3Tuu4)에 참여하세요.
