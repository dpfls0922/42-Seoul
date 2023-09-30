# pipex 개념정리

## 리다이렉션


리눅스 쉘은 항상 **표준 입출력**을 **파일 형태**로 연다.

- 표준입력(키보드) : stdin
- 표준출력(모니터) :stdout
- 표준에러(모니터) : stderr

기본적으로 프로그램은 연산 결과를 출력 장치(파일, 모니터, 프린터 등)로 내보내는데, 이렇게 출력되는 데이터를 임의로 다른 장치로 보내는 것을 **재지향(redirection)**이라고 한다.

다시 말하면 파일이나 프로그램, 명령어 등의 출력을 낚아채어 다른 파일이나 프로그램, 명령어의 표준 입력으로 보내는 것을 말한다.

```c
**> file**
표준 출력(1)을 파일로 재지향한다. 파일이 없으면 새로 만들고, 파일이 있으면 덮어씀
```

```c
**>> file**
표준 출력(1)을 파일로 재지향한다. 파일이 없으면 새로 만들고, 파일이 있으면 파일의 끝에 덧붙인다.
```

```c
**2>&1**
표준 에러(2)를 표준 출력(1)으로 재지향한다. 표준 에러도 표준 출력의 자격으로 보내진다.
```

```c
**< file**
파일로부터 표준 입력(0)을 받도록 재지향한다.
```

```c
**<< file**
파일로부터 표준 입력(0)을 받도록 재지향한다. 파일이 없으면 새로 만들고, 파일이 있으면 파일의 끝에 덧붙인다.
```

```
< or << : 입력 방향 재지정

> or >> : 출력 방향 재지정

> : 덮어쓰기

>> : 내용 뒤에 추가하기

'<<'은 here_doc 이라고 표현하며, 특정 문자열을 입력 받기 전까지 표준 입력을 계속 받는 상태가 된다
```

## 파이프


파이프 내부에서는 모든 것이 한쪽 끝으로 가고, 한쪽 끝은 read하고, 다른 쪽 끝은 write한다.

데이터가 흐르면서 두 프로세스 사이에 데이터가 공유된다.

이때 파이프라인 안에 있는 각 명령들은 각자 독립적인 프로세스 안에서 실행되며, 각자 독립적인 메모리 공간에서 실행된다. 각 프로세스들이 서로 통신할 수 있는 방법이 바로 `pipe()` 시스템 호출이다.

fd[0] : 부모 프로세스 (출구 / read)

fd[1] : 자식 프로세스 (입구 / write)

자식이 쓰는 동안 부모가 읽는다. 무언가를 읽으려면 먼저 써야 하므로 cmd1은 자식에 의해 실행되고 cmd2는 부모에 의해 실행된다.

앞서, 파이프가 fds를 만든다고 말했다.
./pipex infile cmd1 cmd2 outfile 를 실행하므로 infile과 outfile은 pipe의 stdin과 stdout이 되어야 한다.

```c
                           -----------------    
                 0         |     stdin     |  
                           -----------------    
                 1         |     stdout    |    
                           -----------------    
                 2         |     stderr    |  
                           -----------------
                 3         |     infile    |  // open()
                           -----------------
                 4         |     outfile   |  // open()
                           -----------------
                 5         |     fd[0]     | 
                           -----------------
                 6         |     fd[1]     |  
                           -----------------
```

The general idea: we read from *infile*, execute cmd1 with infile as input, send the output to cmd2, which will write to *outfile*.

```
# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close fd[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close fd[1]
            |--execve(cmd2)
```

`pipe()` sends the output of the first `execve()` as input to the second `execve()`; 

`fork()` runs two processes (i.e. two commands) in one single program; 

`dup2()` swaps our files with stdin and stdout.

Visually,

```c
// each cmd needs a stdin (input) and returns an output (to stdout)

    infile                                             outfile
as stdin for cmd1                                 as stdout for cmd2
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    fd[1]       ↔          fd[0]   -->     cmd2
                     |                       |
            cmd1   |---------------------------|  fd[0]
           output                             reads fd[1]
         is written                          and sends cmd1
          to fd[1]                           output to cmd2
       (fd[1] becomes                       (fd[0] becomes
        cmd1 stdout)                           cmd2 stdin)
```

- 자식 프로세스의 경우, inflie을 stdin으로 하고, fd[1]을 stdout으로 함
    - fd[1]에 cmd1의 출력 결과를 작성함
- 부모 프로세스에서, fd[0]을 stdin으로 하고, outfile을 stdout으로 함
    - fd[0]은 fd[1]으로부터 읽음 (cmd1의 출력 결과)
    - outfile에 cmd2의 출력 결과를 작성함