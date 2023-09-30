# pipex 함수정리

## execve - 명령 실행 (다른 프로그램 실행)

올바른 stdin과 stdout을 사용하면 execeve()로 명령을 실행할 수 있다.

```c
int execve(const char *path, char *const argv[], char *envp[]);

/*

# path: 우리의 명령으로 가는 경로
        터미널에 'which ls'와 'which wc'를 입력합니다
        명령어의 이진 파일에 대한 정확한 경로를 확인할 수 있음
# argv[]: 명령에 필요한 args(예: 'ls -la')
          ft_flag를 사용하여 char **를 {"ls", "-la", NULL }와 같이 얻을 수 있음
          반드시 null로 끝나야 함
# envp: 환경 변수
        메인에서 간단히 검색하고 execve로 전달할 수 있음
        명령어의 이진 파일로 가능한 모든 경로가 포함된 라인 PATH가 표시됨
*/

int main(int ac, char **ag, char **envp)
{
     int f1;
     int f2;

     f1 = open(ag[1], O_RDONLY);
     f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (f1 < 0 || f2 < 0)
          return (-1);
     pipex(f1, f2, ag, envp);
     return (0);
}
```

- envp 내부 내용을 보려면 터미널에 env를 입력하면 된다.
- PATH 라인이 표시되는데, 이는 모두 명령 이진 파일로 연결될 수 있는 경로이다.
    - 이를 : 를 기준으로 분할해야 한다.
- execve 함수는 cmd가 적절한 경로를 찾을 때까지 가능한 모든 경로를 시도한다.
    - 예를 들어 명령어 `ls`의 경로를 보려면, 터미널에 `which ls`를 입력한다.
    - 명령어가 존재하지 않으면 execve는 아무것도 하지 않고 -1을 반환한다.
    - 존재한다면 cmd를 실행하고, 진행 중인 모든 프로세스(변수도 제거하므로 free 걱정할 필요 x)를 삭제하고 종료한다.

## pipe - 부모가 자식에게 데이터 전달

부모 프로세스가 자식 프로세스를 생성할 때 부모 프로세스는 자식 프로세스에 데이터를 줘야 한다.

```c
#include <unistd.h>

int  pipe(int fd[2]);
```

- fd : 크기가 2인 int형 배열
    - fd[0] - 파이프 출구 : 함수 호출 후 데이터를 입력(read) 받을 수 있는 파일 디스크립터가 담김
    - fd[1] - 파이프 입구 : 함수 호출 후 데이터를 출력(write)할 수 있는 파일 디스크립터가 담김
- 반환값
    - 0 : 성공 시
    - 1 : 실패 시

```
만약 자식 프로세스의 데이터를 부모 프로세스로 넘긴다고 하면
자식 프로세스에서 close(fd[0]); 를 해준다.
자식 프로세스는 write만 하고 read는 하지 않기 때문이다.
한 쪽을 닫는 이유는 한쪽이 닫힌 파이프는 widowed pipe가 되는데,
이 때 SIGPIPE 시그널이 발생하게 된다.
그러면서 EOF도 부모 프로세스로 전달된다.
```

## **wait / waitpid**

```c
#include <sys/wait.h>
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
```

- wait() 함수
    - OS가 자식프로세스가 완료될 때까지 부모 프로세스를 유지시켜 디먼 프로세스가 되는 것을 막고, 자식 프로세스의 종료를 담보해주는 역할을 한다.
    - 동시에 자식 프로세스가 좀비 프로세스가 되는 것을 막기위해 사용한다.
    - 자식프로세스가 종료돼도 부모프로세스가 진행 중이면 자식프로세스는 반환값을 지닌채 좀비 프로세스 상태로 대기하고 있다. 이때 wait()함수로 자식프로세스의 반환값을 받아주면 자식프로세스는 데이터를 넘겨주고 프로세스를 종료하게 된다.

```
좀비 프로세스?
프로세스는 종료되었지만 메모리 상에서 프로세스 정보가 유지되고 있는 상태다.
자식 프로세스에가 종료시 반환하는 인자값을 부모 프로세스가 받을 때까지
자식 프로세스는 프로세스 자원을 할당받은 상태로 남아있게 된다.
```

- waitpid() 함수
    - wait() 함수와 비슷하지만, wait() 함수는 자식 프로세스 중 어느 하나라도 종료되면 프로세스 실행을 재개하는 반면, waitpid()는 특정 자식 프로세스가 종료될 때까지 부모 프로세스가 중단된다.
    - 또 WNOHANG 옵션을 사용하면 부모 프로세스가 자식 프로세스가 종료되지 않아도 다른 작업을 진행하는 것이 가능해진다.
    - 또 wait함수와 달리 원하는 자식프로세스의 종료여부를 확인할 수 있고, 옵션을 사용해 자식프로세스의 exit status도 알 수 있다.

## **access -** 파일 / 디렉토리의 사용자 권한 체크하는 함수

execeve()는 명령을 찾지 못하면 아무 작업도 실행하지 않는다. 실행하기 전에 실행 여부를 확인해야 한다.
이를 수행하려면 access() 기능을 확인해야 한다. 적절한 모드를 사용하여 명령이 존재하고 실행 가능한지 확인할 수 있다.

```c
#include <unistd.h>
int  access(const char *pathname, int mode);
```

- pathname
    
    : 체크하고자할 디렉토리 또는 파일명
    
- mode
    - R_OK : 파일 존재 여부, 읽기 권한 여부
    - W_OK : 파일 존재 여부, 쓰기 권한 여부
    - X_OK : 파일 존재 여부, 실행 권한 여부
    - F_OK : 파일 존재 여부
- 반환값
    - 0 : 성공 시
    - 1 : 실패 시 → 오류에 대해서는 errno에 세팅됨

## **fork - 자식 프로세스(복사본 프로세스) 생성**

자식 프로세스를 생성하는 함수로 부모 프로세스 안에서 실행되는 모든 프로세스를 복제하여 병렬적으로 실행한다.

```c
#include <unistd.h>

pid_t  fork(void);
```

- 반환값
    - -1 : 실패
    - 0 : 자식 프로세스. 반환한 본인이 새로 생성된 프로세스
    - 0 이상 : 생성된 자식 프로세스의 pid


## dup / dup2 -  fd의 stdin/stdout 전환

dup()함수는 fd table에서 특정 파일을 가리키는 fd를 다른 fd값도 가리키도록 한 뒤 해당 fd를 반환한다.

dup2()함수는 dup()함수와 같으나, fd값을 자동 할당해주는 dup()와 달리 원하는 fd값을 지정해 줄 수 있다.

dup2()는 fds를 stdin/stdout 전환할 수 있다.

```c
#include <unistd.h>
int dup(int oldfd);
int dup2(int fd1, int fd2);
```

자식 프로세스 수도코드

```c
# child_process(f1, cmd1);

// add protection if dup2() < 0
// dup2 close stdin, f1 becomes the new stdin

dup2(f1, STDIN_FILENO);      // f1 == execve() input
dup2(fd[1], STDOUT_FILENO);  // fd[1] == execve() stdout
close(fd[0]) # --> always close the end of the pipe you don't use,
                    as long as the pipe is open, the other end will
                    be waiting for some kind of input and will not
                    be able to finish its process
/*
사용하지 않는 파이프의 끝을 항상 닫아야 함.
파이프가 열려 있는 한, 다른 쪽 끝은 어떤 종류의 입력을 기다리고 있을 것이고 그 과정을 끝낼 수 없을 것
*/

close(f1)
// execve function for each possible path (see below)
exit(EXIT_FAILURE);
```

부모 프로세스도 비슷하지만, 맨 처음에 waitpid()를 사용하여 자식이 프로세스를 완료할 때까지 기다림

```c
# parent_process(f2, cmd2);

int status;

waitpid(-1, &status, 0);
dup2(f2, ...);       // f2 == stdout
dup2(fd[0], ...);    // fd[0] == stdin
close(fd[1])
close(f2);
// execve function for each possible path (see below)
exit(EXIT_FAILURE);
```

## open

파일을 여는 함수

```c
int open(const char *filename, int flag, [mode_t mode]);
```

- filename : 파일명
- flag
    - O_RDONLY : 파일을 읽기 전용으로 연다. (Read Only)
    - O_RDWR : 파일을 쓰기와 읽기용으로 연다. (Read & Write)
    - O_CREAT : 파일이 없으면 생성한다. 이 플래그를 명시하면, open 함수에 Permission 정보를 추가로 더 받아야 한다. 파일이 존재하면 연다.
    - O_TRUNC : 파일이 이미 존재하고 write-only, read-write모드로 열 수 있는 경우, 파일 사이즈를 0으로 초기화시킨다
- mode : O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 **파일 접근 권한**
    - 읽기 권한 : 4
    - 쓰기 권한 : 2
    - 실행 권한 : 1

420 을 하려면 8진수 0644를 입력해야 한다

## strerror

```c
#include <string.h>
char *strerror(int errnum);
```

strerror()함수는 errno에 해당하는 에러 메시지를 가리키는 char * 포인터를 반환한다.

## perror

```c
#include <stdio.h>
void perror(const char *s);
```

출력 메시지 외에 추가적인 에러 메시지를 표준 에러 출력(2)한다. errno와 해당 에러 메시지를 같이 출력해주는 printf()함수라고 생각하면 된다.

## unlink

```c
#include <unistd.h>
int unlink(const char *pathname);
```

파일을 삭제하는 함수

---

## 헤더 요약
```c
<unistd.h>
access()
unlink()
close()
read()
write()
pipe()
dup()
dup2()
execve()
fork()
```

```c
<stdlib.h>
malloc()
free()
exit()
```

```c
<sys/wait.h>
waitpid()
wait()
```

```c
<stdio.h>
perror()
```

```
<string.h>
strerror()
```

```
<fcntl.h>
open()
```