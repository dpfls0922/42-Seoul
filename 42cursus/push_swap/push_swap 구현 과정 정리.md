# push_swap 구현 과정 정리

## 전처리 작업  (스택 구현, 인자 파싱, 예외처리)

정렬하기 전에 먼저 해주어야 할 일들

1. 과제 설명은 스택 A와 B가 이미 있는 상태에서의 일들을 설명하고 있지만 사실 아무것도 없으므로 스택 먼저 구현해야 한다.
2. 구현한 스택을 사용하기 위해 Push, Pop 등의 기본 함수를 구현해야 한다.
3. 우리가 작성한 프로그램이 인자(argv)를 받을 때 여러 개의 인자가 들어오는 경우 (인자가 없는 경우 예외처리 필요), 하나의 문자열에 여러 개의 값이 포함되어 있는 경우를 고려해 파싱하는 함수를 만들어야 한다.

```
$ ./push_swap "1 3 7 2" "3 9"
$ ./push_swap 8 2 "1 5" 63 "70 12 3"
```

1. 파싱한 인자들을 검사하여 예외처리를 해야 한다. (정수가 아닌 경우, 중복이 있는 경우 등)
2. 인자들을 스택 A에 순서대로 Push해야 한다.

## 주의사항

- 숫자들을 입력받을시 1 2 3 으로만 들어오는게 아닌 1 "7 5 6" 9 2 등의 방법도 처리해야 함
- 중복된 값이 들어올 시 오류 처리해야 함
- 숫자가 아닌 다른 값이 들어온다면 오류 처리해야 함
- 정수 범위를 초과한 값이 들어올시 오류 처리해야 함
- 명령어들은 \n으로 구분되어야 함
- 에러의 경우 Error와 줄바꿈을 표준에러 출력해야 함
- 매개 변수가 지정되지 않은 경우, 프로그램은 아무것도 표시하지 않고 프롬프트를 반환해야함

## 스택 구현 및 스택 관련 함수 작성

스택을 어떤 자료구조로 구현해야 하는지 고민하기

1. 배열
    
    ➡️ 스택의 최대 크기는 정해져 있지만, 스택에서 원소를 Push/Pop 하면 다른 원소들을 한 칸씩 이동시켜주어야 한다는 귀찮음이 있음
    
2. 단방향 연결리스트
    
    : 스택 크기만큼 node를 할당해 값을 넣어주면 되고, Push/Pop도 node를 free해주거나 생성해서 연결해줄 수 있음
    
    ➡️ 단방향으로 구현했을 시 node의 오른쪽 값밖에 볼 수 없어 값 비교나 타 연산에 제약이 생김
    
3. **양방향 연결리스트**
    
    : 공간 복잡도가 단방향 연결리스트에 비해 크지만, 연산에 제약이 줄고 알고리즘 설계할 때 편함
    

위와 같은 이유로 양방향 연결리스트로 스택을 구현하기로 했고, 헤더 파일에 다음과 같이 코드를 작성함

```c
// push_swap.h

typedef struct s_node
{
	int				     val;
	int				     rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int            size;
	struct s_node	*first;
	struct s_node	*last;
}	t_stack;

처음과 마지막 노드를 알 수 있는 t_stack 구조체
stack 내부에서 특정 값과 이전, 다음 노드의 주소를 가지고있을 t_node 구조체
```

그리고 스택 관련 함수들을 작성하기

```c
// push_swap.h

t_stack			*stack_init(void);

/* push_pop.c */
int             is_empty(t_stack *stack);
void		    push_top(t_stack *stack, t_node *new_node);
void		    push_bottom(t_stack *stack, t_node *new_node);
int             pop_top(t_stack *stack);
int             pop_bottom(t_stack *stack);

처음과 마지막 노드를 알 수 있는 t_stack 구조체
stack 내부에서 특정 값과 이전, 다음 노드의 주소를 가지고있을 t_node 구조체
stack의 앞에 새로운 노드를 추가할 push_top 함수
stack의 끝에 새로운 노드를 추가할 push_bottom 함수
stack의 가장 앞에있는 노드를 없에주는 pop_top 함수
stack의 가장 끝에있는 노드를 없에주는 pop_bottom 함수
```

스택은 큐와 다르게 후입선출이지만, push_swap에서는 정해진 연산을 사용해 스택을 정렬하므로 연산 사용의 편의성을 위해 push, pop을 first과 last에서 둘 다 가능하도록 했다.

## 제한된 명령어 구현
앞서 구현한 push_top, push_bottom, pop_top pop_bottom 함수를 이용하여 명령어를 구현한다.
```c
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
```
- `sa`: A의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- `sb`: B의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- `ss`: `sa`와 `sb`를 동시에 실행한다.
- `pa`: B에서 가장 위(탑)에 있는 원소를 가져와서 A의 맨 위(탑)에 넣는다. B가 비어 있으면 아무 것도 하지 않는다.
- `pb`: A에서 가장 위(탑)에 있는 원소를 가져와서 B의 맨 위(탑)에 넣는다. A가 비어 있으면 아무 것도 하지 않는다.
- `ra`: A의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- `rb`: B의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- `rr`: `ra`와 `rb`를 동시에 실행한다.
- `rra`: A의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- `rrb`: B의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- `rrr`: `rra`와 `rrb`를 동시에 실행한다.

## 인자 파싱 및 예외 처리

```
$ ./push_swap "1 3 7 2" "3 9"		->	1 3 7 2 3 9
$ ./push_swap 8 2 "1 5" 63 "70 12 3"	->	8 2 1 5 63 70 12 3
```

각 인자 하나하나(문자열)에 대해 정수값을 찾아주면 된다고 생각했다.

그래서 생각한 전처리 로직을 간단하게 작성해보면 다음과 같다.

```c
void    check_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)  // 널 문자를 만나기 전까지 인자 확인하기
		{
			if (*str == '-' || *str == '+' ) // 부호를 만났을 때
			{
				str++;
				if (*str < '0' || *str > '9')  // 부호 다음 값이 숫자가 아니라면 에러 처리
					print_error();
			}
			else if (*str != ' ' && (*str < '0' || *str > '9')) // 공백 문자나 숫자가 아닐 때
				print_error(); // 에러처리
			if (*str) // 널 문자가 아니면 다음 값을 가리키게 함
				str++;
		}
		i++;
	}
}
```

INT_MAX, INT_MIN의 경우도 예외처리해야 하니 주의할 것!

중복 검사는 스택에 모든 값들을 다 push한 후 스택을 순회하며 수행하기

## 그리디 알고리즘

우선 push_swap 과제에서 그리디를 사용하려면 pivot 값을 정하여 값의 크기에 따라서 partitioning 해준 뒤, 그것을 그대로 정렬하면 된다.

### partitioning

![image](https://oopy.lazyrockets.com/api/v2/notion/image?src=https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F54495ea9-b612-49db-9ce8-7c66cb3bede7%2FUntitled.png&blockId=a3976fac-ab7d-4a27-a6b5-83db5842cfb7)


****정렬 규칙****:

1. stack a는 항상 정렬된 상태다.
2. stack a에 넘어간 것은 stack b로 돌아오지 않는다.
3. stack b의 요소마다 stack a에 정렬되려면 몇 개의 명령어를 사용하는지 계산한 뒤, 가장 적은 명령어를 사용하는 요소를 stack a에 넘긴다.

**분할:**

1. pivot 2개를 설정해서 3분할한다.
    1. 명령어를 최소한으로 사용하기 위해 pivot을 2개 설정한다.
2. 스택 a에는 pivot2보다 큰 원소만 남아있다.
3. 스택 a에 5개만 남겨놓고 전부 b로 push
4. 스택 a에 남은 5개 하드코딩한다.

**최적 찾기:**

1. 스택 a에 있는 5개 이하의 노드들을 하드코딩해서 정렬한다.
2. 스택 b에서 스택 a로 옮길 때 최소의 명령어를 갖는 노드를 찾는다. → 가장 best 방법 찾기
    1. 단, 정렬이 되면서 옮겨져야 한다.
3. 최소한의 명령어를 갖는 노드를 옮길 수 있도록 스택 a와 스택 b 상태를 바꾼다.
4. 옮긴다.
5. 모든 노드가 스택 a로 이동할 때가지 1-4 단계를 반복한다.
