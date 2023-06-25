# 1. General instructions

### - .vdi 파일의 signature과 제출한 signature가 동일한가?

# 2. 프로젝트 개요

### 1. 가상머신 동작 원리

**가상머신이란?**

컴퓨팅 환경을 소프트웨어로 구현한 것으로, 컴퓨터 시스템을 가상화한 것이다.

하나의 물리 서버에서 여러 개의 운영체제를 구동할 수 있도록하는 기술이다.

**동작원리**

virtual machine은 Hypervisor 위에서 작동한다.

Hypervisor는 하드웨어에서 리소스를 사용하여 VM을 생성하고 구동하는 소프트웨어이다. 

- hypervisor 분류
    
    Hypervisor에는 2가지 유형이 있다.
    
    1) 호스트형
        
        하드웨어 위에 바로 Hypervisor가 설치되는 형태
    
    2) 네이티브형
    
        호스트 운영 체제 위에 Hypervisor가 설치되는 형태이고, 해당 프로젝트에서 사용하는 virtualbox역시 Type 2에 속함
    
**Host와 Guest** 

Hypervisor가 설치되는 물리 하드웨어를 Host, Hypervisor에서 리소스를 사용하는 여러 VM을 Guest라고 한다.
    
우리가 클러스터의 macOS에서 다른 OS인 Debian을 구동시킬 수 있는 이유도 Hypervisior 덕분이라고 생각하면 된다.
    
**virtual machine의 장점** 
1. **비용 절감**

    여러 가상 환경을 하나의 인프라(하드웨어)에서 설치하기에 물리적 인프라 설치 공간을 줄일 수 있게 된다. 이 때문에 많은 서버를 유지 보수하지 않아도 되고 많은 전력을 사용할 필요가 없어 비용을 줄이는 데 도움이 된다.
        
2. **간편함+속도**
    
    새로운 환경(OS)을 구동하려는 경우 새 환경 전체(물리적 서버 포함)를 준비하는 것 보다 빠르고 간편하다.
        
3. **downtime의 최소화**
    
    `VM`은 호스트가 예기치 않게 중단될 경우 다른 물리적 서버의 `Hypervisor`로 이전할 수 있다. 이는 유용한 백업 대책에 마련되있다는 의미이다.
        

### 2. 선택한 운영체제 및 CentOS와 Debian의 차이점

CentOS와 Debian은 모두 linux 운영체제로, **커널 + 자유소프트웨어**로 구성된 리눅스 배포판이다. 따라서 두 OS차이는 자유소프트웨어(패키지 포맷, 패키지 관리 툴 등)이다.

- CentOS vs. Debian
    
    ### **CentOS**
    ---
    - RHEL에서 사후 기술지원과 상표권을 배제하고 제작한 오픈소스이다.
    - 패키지 포맷으로 .rpm 확장자를 사용하고, yum/dnf을 패키지 관리 툴로 사용한다.
    - 다양한 아키첵처를 지원하지 않는다.
    - 쉬운 GUI가 없다.
    - 기업용 서버에서 주로 사용된다.
    
    ### **Debian**
    ---
    - debian project에서 제작한 오픈소스이다.
    - 패키지 포맷으로 .deb 확장자를 사용하고, dpkg와 APT를 패키지 관리 툴로 사용한다.
    - 많은 패키지를 가지고 있고, 패키지 관리가 매우 편하다.
    - 데스크톱 친화적인 GUI가 있다.


### 3. 가상머신의 목적

1. 하나의 하드웨어에서 서로 다른 두개 이상의 운영체제를 실행하기 위함
2. 여러 사용자에게 자원을 독립된 환경으로 분리시켜서 분배하고 싶을 때
3. 하드웨어에 영향을 주지 않는 독립 환경을 만들고 싶을 때

    ex)악성코드 분석 시, 감염 등의 영향 방지

### 4. aptitude와 apt의 차이점(debian)

aptitude와 apt 모두 APT(Advanced Packaging Tool)이다.

- aptitude vs. apt
    
    ### **aptitude**
    
    ---
    
    - GUI와 CLI 모두 제공한다.
    - 주요 패키지 작업 과정을 자동화하여 가능한 쉽게 작업할 수 있도록 해줌
    - apt-get의 command-line argument를 제공하기 때문에 apt-get을 완전히 대체할 수 있다.
    - apt-get 외에 apt-chche, apt-mark와 같은 툴도 제공한다.
    
    ### **apt**
    
    ---
    
    - CLI만 제공한다.
    - 실질적으로 apt는 dpkg와 함께 작동한다.
    - 하지만, 필요한 소프트웨어의 검색, 다운로드, 설치, 업그레이드, 검사 등 대부분의 패키지 관리작업은 apt 단독으로 가능
    - 여러가지 APT(cache, mark, get)에서 자주 사용하는 옵션만 추출하여 사용자들이 보기 편하고 사용하기 쉽게 만든 것이다.

### 5. APPArmor(Application Armor)는 무엇인가?

리눅스 커널의 보안 모듈로, 오픈 소스이고, 시스템 관리자가 프로그램 프로필 별로 프로그램의 역량을 제한할 수 있게 해준다.

특정 프로그램에서 **필요한 리눅스 기능, 네트워크 사용 여부, 파일 권한 등에 대한 접근을 허용하는 설정파일로 구성**한다.

- DAC vs. MAC
    ### **DAC**
    ----
    - 임의접근제어, Discretionary Access Control
    - 소유자가 사용자 또는 그룹이 자원에 접근하는 것을 조절

    ### **MAC**
    ----
    - 강제접근제어, Mandatory Access Control
    - 사용자에게 정의된 정책을 활용해 사용자와 프로세스의 행동을 제어

enforce 모드와 complain모드 두가지가 존재한다. enforce 모드는 허가되지 않은 파일에 접근하는 것을 거부하는 모드, complain모드는 실질적으로 보안을 제공하는 것은 아니고, 어플리케이션이 해야할 행동이 아닌 다른 행동을 하는경우에 앱 아머는 로그를 남겨준다.

```jsx
sudo aa-status : apparmor 상태확인
```

# 3. 기본 설정


### Setup 1.

- 가상머신 그래픽 환경 없는지 확인
- 가상머신 연결 시도 시 비밀번호 요구하는지 확인
- 비밀번호가 policy에 맞는지? - 길이 10자 이상, 대문자, 숫자 포함, 같은 문자 최대 3번

### Setup 2.

- UFW 서비스가 시작되었는지 확인

```c
$ sudo ufw status (verbose)
```

### Setup 3.

- SSH 서비스가 시작되었는지 확인

```c
$ systemctl status ssh
```

### Setup 4.

- OS가 Debian인가?

```c
$ uname -a
```

# 4. 사용자

- 유저가 잘 추가되었는지 확인. 이때, 유저가 sudo와 user42 그룹에 속하는지 확인

```c
$ groups
// or
$ getent group sudo user42
// or
$ id
```

- 새로운 유저 생성 후 평가자가 password policy에 맞는 password를  만든 뒤, password policy의 설정 방법 설명하기
    - adduser vs. useradd
        
        ### adduser
        
        - 이건 home 디렉토리에 username의 폴더가 생겨버림
        - 그룹에 다 포함됨
        
        ### useradd
        
        - 이거는 그냥 사용자가 생성됨
        - 저수준의 사용자 추가

```c
1. 새로운 유저 생성하기
$ sudo adduser <Nusername>
2. 제시된 규칙에 맞게 임의로 비밀번호를 만듦
```

```c
3. 피평가자는 과제에 제시된 규칙을 어떻게 설정했는지 설명함

$ sudo vi /etc/login.defs
 
PASS_MAX_DAYS 30 // 30일 후 만료
PASS_MIN_DAYS 2  // 최소 사용기간 2일
PASS_WARN_AGE 7  // 7일전에 경고 보내기
```

```java
$ sudo apt install libpam-pwquality // 패키지 설치

$ sudo vi /etc/pam.d/common-password // 이 파일에서 비밀번호 정책 수정

/// common-password 파일 수정
retry=3   // 암호 재입력은 최대 3회까지
minlen=10 // 최소 길이 10
difok=7   // 기존 패스워드와 달라야 하는 문자 수 7
maxrepeat=3 // 같은 문자 연속해서 3글자 사용x
ucredit=-1  // 대문자 한개 이상 포함
lcredit=-1  // 소문자 한개 이상 포함
dcredit=-1  // digit 한개 이상 포함
reject_username // username이 그대로 혹은 reversed 된 문자는 패스워드로 사용 불가
enforce_for_root // root 계정도 위의 정책들 적용
```

비밀번호 정책은 정책이 변경된 이후 생성된 계정부터 적용된다. 기존 계정들에 적용하기 위해 비밀번호를 만료시켜버린다.

```
$ passwd -e [username]  //passwd -e (expire) 비밀번호 만료 옵션.
```

/etc/login.defs 내용도 기존 계정들은 따로 적용해줘야 한다.

```
$ sudo chage -m 2 -M 30 -W 7 [username]  #-m MIN_DAYS -M MAX_DAYS -W WARN_DAYS
```

- enforce_for_root의 암호 정책 -> root 계정 적용 시?
    
    `enforce_for_root`는 암호 정책을 root 계정에도 동일하게 적용된다는 내용인데도 불구하고, 직전 비밀번호 7자 규정은 적용되지 않는 이유는 root 계정의 비밀번호 변경시에는 직전 비밀번호를 확인하지 않기 때문입니다.
    

- 새로운 유저가 추가된 상태에서 evaluating이라는 그룹을 만든 후, 해당 그룹에 새 유저 추가

```c
$ sudo groupadd evaluating
$ sudo usermod -aG evaluating <NEW_USER>
```

`-G` ⇒ user가 명시된 그룹에만 속하게 된다.

`-Ga` ⇒ user가 기존에 속해져 있던 그룹 + 명시된 그룹에 속하게 된다.


- password policy의 장점과 단점
    
    장점 : 보안이 향상된다.
    
    단점 : policy가 너무 어려울 경우 비밀번호를 자주 까먹을 수 있다.
    

# 5. **호스트명과 파티션들**


- 이 가상머신의 호스트명이 yerilee42인지 확인

```c
$ hostnamectl
```

- 로그인 후, 원래의 호스트 명을 변경 후 restart 하기 → 업데이트 확인

```c
$ sudo hostnamectl set-hostname <변경할 이름>
$ sudo reboot
```

- 원래 이름으로 복원하기

```c
$ sudo hostnamectl set-hostname <yerilee42>
$ sudo reboot
```

```c
$ lsblk
```

- LVM에 관해 설명하기 (어떻게 작동하는지, 무엇에 관한 것인지)
    
    ```
    Logical Volume Manager의 약자로, 논리적 볼륨을 관리하는 커널의 일부이자 프로그램
    파티션이란 디스크를 원하는 크기로 조각내어 사용하는 것인데, 사용하기에 애매한 여분의 파티션들을 합쳐서 하나의 공간을 만들어내는 것
    
    LVM을 사용하는 이유
    1. 여러개의 디스크 공간을 합쳐서 하나인 것처럼 사용하기 위해
    2. 사용하기 애매한 공간의 파티션들을 활용하기 위해
    3. 기존에 사용 중인 디스크 공간을 확장하기 위해
    ```
    

하드디스크에 용량이 부족할 때

1. 추가 디스크 장착 → 백업
    1. 9G/10G에서 추가로 30G 장착했다면
    2. 9G내용을 백업해서 30G에 넣고 기존 디스크 해제
    3. 하지만 문제!! 개인 컴퓨터는 문제 없지만, 서버 컴퓨터는 다루는 데이터 양이 많기 때문에 백업보다는 추가디스크 장착하는 방법을 택함
2. 추가 디스크 장착 → lvm
    1. 추가로 10g, 20g를 장착했다고 하더라도 기존의 9G/10G가  9G/40G이 되진 않음
    2. 이를 도와주는 게 lvm!! 하드디스크를 pe단위로 나누어 이를 조합해서 lv를 만들고 이를 디렉토리에 장착함
- LVM 추가 설명
    
    LVM이 불가능한 경우에, 각각의 볼륨 그룹이 모두 찼는데 용량을 추가하고 싶은 경우, 추가 디스크(물리)를 장착하여, 새로운 마운트 포인트를 만들고, 추가한 디스크에 파티션을 생성하고 포멧하여 마운트하고, 기존 내용을 복사한 후에 기존 내용 언마운트 후 새 파티션을 기존의 파티션에 마운트 해야했지만,
    
    LVM을 사용하는 경우 추가된 디스크에 새로운 `PV` 를 생성하고, `VG` 에 추가 후, 기존의 `VG` 의 `LV` 사이즈만 키워주면 된다. → 훨씬 간편
    
    [[소개] LVM(Logical Volume Manager) - 개념](https://tech.cloud.nongshim.co.kr/2018/11/23/lvmlogical-volume-manager-1-%EA%B0%9C%EB%85%90/)
    

LVM 작동 방식

1. 하드 디스크를 여러 개로 나누어 `partition`을 설정한다. 
2. 각 `parition`을 `LVM`으로 사용하기 위해 물리볼륨(PV)으로 변환해준다.
3. 하나 이상의 물리볼륨(PV)을 그룹화하여 볼륨그룹(VG)으로 만든다.
4. 가상의 `partitions`처럼 물리그룹(PG)을 나누어 할당 한 것이 논리불륨(LV)이다.
5. 논리볼륨(LV)을 새 파일시스템(마운트 포인트)과 1대 1로 마운트(연결)한다.
    
    <aside>
    💡 `LVM`이 물리볼륨(PV)을 가리키는 단위는 물리적 범위(PE)로 기본 단위는 4MB이다.
    
    </aside>
    
    <aside>
    💡 `LVM`이 논리불륨(LV)을 가리키는 단위는 논리적 범위(PE)로 기본 단위는 4MB이다.
    
    </aside>
    
    <aside>
    💡 파일시스템은 파일이나 자료를 쉽게 발견 및 접근할 수 있도록 보관 또는 조직하는 체제를 가리키는 말이다.
    
    </aside>
    
    
    [파일 시스템 마운트](https://yangorithm.tistory.com/102)
    
    [[ 기본정리 ] 파일 시스템과 디렉토리 계층 구조](https://rrhh234cm.tistory.com/190)
    
    [[Linux] 파일 시스템](https://neul-carpediem.tistory.com/98)
    

# 6. SUDO


- sudo 프로그램이 가상머신에 제대로 설치되어있는지 체크

```c
$ sudo --version
```

- 새 user를 sudo 그룹에 할당하기

```c
$ sudo usermod -aG sudo <사용자이름>
$ id <사용자이름>
```

- 해당 과제는 sudo에 대한 엄격한 규칙들을 요구합니다. 여러 예시를 통하여 sudo의 목적과 동작을 보여주세요. 그리고 과제에서 요구하는 엄격한 규칙들을 구현한 것을 보여주세요.

```java
sudo visudo : sudo 설정파일 편집 -> 문법 체크도 함

/*
	**visudo**
	/etc/sudoers 파일을 수정하는 명령어이다.
	/etc/sudoers 파일은 기본적으로 쓰기 권한이 없기 때문에
	기존에 있는 리눅스 편집기인 'vi'나 'nano'를 사용하지 않고
	visudo 명령어를 사용한다.
*/
```

```c
# secure_path 끝에 :/snap/bin 추가  

Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

/*
	보안을 위해 secure_path(sudo가 사용할 수 있는 경로)를 제한하라
	`secure_path` : 명령을 수행하기 위해 `sudo`가 실행할 소프트웨어를 찾는 경로
	`/A:/B` : A에 없으면 B에서 찾아라
*/

# 다음 설정 추가

Defaults        passwd_tries=3 
Defaults        authfail_message="Authentication faliure!"
Defaults        badpass_message="Password is wrong!"
Defaults        iolog_dir="/var/log/sudo"
Defaults        log_input
Defaults        log_output
Defaults        requiretty

// 일치하지 않는 password인 경우 입력은 3회로 제한하라
// Authentication 획득 실패 시 출력되는 error 메시지
// password가 일치하지 않는 경우 출력되는 error 메시지
// log(input, output)의 저장을 해당 디렉토리에 하라
// sudo 명령어 실행 시 입력된 명령어를 iolog_dir에 log로 저장하라
// sudo 명령어 실행 시 출력 결과를 iolog_dir에 log로 저장하라
// 사용자가 실제 tty로 로그인한 경우에만 실행을 허용
```

- sudo secure path 설정
    
    [[Linux] Sudo 명령의 Secure Path - ECE - TUWLAB](https://www.tuwlab.com/ece/24044)
    
- sudo 명령어 사용이유
    
    ### sudo
    
    - 유닉스 및 유닉스 계열 운영체제에서, 다른 사용자의 보안 권한, 보통 슈퍼유저로서 프로그램을 구동할 수 있도록 하는 프로그램
    - superuser do에서 유래
    - **sudo (명령어)**
    일반 사용자가 root권한을 잠시 빌려 명령을 실행
    - **su (계정명)**
    현재 사용자를 로그아웃하지 않은 상태에서 다른 사용자의 계정으로 전환하는 명령어
    - **su - (계정명)**
    다른 사용자의 계정으로 완전히 전환하고, 전환한 사용자의 환경설정을 불러오는 명령어
    
    **사용이유**
    
    - root는 무한대의 권한을 가지고 있음 ⇒ 침입자들은 root 권한 얻어내는게 최우선
    - root의 권한은 시스템 관리자, 시스템커널 자체, 서비스 데몬의 대개 세가지 경우로 한정
    
    **su 대신 sudo의 장점**
    
    root password를 효율적으로 관리할 수 있다.
    
    여러 사람이 root 패스워드를 공유하면, 정기적인 변경의 어려움과 외부 노출확률이 높아진다.
    
    일반 사용자가 root 권한을 빌려 명령을 실행하기 위해 sudo를 사용한다. 또한 sudo를 사용하게 되면 아래와 같은 장점이 있다.
    
    1. 시스템 침입자가 sudo를 사용하면 sudoers에 자신이 노출되기에 침입을 확인할 수 있다는 장점이 있다.
    2. root 계정에 장시간 머무를 일이 없어져서 위험한 command를 실행할 가능성이 낮아진다.
    3. sudo 사용 시에는 log가 남아 추적이 쉽다.
        
        <aside>
        💡 root 계정에서 작업하면 log가 남지 않는다
        
        </aside>
        
    4. root의 password를 타인과 공유하지 않아도 되기에 효율적(잦은 비밀번호 변경 X, 외부로의 노출 X)으로 관리할 수 있다.
        
        [sudo 사용으로 root 권한보호](https://blog.naver.com/PostView.naver?blogId=hymne&logNo=221030419175&categoryNo=185&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search)
        

- "/var/log/sudo/" 폴더가 존재하는지, 최소 한개 이상의 log 파일이 존재하는지 확인

```c
$ sudo ls /var/log/sudo
```

- 파일의 내부에는 sudo와 함께 사용된 명령어들의 기록이 존재해야 함
    
    그리고 sudo 명령어를 사용 후 log 파일이 업데이트 되었는지 확인
    

- log파일은 /var/log/sudo/00/00에 명령어당 한 폴더씩 생성되어 저장된다.
    - log - sudo 명령어 실행 위치가 저장된다.
    - stderr - 표준 에러 발생시 기록된다.
    - stdin, stdout - 표준 입출력 발생시 기록된다.
    - ttyin, ttyout - tty 입출력 발생시 기록된다.
    - timing - 명령어 실행시간과 관련 있는 것 같다.

```c
$ sudo apt update
$ sudo ls /var/log/sudo/00/00
```

# 7. UFW

- UFW의 설치 여부 확인

```c
$ sudo ufw --version
```

- UFW의 작동 여부 확인

```c
$ sudo ufw status (verbose)
```

- UFW에 대한 설명 & 사용하는 이유
    
    - **UFW ( Uncomplicated Firewall )**
    
        데비안 계열을 비롯한 여러 리눅스 환경에서 작동하는 방화벽 관리 프로그램
    
        단순하고 사용자가 사용하기 쉬운 명령어로 구성되어 있음
    
    
    대표적으로 외부 침입자가 내부 `network`에 침입하는 경우를 막기 위해서 `UFW`를 사용한다.
    
    Linux 커널은 서버에 대한 `client`의 네트워크 접속을 제어하는 `netfilter Module`을 가지고 있다. netfilter를 사용하여 filtering을 수행하는데, 이것을 이용하여 서버 접속에 대한 `network policy`를 세우는 프로그램이 바로 `Firewall`(방화벽)이다.
    
    특히 리눅스에서 가장 많이 사용하는 필터는 `iptables` 이다. 그러나 이 기본 모듈 소프트웨어만 가지고는 절차 상 번거로운 면이 있기 때문에 `iptables`의 작업을 간편화 해주는 소프트웨어가 바로 `UFW`(Uncomplicated FireWall)이다. 
    
    해당 `subject`에는 `port 22`를 닫고 `port 4242`를 여는데 사용했다.
    
    [리눅스 기본 방화벽 UFW 활용방법](https://cosmosproject2015.tistory.com/6)
    

- UFW의 활성된 규칙들을 나열하세요, 4242 포트에 대한 규칙도 있어야 함

```java
$ sudo cat /etc/ufw/user.rules
```

- 8080 포트를 열기 위한 새로운 규칙을 추가 & 잘 추가되었는지 확인

```c
$ sudo ufw allow 8080
$ sudo cat /etc/ufw/user.rules
```

- 새로운 규칙을 삭제

```c
$ sudo ufw status numbered
$ sudo ufw delete <NUMBER>

---------------------------

$ sudo ufw delete allow 8080
```

# 8. SSH


- SSH의 설치 여부 확인

```c
$ sudo ssh -V
```

- SSH의 작동 여부 확인

```c
$ systemctl status ssh
```

- SSH가 무엇인지, 그리고 그걸 사용할 때의 장점
    
    <aside>
    💡 **SSH ( Secure Shell Protocol)**
    인터넷과 같은 public Network를 통해 컴퓨터간의 통신을 할 때, 보다 안전하게 통신을 하기 위해 사용하는 프로토콜
    주로 원격 제어를 할 때 많이 사용됨
    
    </aside>
    
    SSH는 원격으로 호스트(Shell)에 접속하기 위해 사용되는 보안 프로토콜이다. 즉, 모든 데이터는 암호화가 보장된다. SSH는 한 쌍의 key(public key/private key)를 이용하여 데이터를 암호화/복호화하는데 private key는 클라이언트, public key는 호스트가 가지고 있어야한다. 따라서 연결시 fingerprint 생성 여부를 묻는 것.
    
    
    `SSH`를 사용하는 이유는 역시 보안이 된다는 장점 덕분이다.
    

- SSH 서비스가 4242포트만 사용하는지 확인

```c
$ sudo vi /etc/ssh/sshd_config
```

<aside>
💡 sshd_config ⇒ server 측 설정
ssh_config ⇒ client 측 설정

</aside>

- SSH를 통해 새로운 유저에 로그인 하기 & 그리고 SSH로 root에 접근할 수 없어야 함
    - terminal에서 ssh 접속
        
        ```c
        $ ssh <NEW_USER>@<MAC_IP> -p <HOST_PORT>
        ```
        
        ```c
        $ ssh yerilee@127.0.0.1 -p 4242
        ```
        
        
    - ssh로 root 계정 외 user로 로그인 ( 보안 상 ssh로 root 계정으로는 바로 접속 불가능 하도록 설정 )
        
        ```c
        $ cat /etc/ssh/sshd_config | grep "PermitRootLogin"
        ```
        

<aside>
💡 `SSH` 연결을 위해 포트포워딩이 필요하다

</aside>

- 포트포워딩
    
    포트포워딩(Port forwarding)은 간단히 말해 포트(Port)를 전달(Forwarding)해 주는 거라고 생각하면 됨
    
    특정한 포트로 들어오는 데이터 패킷을 다른 포트로 바꿔서 다시 전송해주는 작업
    
    ## **포트포워딩의 필요성**
    
    ---
    
    나만의 웹서버를 **리눅스 환경**에 구축하고 싶어서
    
    **Virtual Machine**에 **리눅스**를 설치하고 이 리눅스 환경에 **웹서버**를 설치하였다.
    
    (웹서버는 Nginx 포트는 80번이라고 가정한다)
    
    웹서버 설치를 완료하고 잘 접속이 되는지 테스트하기 위해서
    
    실제 OS환경(Windows)에 크롬 브라우저를 띄우고 주소창에 [http://localhost](http://localhost/) 를 입력해보지만..? **접속 x**
    
    Why? 가상환경에서 네트워크 주소와 실제 네트워크 주소가 다르기 때문이다.
    
    (실제 웹서버는 VM에 설치되있지만 브라우저에서는 실제 머신 주소로 접근하기 때문에 접속이 안된다)
    
    따라서, 아래와 같이 브라우저가 내 localhost 주소로 접속 했을 때 실제 머신이 아닌 Virtual Machine으로 연결시켜주어야 한다.
    
    
    이 예제에 한해서, 위와 같이 80번 포트를 통해 내 머신에 접속 했을 때
    
    Virtual Machine으로 연결시키는 과정을 쉽게 말해서 포트 포워딩이라 한다.
    

# 9. Script monitoring

- 스크립트가 어떻게 동작하는지 코드를 보여주기
    
    **monitoring.sh**
    
    1. 운영 체제 및 해당 커널 버전의 아키텍처
    2. 물리적 프로세서의 수 # 코어라고 생각됨
    3. 가상 프로세서의 수
    4. 서버에서 현재 사용 가능한 RAM 및 사용률(백분율)
    5. 서버의 현재 사용 가능한 메모리 및 사용률(백분율)
    6. 프로세서의 현재 사용률을(백분율)표시
    7. 마지막 재부팅 날짜 및 시간
    8. LVM이 활성 상태 여부
    9. 활성 연결 수 # 네트워크 소켓이 몇 개인지 찾으면 됨 
    10. 서버를 사용하는 사용자 수
    11. 서버의 IPv4 주소 및 해당 MAC(Media Access Control) 주소
    12. sudo 프로그램으로 실행된 명령 수
    
    ```jsx
    #!/bin/bash
    #1
    printf "#Architecture: "
    uname -a
    
    #2
    printf "#CPU physical : "
    cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l
    
    #3
    printf "#vCPU : "
    grep -c processor /proc/cpuinfo
    
    #4
    printf "#Memory Usage: "
    free --mega | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100 }'
    
    #5
    printf "#Disk Usage: "
    df -Bm | grep /dev/map | awk '{sum += $3}END{print sum}' | tr -d "\n"
    printf "/"
    df -BG | grep /dev/map | awk '{sum += $2}END{print sum}' | tr -d "\n"
    printf "Gb ("
    df -Bm | grep /dev/map | awk '{sum1 += $3 ; sum2 += $2 }END{printf "%d%%)\n", sum1 / sum2 * 100}'
    
    #6
    #apt install sysstat
    printf "#CPU load: "
    mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'
    
    #7
    printf "#Last boot: "
    who -b | awk '{print $3, $4}'
    
    #8
    printf "#LVM use: "
    lsblk | grep lvm | wc -l | awk '{if($NF > 0) {print "yes"} else {print "no"}}'
    
    #9
    printf "#Connections TCP : "
    ss | grep -i tcp | wc -l | awk '{if($NF == 0) {print $NF" ""NONE"} else if ($NF >= 1) {print $NF" ""ESTABLISHED"}}'
    
    #10
    printf "#User log: "
    who | wc -l
    
    #11
    printf "#Netwrok: IP "
    hostname -I | tr -d "\n"
    printf "("
    ip addr | grep ether | awk '{print $2}' | tr -d "\n"
    printf ")\n"
    
    #12
    printf "#Sudo : "
    journalctl _COMM=sudo | wc -l | tr -d "\n"
    printf " cmd\n"
    ```
    
    ```c
    uname -a // 시스템의 정보를 출력 [Linux(커널 이름) 
    // yerilee42(호스트 명) 5.10.0-19-amd64(커널 릴리즈 번호) #1 SMP Debian 5.10.149-2 (2022-10-21)(커널 버전과 커널이 빌드된 날짜 정보) x86_64(호스트의 프로세서 아키텍쳐 정보) GNU/Linux(시스템 운영체제 이름 정보)]

    cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l // -u : 정렬에 중복된 것 제외
    
    cat /proc/cpuinfo | grep processor | wc -l // 전체 가상코어수 : 48 (=4CPU * 6코어 * 2쓰레드)

    free -m // 메모리 사용량을 mb 단위(-m)로 출력한다
    
    df -P // 리눅스 내 디스크 메모리 전체 현황을 한줄로(-P) 출력한다
    
    mpstat // 현재 CPU의 사용량을 출력한다
    // 100-$13 : $13은 유휴(컴퓨터 처리 장치에서 유휴 또는 아이들은 어떠한 프로그램에 의해서도 사용되지 않는 상태)인 cpu를 나타내며 우리는 cpu 사용률을 보여줘야 하므로 전체 100에서 유휴 상태 cpu를 빼준 결과를 출력하면 된다.
    
    who -b // 마지막 리부트 날짜와 시간
    
    ss | grep -i tcp // 활성화된(현재 연결된) tcp 네트워크 상태를 출력한다 | -i : 대문자/소문자 무시
    
    who // 서버를 사용하는 유저들을 출력한다
    
    hostname -I // IPv4 주소
    
    journalctl : 리눅스 로그 확인, _COMM : 특정 로그 보기
    ```

    
    - 코어, 쓰레드, 하이퍼쓰레딩
        
        core (physical core) : cpu 내부적으로 반도체부품을 통하여 실제로 존재하는 부분
        
        thread (logical core) : os에서 인식하는 core 수
        
        hyper threading : 코어 수 x 2만큼 os에서 인식하게 하는 기술
        
        https://information-factory.tistory.com/38
        

- cron이 무엇인지 설명하기
    
    unix 운영체제에서 어떤 작업을 특정 시간에 실행시키기 위한 데몬(백그라운드에서 작업을 하는)프로그램으로, crontab 파일을 통해 cron 작업을 설정할 수 있음
    
    <aside>
    `데몬`은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램을 말한다. 백그라운드 프로세스와 다른점은 사용자와 상호작용하지 않는 독자적인 프로세스란 것이다.
    
    </aside>
    
    - 스크립트를 10분마다 실행되도록 설정하는 방법
        
        ```c
        * * * * * command 
        | | | | |_ // 요일
        | | | |_ // 월
        | | |_ // 일(날짜)
        | |_ // 시간
        |_ // 분
        
        // 예시1) 5일에서 6일까지 2시,3시,4시에 매 10분마다 test.sh 를 실행
        */10 2,3,4 5-6 * * /home/script/test.sh
        
        // 10분마다 monitoring.sh를 실행
        */10 * * * * sh /root/monitoring.sh | wall
        
        wall → 모든 로그인한 사용자에게 메시지를 표시할 때 쓰는 명령어
        `-` ⇒ 그 사이 모든 값
        `,` ⇒ 지정 값
        `/` ⇒ 특정 주기로 나누기
        ```
        
    - 1분마다 script가 실행 되도록 수정
        
        ```c
        $ sudo crontab -e
        
        // crontab
        */1 * * * * sh /root/monitoring.sh | wall
        
        $ sudo service cron restart
        ```
        
    - 서버 시작 시 script 실행 안되게 수정하기 (crontab 수정)
        
        💡 스크립트 파일 내용 수정, 위치 이동, 권한 수정 금지!
        
        ```jsx
        $ sudo systemctl disable cron
        $ sudo reboot
        $ sudo service cron status
        $ sudo systemctl enable cron // enable 상태로 수정
        ```
        

# Bonus


- 파티션 설정은 2점의 가치가 있다.
    
- 주제에 필요한 서비스로만 WordPress를 설정하는 것은 2점의 가치가 있다.
    - lighttpd, MariaDB, PHP를 이용해서 WordPress로 기능을 갖춘 웹사이트를 구성
- 무료 선택 서비스는 1점의 가치가 있다. 각 추가 서비스의 적절한 기능 및 구현을 확인하고 테스트한다. 무료 선택 서비스의 경우, 평가를 받는 학생은 그것이 어떻게 작동하고 그것이 왜 유용하다고 생각하는지에 대해 간단한 설명을 제공해야 한다.
- NGINX 및 Apache2는 금지되어 있다.

- Bonus 구현 방법
    
    ### Lighttpd 설치
    
    ```bash
    sudo apt-get install lighttpd
    ```
    
    - 서버활성화
    
    ```bash
    sudo systemctl enable lighttpd.service		#enable with start up
    sudo systemctl start lighttpd.service
    ```
    
    - 서버 정지
    
    ```bash
    sudo systemctl stop lighttpd.service
    ```
    
    ### PHP 설치 및 연동
    
    다음 명령어를 통해 **웹 서버와 연동**할 PHP 를 설치한다.
    
    - PHP-FPM 은 PHP **FastCGI** Process Manager의 약자
    
    ```bash
    sudo apt install php php-fpm
    ```
    
    설치 후, 다음 명령어를 통해 php.ini 파일의 **cgi.fix_pathinfo=1** 행 주석을 해제한다.
    
    - 파일 위치: /etc/php/7.4/fpm
        
    
    vim 일반 모드에서 / 을 누르고 pathinfo 찾기
    
    밑부분 
    
    cgi.fix_pathinfo=1 주석 해제하기

    ### 설치한 lighttpd의 Fastcgi 설정 파일 편집
    
    - 파일 위치
    
    ```bash
    vi /etc/lighttpd/conf-available/15-fastcgi-php.conf
    ```
    bin-path와 socket 주석 처리를 하고 **"socket" => "/var/run/php/php7.3-fpm.sock"을 추가**
    
    
    저장하고 lighttpd 재시작
    
    ```bash
    sudo lighttpd-enable-mod fastcgi 
    sudo lighttpd-enable-mod fastcgi-php
    sudo service lighttpd force-reload
    ```
    
    
    lighttpd 설정 확인해보자
    
    ```bash
    vi /etc/lighttpd/lighttpd.conf
    ```
    
    기본 설정은 위와 같이 80번 포트로 되어있음. ufw 방화벽이 켜져 있어서 80번 포트 해체해주자.
    
    ```bash
    sudo ufw allow 80
    ```
    
    포트 설정하기
    
    위에서 포트 80을 말함 이제 lighttpd로 우리가 사이트로 접근을 할 수 있음 
    
    chrome창에 127.0.0.1:8080 했을 때 밑의 사진처럼 나옴 
    
    
    ---
    
    ### 연결이 안 될 때
    
    
    ```bash
    sudo systemctl status lighttpd.service
    ```
    
    패키지 다시 삭제하고 설치
    
    ```bash
    sudo apt-get purge lighttpd
    ```
    
    ```bash
    sudo apt-get install lighttpd
    ```
    
    설치 후 다시 설정
    
    ```bash
    sudo lighttpd-enable-mod fastcgi 
    sudo lighttpd-enable-mod fastcgi-php
    service lighttpd force-reload
    ```
    
    ---
    
    잘 되면 아래와 같이 나옴
    
    
    정상적으로 연결이 잘 되었을 때 표시되는 페이지는, 위 **lighttpd.conf** 파일의 **server.document-root** 에 해당하는 디렉토리, **/var/www/html/** 의 index.lighttpd.html 파일이다
    
    
    이제 PHP 연동이 잘 되었는지 확인 하기 위해
    
    - /var/www/html 폴더 안에 info.php 작성
    
    ```bash
    root@yerilee42:/var/www/html# vi info.php
    ```
    
    ```bash
    <?php
    	phpinfo();
        ?>
    ```
    
    저장한 후 
    
    url을 아래와 같이 작성한다.
    
    ```bash
    127.0.0.1:8080/info.php
    ```
    
    
    ---
    
    ### php 연결 안 됐을 때
    
    참고 → https://han-joon-hyeok.github.io/posts/born2beroot-install-wordpress/
    
    ---
    
    PHP를 설치할 때 DB와 연동하기 위한 아래 패키지 설치
    
    ```bash
    sudo apt-get install php7.4-mysql
    ```
    
    웹으로 웹 서버와 PHP가 정상적으로 동작하는 것을 확인했으니
    
    이제 데이터베이스 서버 설치 차례다.
    
    ### MariaDB
    
    ```bash
    sudo apt-get install mariadb-server mariadb-client
    ```
    
    서버 구동
    
    ```bash
    sudo systemctl enable mysql.service
    ```
    
    ```bash
    sudo systemctl start mysql.service
    ```
    
    상태 확인
    
    ```bash
    sudo systemctl status mysql.service
    ```

    
    보안 설정 
    
    ```bash
    sudo mysql_secure_installation
    ```
    
    
    재시작
    
    ```bash
    sudo systemctl restart mysql.service
    ```
    
    상태 확인
    
    ```bash
    sudo systemctl status mysql.service
    ```
    
    ### Wordpress에 연동할 DB 생성
    
    MariaDB 진입
    
    ```bash
    sudo mysql -u root -p
    ```
    
    
    진입한 뒤 SQL 문법으로 DB 생성과 계정 만들고, 권한 부여 
    
    1. 데이터베이스 생성
    
    ```bash
    CREATE DATABASE wpdb;
    ```
    
    1. 계정과 암호 생성
    
    ```bash
    CREATE USER 'wpdb-user'@'localhost' IDENTIFIED BY 'wp-pw';
    ```
    
    1. 생성한 DB에 대한 full access 부여
    
    ```bash
    GRANT ALL ON wpdb.* TO 'wpdb-user'@'localhost' IDENTIFIED BY 'wp-pw' WITH GRANT OPTION;
    ```
    
    1. 확인
    
    ```bash
    show databases;
    ```
    
    1. 설정 마치고 종료
    
    ```bash
    FLUSH PRIVILEGES;
    ```
    
    ```bash
    EXIT;
    ```
    
    
    ### Wordpress 설치
    
    **server.document-root** 가 설정되어 있던 디렉토리
    
    ```bash
    /etc/lighttpd/lighttpd.conf
    ```
    
    /var/www/html 디렉토리에 Wordpress를 설치
    
    ```bash
    sudo apt-get install wget
    sudo wget -O /tmp/wordpress.tar.gz "http://wordpress.org/latest.tar.gz"
    sudo tar -xvzf /tmp/wordpress.tar.gz -C /var/www/html
    ```
    
    chrome 접속
    
    ```bash
    127.0.0.1:8080/wordpress
    ```
    
    아래와 같이 나옴
    
    
    ### Wordpress 와 Maria DB 연동
    
    설치한 Wordpress와 생성한 DB 연동하기 위해 Wordpress를 설치한 경로에 있는 config 파일을 편집해야함.
    
    ```bash
    vi /var/www/html/wordpress/wp-config-sample.php
    ```
    
    
    Define 부분에 계정 암호 편집
    
    
    밑으로 조금 내려보면 인증키 설정 부분 있음
    
    
    define 전부 주석 처리 하고
    
    여기 사이트 들어가서 복붙한다.
    
    [](https://api.wordpress.org/secret-key/1.1/salt/)
    
    
    저장하고 sample 파일 이름을 wp-config.php로 변경
    
    ```bash
    mv /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php
    ```
    
    다시 접속해보면
    
    완료!