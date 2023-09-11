# Push Swap

이번 과제에서는 스택에 있는 데이터를 한정된 명령어를 이용하여 최대한 적은 횟수 내에 정렬하는 것을 목표로 합니다. 성공하기 위해서는 다양한 정렬 알고리즘을 조작해 보고, 최적화된 데이터 정렬에 가장 적합한 알고리즘을 선택하여야 합니다.

<br>


# **Chapter 1**

## Foreword

- `C`

  ```c
  #include <stdio.h>

  int main(void)
  {
  		printf("hello, world\n");
  		return 0;
  }
  ```

- `ASM`

  ```as
  cseg segment
  assume cs:cseg, ds:cseg
  org 100h
  main proc
  jmp debut
  mess db 'Hello world!$'
  debut:
  mov dx, offset mess
  mov ah, 9
  int 21h
  ret
  main endp
  cseg ends
  end main
  ```

- `LOLCODE`

  ```lolcode
  HAI
  CAN HAS STDIO?
  VISIBLE "HELLO WORLD!"
  KTHXBYE
  ```

- `PHP`

  ```php
  <?php
    echo "Hello world!";
  ?>
  ```

- `BrainFuck`

  ```BrainFuck
  ++++++++++[>+++++++>++++++++++>+++>+<<<<-]
  >++.>+.+++++++..+++.>++.
  <<+++++++++++++++.>.+++.------.--------.>+.>.
  ```

- `C#`

  ```c#
  using System;

  public class HelloWorld {
  	public static void Main () {
  			Console.WriteLine("Hello world!");
  	}
  }
  ```

- `HTML5`

  ```html
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8">
      <title>Hello world !</title>
    </head>
    <body>
      <p>Hello World !</p>
    </body>
  </html>
  ```

- `YASL`

  ```yasl
  "Hello world!"
  print
  ```

- `OCaml`

  ```ocaml
  let main () =
	print_endline "Hello world !"

  let _ = main ()
  ```

<br>

# **Chapter 2**

## Introduction

##### _The `Push_swap` project is a very simple and highly straightforward algorithm project: data must be sorted._ 

`Push_swap` 프로젝트는 아주 간단하고 꽤나 중요한 알고리즘 프로젝트입니다. 이 프로젝트에서는 데이터를 정렬하여야 합니다.

#### _You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks._

과제에서는 정렬해야 하는 int 값들과 두 개의 스택, 그리고 이 스택을 조작하는 명령어 집합이 주어집니다.

##### _Your goal? Write a program in `C` called `push_swap` which calculates and displays on the standard output the smallest program, made of `Push_swap language` instructions, that sorts the integers as received._

여러분의 목표는 `C`언어로 `Push_swap`이라는 프로그램을 작성하시는 겁니다. `Push_swap` 프로그램은 최소한의 `Push_swap 명령어`를 이용하여 정수형 인자를 정렬하는 방법을 계산하고, 최종적으로 사용된 명령어들을 표준 출력해야 합니다.

##### _Easy?_

쉬워보이죠?

##### _We’ll see about that..._

두고보세요...

<br>

# **Chapter 3**

## Objectives

##### _Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)._

정렬 알고리즘을 작성하는 것은 개발자의 여정에서도 꽤나 중요한 비중을 차지하는 부분입니다. 대개 [**복잡도**](https://en.wikipedia.org/wiki/Analysis_of_algorithms)의 개념을 여기서 처음 마주하게 되거든요.

##### _Sorting algorithms and their complexities are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts because you’ll have to face them at one point._

정렬 알고리즘과 복잡도는 기업 면접에서 자주 질문하는 문항이기도 합니다. 언젠가는 마주할 내용이기 때문에, 이번 기회에 개념을 잘 다지는 것도 좋은 방법이겠지요.

##### _The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity._

이번 과제의 목표는 엄격함, C언어의 사용과 기본적인 알고리즘의 사용입니다. 특히 복잡도에 대해 면밀히 살펴보세요.

##### _Sorting values is simple. To sort them the fastest way possible is less simple, especially because from one integers configuration to another, the most efficient sorting algorithm can differ._

값을 정렬하는 건 꽤나 간단합니다만, 가능한 한 빠르게 정렬하는 것은 조금 복잡합니다. 어떤 정수 집합을 정렬하는지에 따라 최적의 알고리즘이 달라지거든요.

<br>


<br>

# **Chapter 5**

## Mandatory part

## 5.1 The rules

- ##### _You have 2 [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) named a and b._

	[스택](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) a와 b가 있습니다.

- ##### _At the beginning:_

	시작 지점에서:

	- ##### _The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated._

		스택 a는 랜덤한 개수의 양의 정수들과 음의정수들을 포함하며, 값은 중복되지 않습니다.

	- ##### _The stack b is empty._

		스택 b는 비어있습니다.

- ##### _The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:_

	스택 a에 정수들을 오름차순으로 정령하는 것이 목표입니다. 다음과 같은 명령어를 사용할 수 있습니다:

	- ##### _**sa** : (`swap a`) - Swap the first 2 elements at the top of stack a.<br/>Do nothing if there is only one or no elements._

		**sa** : (`swap a`) - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다.<br/>스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.

	- ##### _**sb** : (`swap b`) - Swap the first 2 elements at the top of stack b.<br/>Do nothing if there is only one or no elements._

		**sb** : (`swap b`) - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다.<br/>스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.

	- ##### _**ss** : `sa` and `sb` at the same time._

		**ss** : `sa`와 `sb`를 동시에 수행합니다.

	- ##### _**pa** : (`push a`) - Take the first element at the top of b and put it at the top of a.<br/>Do nothing if b is empty._

		**pa** : (`push a`) - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다.<br/>스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.

	- ##### _**pb** : (`push b`)- Take the first element at the top of a and put it at the top of b.<br/>Do nothing if a is empty._

		**pb** : (`push b`) - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다.<br/>스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.

	- ##### _**ra** : (`rotate a`) - Shift up all elements of stack a by 1.<br/>The first element becomes the last one._

		**ra** : (`rotate a`) - 스택 a의 원소를 한 칸씩 위로 옮깁니다.<br/>스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.

  	- ##### _**rb** : (`rotate b`)- Shift up all elements of stack b by 1.<br/>The first element becomes the last one._

		**rb** : (`rotate b`) - 스택 b의 원소를 한 칸씩 위로 옮깁니다.<br/>스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.

	- ##### _**rr** : `ra` and `rb` at the same time._

		**rr** : `ra`와 `rb`를 동시에 수행합니다.

	- ##### _**rra** : (`reverse rotate a`) - Shift down all elements of stack a by 1.<br/>The last element becomes the first one._

		**rra** : (`reverse rotate a`) - 스택 a의 원소를 한 칸씩 아래로 옮깁니다.<br/>스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.

	- ##### _**rrb** : (`reverse rotate b`) - Shift down all elements of stack b by 1.<br/>The last element becomes the first one._

		**rrb** : (`reverse rotate b`) - 스택 b의 원소를 한 칸씩 아래로 옮깁니다.<br/>스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.

	- ##### _rrr : `rra` and `rrb` at the same time._

		**rrr** : `rra`와 `rrb`를 동시에 수행합니다.

<br>

## 5.2 Example

##### _To illustrate the effect of some of these instructions, let’s sort a random list of integers.<br>In this example, we’ll consider that both stack are growing from the right._

이 명령어들의 수행 결과를 자세히 알아보기 위해, 랜덤한 정수 배열을 정렬해 보겠습니다.<br>이번 예시에서는, 두 스택 a, b 모두 오른쪽으로 크기가 증가한다고 가정합시다.

```
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```

##### _Inteagers from a get sorted in 12 instructions. Can you do better?_

스택 a의 정수들을 12개의 명령어로 정렬합니다. 더 빠르게 정렬할 수 있으시겠어요?

<br>

## 5.3 The “push_swap” program

| **Program name** |push_swap|
|---|---|
| **Turn in files** | Makefile, *.h, *.c |
| **Makefile** | NAME, all, clean, fclean, re |
| **Arguments** | stack a: A list of integers |
| **External functs.** | • read, write, malloc, free, exit<br/> • ft_printf and ny equivalent YOU coded |
| **Libft authorized** | Yes |
| **Description** | Sort stacks |

##### _Your project must comply with the following rules:_

 프로젝트는 위 규칙들을 따라야 합니다:

- ##### _You have to turn in a `Makefile` which will compile your source files. It must not relink._

	모든 소스 파일들을 컴파일 하는 `Makefile`을 제출해야합니다. 리링크가 되면 안됩니다.

- ##### _Global variables are forbidden._

	전역 변수는 금지됩니다.

- ##### _You have to write a program named `push_swap` that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order)._

	여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `push_swap` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위에 와야 합니다(순서에 주의하세요).

- ##### _The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top._

  프로그램은 스택 a를 작은 숫자가 스택의 top에 오도록 순서대로 정렬하기 위해 가능한 한 적은 개수의 명령어를 사용해야 하고, 사용한 명령어의 목록을 마지막에 출력하여야 합니다.

- ##### _Instructions must be separaed by a ’\n’ and nothing else._

  명령어는 '\n'으로만 구분되어 출력되어야 합니다.

- ##### _The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either dispalys a longer list of or if the numbers aren't sorted properly, your grade will be 0._

	목표는 스택을 가능한 적은 개수의 명령어로 정렬하는 것입니다. 동료평가 시에는 명령어의 개수와 용인되는 최대 명령어의 개수를 비교할 것입니다. 프로그램에서 출력한 명령어의 수가 최대 개수를 넘어서거나 제대로 정렬되지 않았을 경우, 점수를 받을 수 없습니다.

- ##### _If no parameters are specified, the program must not display anything and give the prompt back._

	매개 변수가 지정되지 않은 경우, 프로그램은 아무것도 표시하지 않고 프롬프트를 반환해야 합니다.

- ##### _In case of error, you must display `"Error"` followed by a `'\n'` on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates._

  오류가 발생했을 경우에는, 표준 출력으로 `"Error"`와 줄바꿈 문자 `'\n'` 를 출력하여야 합니다. 오류의 예시로는 특정 인자값이 정수가 아니거나, 정수보다 큰 인자값이 들어오거나, 중복된 인자가 들어오는 경우가 있습니다.

```sh
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

##### _During the evaluation process, a binary will be provided in order to properly check your program._

 평가 과정에서 프로그램을 올바르게 확인하기 위해 바이너리가 제공될 것입니다.

#### _It will work as follows:_
 이 프로그램은 다음과 같이 사용할 수 있습니다 :

```sh
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```

##### _If the program `checker_OS` displays `"KO"`, it means that your `push_swap` came up with a list of instructions that doesn’t sort the numbers._

 `checker_OS` 프로그램이 `"KO"`를 출력했다면, 여러분의 `push_swap`이 출력한 명령어 리스트가 정수 배열 정렬에 실패하였다는 의미입니다. 

> ℹ️ <br>
>
> ##### _The `checker_OS` program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works._
>
> `checker_OS` 프로그램은 인트라에서 다운로드 받으실 수 있으며, 어떻게 동작하는지는 과제의 보너스 섹션에서 알아보실 수 있습니다.
>


<br>

# **Chapter 6**

## Bonus part

##### _This project leaves little room for adding extra features due to simplicity. However, how about creating your own checker?_

 이 프로젝트는 너무 단순하기 때문에 기능을 추가하기가 쉽지 않습니다. 그럼, 여러분만의 체커를 만드는 것 어떨까요?

> ℹ️ <br>
>
> ##### _Thanks to the checker program, you will be able to check wheter the list of instructions generated by the push_swap program actually srots the stack properly._
>
> 체커 프로그램 덕에, 여러분의 `push_swap` 프로그램이 출력한 명령어 목록이 정상적으로 스택을 정렬하는지 쉽게 검사할 수 있습니다.
>

<br>

## 6.1 The "Checker" Program

| Program name | checker |
| --- | --- |
| Turn in files | *.h, *.c |
| Makefile | bonus |
| Arguments | stack a : A lsit of inteagers |
| External functs. | • read, write, malloc, free, exit <br/> • ft_printf and any equivalent YOU coded |
| Libft authorized | Yes |
| Description | Execute the sorting instructions |

- ##### _Write a program named `checker` that takes get as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing._

  여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `checker` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위 (top) 에 와야 합니다. (순서에 주의하세요)

- ##### _It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument._

  `checker`를 실행시키면 표준 입력으로 명령어가 들어올 때까지 대기 상태가 됩니다. 명령어는 줄옮김 '\n'으로 구분되어 들어와야 하며, 모든 명령어가 들어왔을 경우 `checker`는 명령어와 입력받은 정수 스택을 이용하여 정렬을 시작합니다.

- ##### _If after executing those instructions, stack `a` is actually sorted and the stack `b` is empty, then the program must display "`OK`" followed by a ’\n’ on the standard output._

  명령어 입력이 끝난 뒤 `checker`가 스택을 정렬하였을 때, 스택 `a`는 제대로 정렬되어 있고 스택 `b`는 비어있을 경우, `checker`는 "`OK`"를 '\n'과 함께 표준 출력하여야 합니다.

- ##### _In every other case, `checker` must display "`KO`" followed by a ’\n’ on the standard output._

  그 외의 경우, `checker`는 "`KO`"를 '\n'과 함께 출력하여야 합니다.

- ##### _In case of error, you must display `Error` followed by a ’\n’ on the `standard error`. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted._

  오류가 발생했을 경우에는, 표준 출력으로 `Error`와 줄바꿈 문자 (\n) 를 출력하여야 합니다. 오류의 예시로는 특정 인자값이 정수가 아니거나, 정수보다 큰 인자값이 들어오거나, 중복된 인자가 들어오거나, 존재하지 않는 명령어를 입력받았거나, 입력 포맷이 잘못되었을 때 등이 있습니다.


```sh
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
$>
```

> ⚠️ <br>
>
> ##### _You DO NOT have to reproduce the exact same behavior as the binary we are giving to you. It is mandatory to manage the errors but it is up to you how you decide to parse the arguments._
>
> 제공되는 Checker 파일과 완벽하게 똑같은 동작을 할 필요는 없습니다. 오류 처리는 필수이지만, 인자값을 어떻게 파싱하여 읽어들일지는 여러분의 자유입니다.

> ⚠️ <br>
>
>##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
>
> 보너스는 필수로 구현해야 하는 파트가 **완벽할 때**만 평가될 것입니다. '완벽함' 이란, 모든 필수 파트가 전부 구현되어 있어야 하며 오작동하는 부분이 없어야 함을 의미합니다. 필수로 구현해야 하는 파트에서 **만점**을 받지 못한다면, 보너스 항목은 채점되지 않습니다.
>

<br>

# Chapter 7

## Submission and peer correction

##### _Turn in your assignment in your `Git` repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your files to ensure they are correct._
 
 항상 그래왔듯, 여러분의 결과물을 `Git` 레포지토리에 제출하세요. 레포지토리에 있는 과제물만이 평가될 것입니다. 파일 이름이 올바른지 확인하려면 꼭 한번 더 확인하세요.


##### _As these assignments are not verified by a program, feel free to organize your files as you wishs, as long as you turn in the mandatory files and comply with the requirements._

 이러한 과제는 프로그램으로 확인되지 않으므로 필수 파일을 제출하고 요구 사항을 준수한다면 원하는대로 파일을 구성하십시오.

##### _Good luck to all!_

행운을 빌어요!