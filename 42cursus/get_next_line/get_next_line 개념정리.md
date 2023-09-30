# get_next_line 개념정리


요약: 이 프로젝트의 목적은 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것입니다. 즉, 파일 디스크립터로부터 한 줄을 읽고, 반환하는 함수를 작성해야 한다.

```
* file descriptor을 통해 텍스트에서 eof까지 한 라인을 읽어 반환하는 함수
('\n'을 기준으로, '\n'이 나오기 전까지의 문자열을 line에 할당)

* 보너스 파트의 경우, `한 개의 static variable`만을 이용해 여러 쓰레드를 이용할 수 있게 한다.
즉, 여러 개의 파일 디스크립터를 통해 여러 파일의 라인을 각각 읽을 수 있도록 한다.
```

# get_next_line 진행과정
    
 <img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/9dcafb3d-fdab-42cd-8064-11d5379a84ee" width="350" height="300"/>

<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/43c8b073-4483-4ead-a9b9-b0ce57e17a8f" width="350" height="300"/>
<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/5dc42d53-70db-48a4-ad66-92911d3c9335" width="350" height="300"/>

<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/0acdb3b6-728f-4002-b1ec-1be97f96ad31" width="350" height="300"/>
<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/9a0d20ee-54f3-4cb0-868f-9a768ecb0228" width="350" height="300"/>
<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/9cdb268d-1ef6-4e3d-9d32-110899d0bf6a" width="350" height="300"/>

    

# 개념


## 1. 파일 디스크럽터(fd)

- 리눅스 시스템에서 모든 것을 파일이라고 한다. 파일, 디렉토리, 소켓, 드라이버, 블록 디바이스, 등등 모든 객체를 파일로 관리한다.
- 운영체제가 만든 파일 또는 소켓의 지칭을 편히 하기 위해서 부여된 숫자이다.
- 기본적으로 파일 디스크립터는 정수형으로 차례로 넘버링 되고 0,1,2는 이미 할당되어 있어서 3부터 파일 디스크립터를 부여한다.
    
    0 : 표준입력 (Standard Input)
    
    1 : 표준출력 (Standard Output)
    
    2 : 표준에러 (Standard Error)
    
- FD의 최대값은 OPEN_MAX라는 값이다.
    
    하나의 프로세스 당 최대 OPEN_MAX개의 파일을 열 수 있다. OPEN_MAX 값은 플랫폼에 따라 다르다.
    
    최대 파일 갯수는 다음 명령어를 통해 확인이 가능하다.
    
    ```java
    getconf OPEN_MAX
    ```
    
    - open_max 값
        
        ![image](https://github.com/dpfls0922/42-Seoul/assets/83818069/eb3a4033-50bf-4e03-951d-e6694b078e52)

        
        ![image](https://github.com/dpfls0922/42-Seoul/assets/83818069/7aa2d6b7-8247-4d96-81cb-68a4f5edbe20)

        
        open할 수 있는 파일의 개수
        
        터미널에서는 256. vs code에서는 10496(계속 다르게 나옴)
        
        프로세스의 목적성 때문에 열릴 수 있는 최대 파일의 개수가 다른 것
        
        → vs code는 많은 파일을, vim은 여러 개 할 필요 없음
        

## **2. read() 함수**

```c
size_t read(int fd, void *buf, size_t bytes)
```

- bytes 수 만큼 fd를 읽어 buf에 저장한다.
- 리턴값
    
    ```java
    read_size : 성공 시, 읽어온 바이트 수를 리턴함
    
    -1 : 실패 시 -1 리턴함
    
    0 : 파일을 끝(EOF)까지 읽었으면, 다음 번에는 더 이상 읽을 바이트가 없기 때문에 0을 반환함
    ```
    

## **3. gcc -d 플래그**

- 외부에서 buff size를 외부에서 지정해주기 위해서 사용한다.
- 이 문제에서 컴파일은 다음과 같이 진행된다.
    
    ```
    $ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
    ```
    
    즉, BUFFER_SIZE를 컴파일할 때 정하게 된다.
    
    ```
    gcc -D[매크로] : 매크로를 외부에서 define할 시 사용
    gcc -D[매크로]=[매크로 값] : 소스 내에서 #define [매크로][매크로 값] 옵션 추가와 동일.
    ```
    

## **4. static 변수**

- static 변수 : static 변수는 메모리의 `data영역`에 저장된다. 지역변수와는 다르게 함수 호출과 종료 시에 값이 초기화되거나 제거되지 않는다. 즉 함수 블록을 벗어나도 값이 제거되지 않고, `프로그램 종료 시 까지 남아있다`.
- 지역변수 : 지역변수는 `스택 영역`에 저장된다. 이 영역은 함수 내부에서 선언된 지역변수, 리턴값 등등이 저장되고, 함수 호출 시 기록되고 종료되면 제거된다.

get_next_line 함수에서는 이전까지 읽었던 문자열을 저장하기 위해 'static 변수'를 이용한다.

# 아이디어

## 과정

1. 파일을 read 할 임시 버퍼(buf)를 만든다.
2. read한 버퍼를 백업할 static 버퍼(backup)를 만든다.
3. `read(fd, buf, BUFFER_SIZE);`를 해서 라인을 읽은 다음,
4. `buf`를 static 변수 `backup`에 백업한다.
5. `backup`안에 개행문자가 있는지 없는지 검사한다.
6. 개행문자가 있으면 다음 단계로 넘어가고, 없다면 개행 문자가 있을 때 까지 3번으로 돌아가 파일을 계속 읽으면서 기존에 백업한 것과 계속 합쳐나간다.
7. 개행문자가 있는 `backup`을 개행문자 전과 후로 잘라서, `\n` 전까지는 `line` 에다가 주고 `\n` 후는 다시 static 변수 `backup`에 백업한다.

```
(1) 보너스 파트 구현을 위해 static char *backup[OPEN_MAX]선언.

OPEN_MAX는 단일 프로그램에 허용되는 `최대 열린 파일 수`를 정의하는 상수다.
Unix 시스템에서 C언어의 OPEN_MAX는 limits.h에 정의돼있다.
그러나 허용되지 않은 헤더를 import하면 안되므로 Bonus 헤더에 OPEN_MAX를 정의해 놓았다.

최대 파일 수만큼의 인덱스를 가지는 포인터 배열을 선언함으로써, OPEN_MAX만큼의 백업 문자열을 다룰 수 있게 되었다.

(2) read를 통해 읽은 데이터를 저장할 buf를 BUFFER_SIZE+1 사이즈 만큼 동적 할당한 후, buf에 읽은 데이터 저장.

크기가 'BUFFER_SIZE + 1'인 이유는 'ft_strjoin()'을 이용해 이전에 읽었던 데이터가 저장된 backup[fd] 문자열과 buf 문자열을 합하는데, 문자열을 합치는 기준이 '\0'이기 때문에 buf의 맨 뒤에도 '\0'을 넣는다.

(3) 읽은 데이터를 저장한 buf를 ft_strjoin()을 통해 backup[fd]와 합하고, 합한 문자열을 다시 backup[fd]에 넣는다.

이 과정을 통해 지금까지 읽었던 문자열이 backup[fd]에 저장되어 있다.

(4) '\n'을 찾으면, '\n'전까지의 값과 '\n'을 line에 넣는다. 마지막에 '\0'도 넣어준다. 개행이 없으면 (2)로 돌아간다.

(5) \n이후의 문자열을 static char *변수 backup[fd]에 넣는다.

이 과정을 통해 \n이후의 문자열이 backup[fd]에 저장된다.

즉, \n을 기준으로 \n이전까지의 문자열은 line에 저장되고, \n이후의 문자열은 backup[fd]에 저장되어 이후 읽을 buf와 합쳐진다.
```

# 고민한 지점들

## 1. line 변수에 대한 고민

### line은 왜 이중포인터인가?

읽어들인 라인(char *)의 주소를 저장하기 위해서다.

- `포인터 변수` **:** 자료값을 저장하는 목적이 아닌 자료값이 저장된 곳의 주소를 저장하는 변수

함수를 통해 기능을 구현하였기 때문에 이중 포인터를 사용해야 한다.

- 함수가 종료되면서 지역 포인터 변수 ptr 메모리가 소거되기 때문에, origin의 포인터 값이 변경 안됨 (swap과 비슷)
- 하지만 이중 포인터를 사용하면, 함수가 종료 후 ptr 메모리가 소거되더라도 origin의 포인터가 변경되기 때문에 수정이 가능함

<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/a046298d-359b-43b2-942d-3bd69106b671" width="350" height="300"/>
<img src="https://github.com/dpfls0922/42-Seoul/assets/83818069/4fd9043b-86ad-4b42-87a6-c7391deff825" width="350" height="300"/>


## **2. read함수가 0을 반환하는 경우**

### **파일을 끝까지 다 읽어서 0 반환**

line = 0으로 메모리 해제가 된 상황. 남은 backup을 line에 넣어준다. main에서 다른 파일을 read할 수 있으니 backup = 0; 해준다.

free(buf)를 해버리면 *line이 담고있는 주소값에 대한 메모리가 해제돼버려서 올바른 값이 들어가지 않고 쓰레기값이 남게된다.

### **빈 파일을 읽어서 0 반환**

backup이 아무 값도 가리키고 있지 않기 때문에 위와 같은 경우로 묶었을 때 segmentation fault가 뜬다.

read_size == 0 && *backup == 0의 경우, backup을 free해주고 널을 반환해준다.

## 3. 언제 메모리가 누수 되는가?

```c
free(buf); 할당받은 메모리를 해제하는 것

buf = 0; 할당받은 메모리 주소를 담고있는 buf 변수가 0 값을 갖게 되는 것
```

### malloc과 free의 매커니즘

프로그램에 메모리 공간을 할당할 때, 시스템은 물리적인 메모리를 프로그램에 직접 할당하지 않고 가상메모리라는 메모리 관리 기법을 이용하여 메모리 공간을 할당하게 된다.

`가상메모리`란 물리적인 메모리보다 큰 프로세스를 실행시키기 위해 `물리 메모리를 추상화하는 기법`으로, 메모리 관리의 핵심 중 하나이다.

malloc 함수를 호출하면 시스템에서는 가상메모리를 요청하여 공간을 할당하고, free를 호출하면 이 할당한 공간을 해제하게 된다. 이에 대한 과정은 다음과 같다.

### **malloc과 free 과정**

- malloc 함수를 호출하면 커널에서 가상메모리를 요청한다.
- 그리고 malloc에서 요청한 크기만큼 프로그램의 가상메모리에 매핑을 하게 된다.
- free 함수를 호출하면 할당된 공간을 해제하는데, 해제된 메모리는 커널에 반환되지 않고 free-list라는 것으로 관리된다.
- 그리고 프로그램에서 메모리 할당에 대해서 재요청을 하면, 관리하던 free-list에서 재할당을 하게 되는 것이다.

<aside>
💡 다만 이는 시스템에 따라 달라지는 부분이 있다.

free는 정확히 할당된 공간의 시작주소가 아니면 free를 하지 않는다.
포인터 변수 p에 malloc으로 공간의 시작주소를 넘겨주고 p의 주소를 연산하여 이동시킨다음 free를 하면 에러가 발생한다.

</aside>

### 1) ****dangling pointer****

포인터 변수가 free된 공간의 주소를 여전히 갖고 있음으로써 그 공간에 접근이 가능한 문제를 `dangling pointer`라고 한다.

다음과 같은 코드가 있다고 하자

```c
char *s;
	
s = (char *)malloc(sizeof(char) * 10);
sprintf(s, "hello");
printf("%s\n", s);
	
free(s);
printf("%s\n", s);    // dangling pointer 발생
```

dangling pointer를 알지 못한다는 전제하에, 예상되는 결과는 다음과 같을 것이다.

```c
output:
	hello
	(null)
```

하지만 실제 출력되는 결과는 다음과 같다.

```c
output:
	hello
	hello
```

이는 free함수가 s가 가리키고 있는 메모리 공간을 free-list로 관리될 수 있게 도와줄 뿐, 메모리 공간을 직접 지우거나 s에 NULL 포인터를 대입하지 않기 때문이다.

따라서 free를 한 후에 바로 s를 호출하면 여전히 s는 free된 공간을 가리키고 있고, 그 공간에는 여전히 ‘hello’라는 데이터가 남아있는 것이다.

dangling pointer를 방지하려면 다음과 같이 해야한다

```c
free(s);
	s = NULL;             // NULL을 넣어 s가 free된 공간을 가리키지 않도록 함
	printf("%s\n", s);
```

****free를 한 후 dangling pointer는 무조건 방지해야 하는가?****

free를 한 뒤 무조건 해당 포인터에 NULL을 넣어야 하는 것은 아니다. dangling pointer의 핵심은 free된 공간을 다시 접근하려 하는 것이므로, 다시 접근 할 일이 없으면 굳이 방지 할 필요는 없다.

이런 경우에는 방지 하지 않아도 된다

- 함수의 지역 포인터 변수를 free하고 바로 종료하는 경우
- 해당 포인터 변수를 free한 후에 다시 쓸 일이 없을 경우
    
    한편, free를 한 뒤 방지해야 하는 위치에 대해서도 유의해야 한다
    
- 포인터 변수를 매개변수로 가져온 뒤, 그 함수 안에서 free를 하고 그 뒤에 NULL을 넣어도 함수 밖에서는 적용이 되지 않고 여전히 free된 공간을 가리키고 있다
- 이때는 함수 밖에서 포인터 변수의 값을 NULL로 바꿔주거나, 매개변수로 가져올 때 이중포인터로 가져와서 해당 포인터 변수의 값을 수정할 수 있게 해주어야 한다.

### 2) **메모리 누수**

할당받은 메모리 주소를 잃어버린 게 돼서 해제가 불가능 하게 되는 상황을 memory leak, 메모리 누수라고 한다. 예외가 발생하여 함수가 종료되기 전에 동적 할당 받은 값들을 해제시키고, 리턴되는 값을 NULL 처리해야 한다.
