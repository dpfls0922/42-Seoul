# **C++ - Module 02**

임시 다형성, 연산자 오버로딩과 정통적인 캐노니컬 클래스

요약: 이 문서는 C++ 모듈의 02번째 모듈 서브젝트를 담고 있습니다.

## Bonus rules

- 지금부터, 여러분이 작성하는 모든 클래스는 **반드시** 정통적인 캐노니컬 폼으로 작성되어야 합니다: 최소한 하나의 기본 생성자, 복사 생성자, 대입 연산자 오버로딩과 소멸자를 포함해야 한다는 의미이죠. 다시 언급하지 않을 것이니 꼭 기억해 두세요.

## Exercise 00: My First Orthodox Class

| CPP Module | Exercise 00 |
| --- | --- |
| Exercise 00 : 내 첫 번째 정통 클래스 |  |
| 제출할 폴더 | ex00/ |
| 제출할 파일 | Makefile, main.cpp, Fixed.hpp and Fixed.cpp |
| 금지된 함수 | None |

여러분은 이미 정수형과 부동 소수점 자료형에 대해 알고 계시죠. 귀여워라.

다음의 세 페이지 문서를 읽어 보시고 ([1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html), [3](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)) 여러분이 사실 이것들에 대해 아무것도 모른다는 것을 깨닫길 바래요. 어서 읽어 보시죠.

여태까지 여러분이 사용하던 모든 숫자는 정수형이나 부동 소수점 수, 또는 그것들의 변종들 (`short, char, long, double` 등등...) 이었어요. 앞서 읽은 문서에 따르면, 정수와 부동 소수점 수는 서로 반대되는 특성을 가지고 있다고 가정해도 무방합니다.

다만 지금부턴 그 생각을 바꿔볼 거에요. 여러분은 '고정 소수점 수' 라는 새롭고 놀라운 수 자료형을 배울 것이랍니다! 대부분의 프로그래밍 언어의 스칼라 데이터 타입에서 누락되어 있는 고정 소수점 수는 성능과 정확도, 범위와 정밀도 간의 가치 있는 균형을 제공하며, 왜 이러한 숫자가 그래픽, 음악 또는 과학적 프로그래밍 영역 등지에서 폭 넓게 사용되는 지 아실 수 있을 겁니다.

다만 `C++`이 고정 소수점 수에 대한 지원이 약하기 때문에, 여러분이 직접 고정 소수점에 대한 부분을 추가하셔야 해요. 시작하기 전에 `버클리` 대학에서 작성된 [이](http://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) 문서를 읽어보는 것을 추천드립니다. `버클리` 대학이 뭐 하는 곳인지 감이 안 잡히신다면, 위키피디아의 [이](https://en.wikipedia.org/wiki/University_of_California,_Berkeley#Notable_alumni.2C_faculty.2C_and_staff) 문서를 한번 참고해 보시죠.

고정 소수점 수를 표현하는 정통 클래스를 다음과 같이 작성하세요:

- Private 멤버들:
    - 고정 소수점 값을 저장할 정수형 변수.
    - 분수 비트의 수를 저장하는 정적 정수형 상수. 이 상수는 항상 8의 값을 갖습니다.
- Public 멤버들:
    - 고정 소수점 값을 0으로 초기화해 줄 기본 생성자.
    - 소멸자.
    - 생성자 복사본.
    - 대입 연산자 오버로딩.
    - 고정 소수점 값 원본을 반환하는 멤버 함수 `int getRawBits( void ) const;`
    - 고정 소수점 값 원본을 설정하는 멤버 함수 `void setRawBits( int const raw );`

다음의 코드는:

```cpp
#include <iostream>
int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}
```

다음과 같은 결과를 출력해야 합니다:

```
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

## Exercise 01: Towards a more useful fixed point class

| CPP Module | Exercise 01 |
| --- | --- |
| Exercise 01 : 조금 더 쓸 만한 고정 소수점 클래스를 향하여 |  |
| 제출할 폴더 | ex01/ |
| 제출할 파일 | Makefile, main.cpp, Fixed.hpp and Fixed.cpp |
| 허용되는 함수 | roundf (from <cmath>) |

좋아요, `ex00`은 꽤 좋은 시작이었어요. 다만 우리가 만든 클래스는 고정 소수점 값 `0.0`만 표시할 수 있다는 점에서 아직 쓸모가 없는 것 같네요. 다음과 같은 Public 생성자와 Public 멤버 함수들을 클래스에 추가해 보세요:

- 매개 변수로 정수형 상수를 받아와 이를 대응되는 고정 (8) 소수점 값으로 변환하는 생성자. 분수 비트 값은 `ex00` 때와 같이 초기화됩니다.
- **매개 변수로 부동 소수점 상수를 받아와 이를 대응되는 고정 (8) 소수점 값으로 변환하는 생성자. 분수 비트 값은 `ex00` 때와 같이 초기화됩니다.
- 고정 소수점 값을 부동 소수점 값으로 변환하는 멤버 함수 `float toFloat( void ) const;`
- 고정 소수점 값을 정수 값으로 변환하는 멤버 함수 `int toInt( void ) const;`

여러분은 다음과 같은 함수 오버로딩을 헤더 (선언) 와 소스 파일 (정의) 에 추가하여야 합니다:

- 매개변수의 출력 스트림에 고정 소수점 값의 부동 소수점 표현을 삽입하는 « 연산자 오버로딩

다음의 코드는:

```
#include <iostream>int main( void ) {
  Fixed a;
  Fixed const b( 10 );
  Fixed const c( 42.42f );
  Fixed const d( b );

  a = Fixed( 1234.4321f );

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  return 0;
}
```

다음과 같은 결과를 출력해야 합니다:

```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Assignation operator called
Float constructor called
Assignation operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

## Exercise 02: Now we’re talking

| CPP Module | Exercise 02 |
| --- | --- |
| Exercise 02 : 이제 대화를 나눕시다 |  |
| 제출할 폴더 | ex02/ |
| 제출할 파일 | Makefile, main.cpp, Fixed.hpp and Fixed.cpp |
| 허용되는 함수 | roundf (from <cmath>) |

거의 다 와 갑니다! 다음과 같은 Public 멤버 연산자 오버로딩을 클래스에 추가하세요:

- 여섯 개의 비교 연산자: `>, <, >=, <=, ==` 그리고 `!=`.
- 네 개의 산술 연산자: `+, -, *,` 그리고 `/`.

고정 소수점 값을 1 + ε > 1와 같은 가장 작은 표현법 ε로부터 증가 또는 감소시키는 전위 증가 연산자, 후위 증가 연산자, 전위 감소 연산자, 후위 감소 연산자.

다음과 같은 Public 정적 멤버 함수 오버로딩을 클래스에 추가하세요:

- 두 개의 고정 소수점 값 참조를 받아 가장 작은 값의 참조를 반환하는 정적 멤버 함수 `min`과, 두 개의 고정 소수점 상수 값의 참조를 받아 가장 작은 상수 값의 참조를 반환하는 오버로딩
- 두 개의 고정 소수점 값 참조를 받아 가장 큰 값의 참조를 반환하는 정적 멤버 함수 `max`와, 두 개의 고정 소수점 상수 값의 참조를 받아 가장 큰 상수 값의 참조를 반환하는 오버로딩

여러분의 클래스의 기능들을 테스트하는 것은 여러분에게 달려있지만, 다음과 같은 짧은 코드

```
#include <iostream>int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max( a, b ) << std::endl;

  return 0;
}
```

는 다음과 같은 결과값을 출력하여야 합니다 (ctors/dtor 로그는 지웠습니다):

```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

## Exercise 03: BSP

| CPP Module | Exercise 03 |
| --- | --- |
| Exercise 03 : BSP |  |
| 제출할 폴더 | ex03/ |
| 제출할 파일 | Makefile, main.cpp, Fixed.hpp, Fixed.cpp, Point.hpp, Point.cpp, and bsp.cpp |
| 허용되는 함수 | roundf (from <cmath>) |

> ⚠️
> 
> 
> ### *This exercise is not required to validate this module.*
> 
> 이 과제는 이번 모듈을 끝내는 데에 필수적이지 않습니다
> 

이제 여러분은 완전히 동작하는 고정 소수점 클래스를 완성했습니다. 이제 유용한 곳에 적절히 사용하면 더 멋지겠죠? 여러분은 지금부터 특정 좌표가 삼각형 안에 들어있는지 아닌지 판단하는 함수를 구현해 볼 것입니다. 정말 쓸모있네요, 그쵸?

> 💡
> 
> 
> ### *BSP stands for Binary space partitioning. You are welcome :)*
> 
> BSP는 Binary Space Partitioning (이진 공간 분할법) 입니다. 천만에요 :)
> 

2D 좌표를 표현하는 정통적인 클래스 `Point`를 작성하는 것부터 시작해 봅시다:

- Private 멤버:
    - *A `Fixed const`*
    - *A `Fixed const y`*
    - 여러분이 생각하기에 유용한 것들.
- Public 멤버:
    - `x`와 `y`를 0으로 초기화하는 기본 생성자.
    - 소멸자.
    - 생성자 복사본.
    - 두 부동 소수점 상수 값을 매개변수로 받아 `x`와 `y`를 초기화하는 생성자.
    - 할당 연산자 오버로딩.
    - 여러분이 생각하기에 유용한 것들.

지금부터 함수 bsp를 작성하셔야 합니다:

- 처음 세 개의 매개변수는 우리의 사랑스러운 삼각형의 정점입니다.
- 네 번째 매개변수는 우리가 판단에 사용할 좌표입니다.
- 만약 좌표가 삼각형 안에 포함되어 있을 경우 `True`를 반환하며, 그 외에는 `False`를 반환합니다. 이 말인즉슨 좌표가 꼭지점이거나 모서리에 있을 경우도 `False`를 반환해야 한다는 의미입니다.
- 결국, 함수의 프로토타입은 다음과 같아야 합니다:

```
bool bsp( Point const a, Point const b, Point const c, Point const point);
```

여러분의 클래스가 의도대로 동작하는 것을 보여주기 위해 main문을 함께 제출하는 것을 잊지 마세요.