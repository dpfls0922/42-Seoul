# **C++ - Module 01**

메모리 할당, 멤버 포인터, 참조, switch 문

요약: 이 문서는 C++ 모듈의 01번째 모듈 서브젝트를 담고 있습니다.

# **Introduction**

C++은 Bjarne Stroustrup이 C 프로그래밍 언어를 확장한 범용 프로그래밍 언어입니다. "C with Classes"라고도 불립니다.

이 모듈의 목표는 여러분을 **객체 지향 프로그래밍**에 소개하는 것입니다. 이것이 여러분의 C++ 여행의 시작점이 될 것입니다. 많은 언어들이 OOP를 배우기에 적합하다고 추천합니다. 우리는 여러분의 친구인 C에서 파생된 C++를 선택했습니다. 이 언어는 복잡하기 때문에, 간단하게 하기 위해 여러분의 코드는 c++98 표준을 준수할 것입니다.

우리는 현대의 C++가 많은 측면에서 매우 다르다는 것을 알고 있습니다. 따라서 여러분이 숙련된 C++ 개발자가 되고 싶다면, 42 Common Core 이후에도 더 나아가야 할 것입니다!

여러분은 새로운 개념을 단계별로 배우게 될 것입니다. 연습문제는 점진적으로 복잡해질 것입니다.

## Exercise 00: BraiiiiiiinnnzzzZ

| CPP Module | Exercise 00 |
| --- | --- |
| Exercise 00 : 뇌ㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣ |  |
| 제출할 폴더 | ex00/ |
| 제출할 파일 | Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,  newZombie.cpp, randomChump.cpp |
| 금지된 함수 | None |

먼저, `Zombie` 클래스를 만드세요. 이 클래스는 private한 속성인 이름을 가져야 합니다

Zombie 클래스에 `void announce( void )` 멤버 함수를 추가하세요. 좀비는 다음과 같이 스스로를 소개합니다:

```
<name> BraiiiiiiinnnzzzZ...
```

꺽쇠 괄호 (<와 >)는 출력하지 마세요. 이름이 Foo인 좀비의 메시지는 다음과 같아야 합니다:

```
Foo : BraiiiiiiinnnzzzZ...
```

그 다음, 다음 두 함수를 구현하세요:

- *`Zombie* newZombie( std::string name )`*
    
    이 함수는 좀비를 생성하고, 이름을 지정하고, 반환하여 함수 범위 밖에서 사용할 수 있도록 합니다.
    
- *`void randomChump( std::string name )`*
    
    이 함수는 좀비를 생성하고, 이름을 지정하고, 좀비가 스스로를 소개하도록 합니다
    

이번 과제의 요점이 무엇일까요? 좀비를 스택에 할당하는 것이 좋은지, 힙에 할당하는 것이 좋은지 판단해야 합니다.

좀비는 더 이상 필요하지 않을 때 소멸해야 합니다. 디버깅을 위해 소멸자는 좀비의 이름을 포함한 메시지를 출력해야 합니다.

## Exercise 01: Moar brainz!

| CPP Module | Exercise 01 |
| --- | --- |
| Exercise 01 : 더 만은 뇌들! |  |
| 제출할 폴더 | ex01/ |
| 제출할 파일 | Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, ZombieHorde.cpp |
| 금지된 함수 | None |

`hord of Zombies`를 만드는 시간입니다!

다음 함수를 적절한 파일에 구현하세요:

### *`Zombie*	zombieHorde( int N, std::string name )`*

이 함수는 N마리의 좀비 객체를 한 번에 할당해야 합니다. 그리고, 각각의 좀비들에게 인자로 전달된 이름을 부여하면서 초기화해야 합니다. 이 함수는 첫 번째 좀비의 포인터를 반환해야 합니다.

여러분의 `zombieHorde()` 함수가 예상대로 동작하는 지 확인하기 위해 테스트를 직접 작성하세요. 각 좀비들에게 `announce()` 함수를 호출해보세요.

모든 좀비들을 `delete`하고 `메모리 누수`를 확인하는 것을 잊지 마세요.

## Exercise 02: HI THIS IS BRAIN

| CPP Module | Exercise 02 |
| --- | --- |
| Exercise 02: 안뇽 나는 뇌야 |  |
| 제출할 폴더 | ex02/ |
| 제출할 파일 | Makefile, main.cpp |
| 금지된 함수 | None |

다음을 포함하는 프로그램을 작성하세요:

- `"HI THIS IS BRAIN"`으로 초기화된 문자열 변수
- `stringPTR`: 문자열을 가리키는 포인터
- `stringREF`: 문자열을 참조하는 참조자

  
프로그램은 다음을 출력해야 합니다:
- 문자열 변수의 메모리 주소
- `stringPTR`이 가리키는 메모리 주소
- `stringREF`가 가리키는 메모리 주소

그리고:
- 문자열 변수의 값
- `stringPTR`이 가리키는 값
- `stringREF`가 가리키는 값

이게 끝이에요. 별 거 없어요. 이 과제의 최종 목표는 완전히 새로운 것 처럼 보이는 '참조' 개념에 대해 이해하는 것입니다. 아주 작고 사소하고 미세한 차이점이 있을지라도요. 이미 알고 있는 개념을 다르게 표현하는 것 뿐이죠 : 주소 조작 말이에요.

## Exercise 03: Unnecessary violence

| CPP Module | Exercise 03 |
| --- | --- |
| Exercise 03: 불필요한 폭력 |  |
| 제출할 폴더 | ex03/ |
| 제출할 파일 | Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp |
| 금지된 함수 | None |

다음을 포함하는 Weapon 클래스를 구현하세요:

- 문자열인 private 속성 `type`
- `type`의 상수 참조를 반환하는 `getType()` 멤버 함수
- 매개변수로 전달된 새로운 `type`을 사용하여 `type`을 설정하는 `setType()` 멤버 함수

이제, 두 개의 클래스를 만드세요

`HumanA`와 `HumanB`.

두 클래스 모두 `Weapon`과 `name`을 지니고 있어야 합니다. 또한, 다음과 같은 문자열을 출력하는 `attack()` 멤버 함수를 포함해야 합니다:

```
<name> attacks with their <weapon type>
```

`HumanA`와 `HumanB`는 거의 비슷하지만, 두 가지 미세한 차이점이 있습니다:

- `HumanA`는 생성자에서 `Weapon`을 지니지만, `HumanB`는 그렇지 않습니다.
- `HumanB`는 항상 무장한 상태가 아닐 수도 있지만, `HumanA`는 **항상** 무장한 상태입니다.

여러분의 구현이 올바르다면, 다음 코드를 실행하면 두 가지 테스트 케이스 모두 "crude spiked club"과 "some other type of club"으로 공격할 수 있습니다.

```
int main()
{
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
}
```

`메모리 누수`를 확인하는 것을 잊지 마세요.

> 💡
> 
> 
> 어떤 경우에 `Weapon`을 가리키는 포인터를 사용하는 것이 좋을까요? 그리고 `Weapon`을 참조하는 것이 좋을까요? 이유는 무엇일까요? 이 과제를 시작하기 전에 생각해보세요.
> 

## Exercise 04: Sed is for losers

| CPP Module | Exercise 04 |
| --- | --- |
| Exercise 04: sed는 패배자들이나 쓰는 것 |  |
| 제출할 폴더 | ex04/ |
| 제출할 파일 | `Makefile, main.cpp, *.cpp, *.{h, hpp} |
| 금지된 함수 | std::string::replace |

다음 순서대로 세 개의 인자를 받는 프로그램을 작성하세요: 파일명과 두 개의 문자열, s1과 s2입니다.

프로그램은 `<filename>` 파일을 열고, 파일 내용을 `<filename>.replace`라는 새 파일에 복사합니다. 이때, 모든 `s1`을 `s2`로 대체합니다.

C 파일 관리 함수들을 사용하는 것은 금지되어 있으며, 치팅으로 간주됩니다. replace를 제외한 모든 std::string 클래스의 멤버 함수들을 사용할 수 있습니다. 현명하게 사용하세요!

당연히, 예상치 못한 입력과 에러를 처리해야 합니다. 프로그램이 예상대로 동작하는지 확인하기 위해 여러분만의 테스트를 작성하고 제출해야 합니다.

## Exercise 05: Harl 2.0

| CPP Module | Exercise 05 |
| --- | --- |
| Exercise 05: 할 2.0 |  |
| 제출할 폴더 | ex05/ |
| 제출할 파일 | Makefile, main.cpp, Harl.{h, hpp}, and Harl.cpp |
| 금지된 함수 | None |

할을 아시나요? 다 아시죠? 아닌가요? 모르실 때를 대비해서, 할이 주로 할 법한 대사를 몇 자 적어보겠습니다. 이 대사들은 레벨에 따라 분류됩니다:

- `"DEBUG"` 레벨: 디버그 메시지는 상황별 정보를 포함합니다. 문제 진단에 사용됩니다.
    
    예시: "나는 패티 7장이랑 피클 3개 추가한 더블 쿼터 파운더 치즈 버거에 베이컨 서비스 받는 게 너무 좋아. 너무 맛있엉!"
    
- `"INFO"` 레벨: 이 메시지들은 광범위한 정보를 포함합니다. 운영 환경에서의 프로그램 실행을 추적하는 데 도움이 됩니다.
    
    예시: "햄버거에 베이컨을 추가하는 데 추가금이 든다니, 믿을 수 없어! 쥐꼬리만큼 넣어주잖아! 이딴 식이면 추가해달라고 하지도 않았겠지!"
    
- `"WARNING"` 레벨: 경고 메시지는 시스템에서 발생가능한 문제를 알려줍니다. 그러나, 이러한 문제들은 스스로 해결하거나 무시할 수 있습니다.
    
    예시: "솔직히 난 베이컨을 무료로 추가 받을 자격이 있다고 생각해. 난 여기 몇 년째 단골손님이지만, 당신은 저번 달부터 근무한 초짜잖아."
    
- `"ERROR"` 레벨: 이 메시지들은 복구할 수 없는 에러가 발생했음을 알려줍니다. 이는 대개 수동 개입이 필요한 심각한 문제입니다.
    
    예시: "몰라, 난 용납 못해. 매니저 부를거야."
    

이제, 우리는 할을 자동화해 볼 겁니다. 그녀는 항상 똑같은 말만 반복하죠. `Harl` 이라는 이름의 클래스를 만들고, 다음과 같은 private 멤버 함수를 만드세요:

- *`void debug( void );`*
- *`void info( void );`*
- *`void warning( void );`*
- *`void error( void );`*

`Harl`에는 레벨에 따라 위의 네 멤버 함수를 호출하는 public 멤버 함수가 있습니다:

- *`void complain( std::string level );`*

이번 과제의 목표는 `멤버 함수 포인터`를 사용하는 것입니다. 이는 제안이 아닙니다. 할은 if/else if/else의 무리를 사용하지 않고도 불평을 해야 합니다. 그녀는 두 번 생각하지 않아요!

할이 많이 불평하는 것을 보여주는 테스트를 작성하고 제출하세요. 과제에서 제시한 예시 대사을 사용하거나, 여러분만의 대사을 사용할 수 있습니다.

## Exercise 06: Harl filter

| CPP Module | Exercise 06 |
| --- | --- |
| Exercise 06: 할 필터 |  |
| 제출할 폴더 | ex06/ |
| 제출할 파일 | Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp |
| 금지된 함수 | None |

할이 하는 말을 항상 신경쓰고 싶지 않을 때가 있습니다. 원하는 로그 레벨에 따라 할이 하는 말을 걸러내는 시스템을 구현해 보세요.

프로그램을 하나 만드세요. 프로그램은 네 가지 레벨 중 하나를 인자로 받습니다. 해당 레벨과 그 이상의 레벨에 해당하는 모든 메시지를 출력합니다. 예시는 다음과 같습니다:

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I’ve been coming here for years whereas you started working here since last month.

[ ERROR ]
This is unacceptable, I want to speak to the manager now.

$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

할을 다루는 방법은 여러 가지가 있지만, 가장 효과적인 방법 중 하나는 그녀의 **스위치**를 끄는 것입니다

여러분의 실행 파일의 이름을 `harlFilter`로 지정하세요.

이번 과제에서는 switch 문을 사용해야 합니다. 아마도 이번 과제에서 switch 문을 처음 사용해보실 수도 있을 겁니다.

> 💡 6번 과제를 하지 않고도 이번 모듈을 통과할 수 있습니다.
>
