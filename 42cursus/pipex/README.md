# Pipex

이 프로젝트에서는 UNIX 동작 원리를 프로그래밍을 통해 상세히 파헤쳐볼 것이다.
<br>
여러분의 목표는 Pipex 프로그램을 작성하는 것입니다.
<br><br>

# Mandatory part

프로그램은 다음과 같이 실행될 것입니다:

```sh
$> ./pipex file1 cmd1 cmd2 file2
```

설명해 드리자면: file1과 file2는 파일명이고, cmd1과 cmd2에는 쉘 명령어와 그에 대한 인자값이 들어갑니다.

pipex 프로그램의 동작 결과는 다음 명령줄을 쉘에서 실행할 때의 결과와 동일하여야 합니다.

```sh
$> < file1 cmd1 | cmd2 > file2
```

```sh
$> ./pipex infile ``ls -l'' ``wc -l'' outfile
```

는 “< infile ls -l | wc -l > outfile” 와 같이 동작하여야 합니다.

```sh
$> ./pipex infile ``grep a1'' ``wc -w'' outfile
```

는 “< infile grep a1 | wc -w > outfile” 와 같이 동작하여야 합니다.

<br>

# Bonus part

  다중 파이프 구현하기:

```sh
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

  의 결과값은 다음과 같아야 합니다:

```sh
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

  첫 번째 인자값이 "here_doc" 일 경우 <<와 >> 구현하기

```sh
$> ./pipex here_doc LIMITER cmd cmd1 file
```

  의 결과값은 다음과 같아야 합니다:

```sh
cmd << LIMITER | cmd1 >> file
```
