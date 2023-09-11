# Push Swap

이번 과제에서는 스택에 있는 데이터를 한정된 명령어를 이용하여 최대한 적은 횟수 내에 정렬하는 것을 목표로 합니다. 성공하기 위해서는 다양한 정렬 알고리즘을 조작해 보고, 최적화된 데이터 정렬에 가장 적합한 알고리즘을 선택하여야 합니다.
과제에서는 정렬해야 하는 int 값들과 두 개의 스택, 그리고 이 스택을 조작하는 명령어 집합이 주어집니다.
`Push_swap` 프로그램은 최소한의 `Push_swap 명령어`를 이용하여 정수형 인자를 정렬하는 방법을 계산하고, 최종적으로 사용된 명령어들을 표준 출력해야 합니다.

<br>


# Foreword

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


# Mandatory part

## The rules

스택 a와 b가 있습니다.

- 시작 지점에서:

	- 스택 a는 랜덤한 개수의 양의 정수들과 음의정수들을 포함하며, 값은 중복되지 않습니다.
	- 스택 b는 비어있습니다.


- 스택 a에 정수들을 오름차순으로 정령하는 것이 목표입니다. 다음과 같은 명령어를 사용할 수 있습니다:

	- **sa** : (`swap a`) - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다.<br/>스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.

	- **sb** : (`swap b`) - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다.<br/>스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.

	- **ss** : `sa`와 `sb`를 동시에 수행합니다.

	- **pa** : (`push a`) - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다.<br/>스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.

	- **pb** : (`push b`) - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다.<br/>스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.

	- **ra** : (`rotate a`) - 스택 a의 원소를 한 칸씩 위로 옮깁니다.<br/>스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.

	- **rb** : (`rotate b`) - 스택 b의 원소를 한 칸씩 위로 옮깁니다.<br/>스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.

	- **rr** : `ra`와 `rb`를 동시에 수행합니다.

	- **rra** : (`reverse rotate a`) - 스택 a의 원소를 한 칸씩 아래로 옮깁니다.<br/>스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
  
	- **rrb** : (`reverse rotate b`) - 스택 b의 원소를 한 칸씩 아래로 옮깁니다.<br/>스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.

	- **rrr** : `rra`와 `rrb`를 동시에 수행합니다.

<br>

## Example

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

스택 a의 정수들을 12개의 명령어로 정렬합니다. 더 빠르게 정렬할 수 있으시겠어요?

<br>

## The “push_swap” program

| **Program name** |push_swap|
|---|---|
| **Turn in files** | Makefile, *.h, *.c |
| **Makefile** | NAME, all, clean, fclean, re |
| **Arguments** | stack a: A list of integers |
| **External functs.** | • read, write, malloc, free, exit<br/> • ft_printf and ny equivalent YOU coded |
| **Libft authorized** | Yes |
| **Description** | Sort stacks |

 프로젝트는 위 규칙들을 따라야 합니다:

	모든 소스 파일들을 컴파일 하는 `Makefile`을 제출해야합니다. 리링크가 되면 안됩니다.

	전역 변수는 금지됩니다.

	여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `push_swap` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위에 와야 합니다(순서에 주의하세요).

  프로그램은 스택 a를 작은 숫자가 스택의 top에 오도록 순서대로 정렬하기 위해 가능한 한 적은 개수의 명령어를 사용해야 하고, 사용한 명령어의 목록을 마지막에 출력하여야 합니다.

  명령어는 '\n'으로만 구분되어 출력되어야 합니다.

	목표는 스택을 가능한 적은 개수의 명령어로 정렬하는 것입니다. 동료평가 시에는 명령어의 개수와 용인되는 최대 명령어의 개수를 비교할 것입니다. 프로그램에서 출력한 명령어의 수가 최대 개수를 넘어서거나 제대로 정렬되지 않았을 경우, 점수를 받을 수 없습니다.

	매개 변수가 지정되지 않은 경우, 프로그램은 아무것도 표시하지 않고 프롬프트를 반환해야 합니다.

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

 평가 과정에서 프로그램을 올바르게 확인하기 위해 바이너리가 제공될 것입니다.

 이 프로그램은 다음과 같이 사용할 수 있습니다 :

```sh
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```


 `checker_OS` 프로그램이 `"KO"`를 출력했다면, 여러분의 `push_swap`이 출력한 명령어 리스트가 정수 배열 정렬에 실패하였다는 의미입니다. 



<br>

# Bonus part


 이 프로젝트는 너무 단순하기 때문에 기능을 추가하기가 쉽지 않습니다. 그럼, 여러분만의 체커를 만드는 것 어떨까요?

 체커 프로그램 덕에, 여러분의 `push_swap` 프로그램이 출력한 명령어 목록이 정상적으로 스택을 정렬하는지 쉽게 검사할 수 있습니다.


<br>

## The "Checker" Program

| Program name | checker |
| --- | --- |
| Turn in files | *.h, *.c |
| Makefile | bonus |
| Arguments | stack a : A lsit of inteagers |
| External functs. | • read, write, malloc, free, exit <br/> • ft_printf and any equivalent YOU coded |
| Libft authorized | Yes |
| Description | Execute the sorting instructions |


  여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `checker` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위 (top) 에 와야 합니다. (순서에 주의하세요)


  `checker`를 실행시키면 표준 입력으로 명령어가 들어올 때까지 대기 상태가 됩니다. 명령어는 줄옮김 '\n'으로 구분되어 들어와야 하며, 모든 명령어가 들어왔을 경우 `checker`는 명령어와 입력받은 정수 스택을 이용하여 정렬을 시작합니다.

  명령어 입력이 끝난 뒤 `checker`가 스택을 정렬하였을 때, 스택 `a`는 제대로 정렬되어 있고 스택 `b`는 비어있을 경우, `checker`는 "`OK`"를 '\n'과 함께 표준 출력하여야 합니다.

  그 외의 경우, `checker`는 "`KO`"를 '\n'과 함께 출력하여야 합니다.

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
