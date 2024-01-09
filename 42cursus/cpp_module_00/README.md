# **C++ - Module 00**

이름공간, 클래스, 멤버함수, 표준 입출력 스트림, 초기화 리스트, 정적변수, 상수 그리고 많은 기초 사항들

요약: 이 문서는 C++ 모듈의 00번째 모듈 서브젝트를 담고 있습니다.

# Introduction

C++은 Bjarne Stroustrup이 C 프로그래밍 언어를 확장한 범용 프로그래밍 언어입니다. "C with Classes"라고도 불립니다.

이 모듈의 목표는 여러분을 **객체 지향 프로그래밍**에 소개하는 것입니다. 이것이 여러분의 C++ 여행의 시작점이 될 것입니다. 많은 언어들이 OOP를 배우기에 적합하다고 추천합니다. 우리는 여러분의 친구인 C에서 파생된 C++를 선택했습니다. 이 언어는 복잡하기 때문에, 간단하게 하기 위해 여러분의 코드는 c++98 표준을 준수할 것입니다.

우리는 현대의 C++가 많은 측면에서 매우 다르다는 것을 알고 있습니다. 따라서 여러분이 숙련된 C++ 개발자가 되고 싶다면, 42 Common Core 이후에도 더 나아가야 할 것입니다!

여러분은 새로운 개념을 단계별로 배우게 될 것입니다. 연습문제는 점진적으로 복잡해질 것입니다.

# Exercise 00: Megaphone

| CPP Module | Exercise 00 |
| --- | --- |
| Exercise 00 : 확성기 |  |
| 제출할 폴더 | ex00/ |
| 제출할 파일 | Makefile, megaphone.cpp |
| 금지된 함수 | None |

모두가 잠에서 깨어날 수 있도록, 다음과 같이 동작하는 프로그램을 작성하세요:

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

# Exercise 01: My Awesome Phonebook

| CPP Module | Exercise 01 |
| --- | --- |
| Exercise 01 : 내 짱 멋진 전화번호부 |  |
| 제출할 폴더 | ex01/ |
| 제출할 파일 | Makefile, *.cpp, *.{h, hpp} |
| 금지된 함수 | None |

믿을 수 없는 최첨단 기술력의 80년대에 오신 것을 환영합니다! `형편없이` 멋진 전화번호부처럼 동작하는 프로그램을 제작하세요.

두 개의 클래스를 구현해야 합니다:

- ***Phone Book***
    
    전화번호부
    
    - *It has an array of contacts.*
        
        연락처 배열을 가지고 있습니다.
        
    - *It can store a maximum of **8 contacts**. If the user tries to add a 9th contact, replace the oldest one by the new one.*
        
        최대 **8개의 연락처**를 저장할 수 있습니다. 사용자가 9번째 연락처를 추가하려고 하면, 가장 오래된 연락처를 새 연락처로 대체하세요.
        
    - *Please note that dynamic allocation is forbidden.*
        
        동적 할당은 금지되어 있습니다.
        
- ***Contact***
    
    연락처
    
    - *Stands for a phonebook contact.*
        
        전화번호부 연락처를 나타냅니다.
        

여러분의 코드에서, 전화번호부는 **PhoneBook** 클래스의 인스턴스로 정의되어야 합니다. 연락처도 마찬가지입니다. 각각의 연락처는 **Contact** 클래스의 인스턴스로 정의되어야 합니다. 클래스를 어떻게 구성할 지는 여러분의 자유지만, 항상 클래스 내에서 사용되는 것은 private로, 클래스 외부에서 사용되는 것은 public으로 정의되어야 한다는 것을 기억하세요.

프로그램을 시작하면, 전화번호부는 비어있고 사용자에게 세 가지 커맨드 중 하나를 입력하도록 안내합니다. 프로그램은 ADD, SEARCH, EXIT 커맨드만 허용합니다.

- `ADD`: 새연락처 저장
    - 사용자가 이 커맨드를 입력하면, 새 연락처의 정보를 한 번에 한 필드씩 입력할 수 있도록 안내합니다. 모든 필드가 완료되면, 연락처를 전화번호부에 추가하세요.
    - 연락처 필드는 다음과 같습니다: 성, 이름, 별명, 핸드폰 번호, 비밀. 저장된 연락처는 비어있는 필드를 가질 수 없습니다.
- `SEARCH`: 특정 연락처 출력
    - 저장된 연락처를 `4개의 열`로 나누어 리스트로 보여줍니다: 인덱스, 성, 이름, 별명.
    - 각 열은 `10 문자`로 너비가 정해져 있어야 합니다. 파이프 문자 ('|')가 열을 구분합니다. 텍스트는 오른쪽 정렬되어야 합니다. 텍스트가 열보다 길면, 잘리고 마지막 표시 가능 문자는 점 ('.')으로 치환되어야 합니다.
    - 그리고, 사용자에게 다시 항목을 표시할 인덱스를 입력하도록 안내하세요. 인덱스가 범위를 벗어나거나 잘못된 경우, 적절한 동작을 정의하세요. 그렇지 않으면, 연락처 정보를 한 필드당 한 줄씩 출력하세요.
- `EXIT`
    - 프로그램은 종료되고, 저장했던 연락처는 영원히 사라집니다!
- 다른 입력값은 버려집니다.

커맨드가 정상적으로 실행되면, 프로그램은 다른 커맨드를 기다립니다. 사용자가 `EXIT`를 입력하면 프로그램은 종료됩니다.

# Exercise 02: The Job Of Your Dreams

| CPP Module | Exercise 02 |
| --- | --- |
| Exercise 02 : 네가 원하는 꿈의 직장 |  |
| 제출할 폴더 | ex02/ |
| 제출할 파일 | Makefile, Account.cpp, Account.hpp, tests.cpp |
| 금지된 함수 | None |

오늘은 여러분의 `GlobalBanksters United` 출근 첫 날입니다. 여러분은 채용 시험을 통과했고 (친구가 알려준 몇 가지 `Microsoft Office` 기술 덕분에), 개발 팀에 합류했습니다. 여러분은 또한 채용 담당자가 `Adobe Reader`를 빠르게 설치한 여러분에게 감탄했다는 것을 알고 있습니다. 이 작은 장점이 모든 차이를 만들었고, 여러분의 경쟁자들 (즉, 다른 지원자들)을 물리쳤습니다: 여러분은 성공했습니다!

아무튼간에, 여러분의 매니저가 여러분에게 일을 시키기 시작했습니다. 여러분의 첫 업무는 잃어버린 파일을 다시 만드는 것입니다. 무언가 잘못되었고, 소스 파일이 실수로 삭제되었습니다. 불행히도, 여러분의 동료들은 git이 무엇인지 모르고, 코드를 공유하기 위해 USB를 사용합니다. 이 시점에서는 이곳을 떠나는 것이 합리적일 것입니다. 하지만, 여러분은 여기에 남기로 합니다. 도전 수락!

여러분의 동료 개발자들은 여러분에게 파일을 줍니다. tests.cpp를 컴파일하면, 누락된 파일이 Account.cpp임을 알 수 있습니다. 다행히도, 헤더 파일 Account.hpp는 남아있습니다. 또한 로그 파일도 있습니다. 아마도 Account 클래스가 어떻게 구현되었는지 이해하는 데에 사용할 수 있을 것입니다.

Account.cpp 파일을 다시 만들기 시작합니다. 단 몇 분 만에, 여러분은 순수하고 아름다운 C++ 코드 몇 줄을 작성합니다. 몇 번의 컴파일 실패 끝에, 여러분의 프로그램은 테스트를 통과합니다. 출력값은 로그 파일에 저장된 출력값과 완벽하게 일치합니다 (당연히 타임스탬프는 다를 것입니다. 로그 파일에 저장된 테스트는 여러분이 입사하기 전에 실행되었기 때문에).

> ℹ️
> 
> 
> ### *The order in which the destructors are called may differ depending on your compiler/operating system. So your destructors may be called in a reverse order.*
> 
> 소멸자가 호출되는 순서는 컴파일러/운영체제에 따라 다를 수 있습니다. 따라서 여러분의 소멸자는 역순으로 호출될 수 있습니다.
> 

> ℹ️
> 
> 
> ### *You can pass this module without doing exercise 02.*
> 
> 연습문제 02를 하지 않고도 이 모듈을 통과할 수 있습니다.
>