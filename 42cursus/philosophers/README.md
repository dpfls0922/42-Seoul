# **Philosophers**

철학이 이렇게 치명적인 줄은 생각치도 못했지.

요약: 이번 프로젝트에서, 여러분은 프로세스 스레딩의 기본과 스레드를 만드는 방법을 익힐 것입니다. 또한 뮤텍스가 무엇인지도 알아낼 수 있겠지요.

<br>

# Overview

이 과제를 성공적으로 수행하기 위해 알아야 할 사항은 다음과 같습니다:

- 한 명 이상의 철학자들이 원탁에 둘러앉아 있고, 테이블 중앙에는 커다란 스파게티 한 그릇이 놓여 있습니다.
- 철학자들은 번갈아가며 `먹기`, `생각하기`, `자기`를 합니다.
    
    철학자가 먹고 있을 때에는 생각하거나 자지 않습니다.
    
    생각하고 있을 때에는 먹거나 자지 않습니다.
    
    물론 자고 있을 때에는 먹거나 생각하지 않습니다.
    
- 탁자 위에는 몇 개의 포크가 올려져 있습니다. 포크의 개수는 `철학자의 수`와 같습니다.
- 한 개의 포크로 스파게티를 먹는 것은 매우 불편하기 때문에, 철학자는 오른손에는 오른쪽 포크를, 왼손에는 왼쪽 포크를 들고 먹습니다.
- 철학자가 먹기를 마치면, 포크를 탁자 위에 올려놓고 자기를 시작합니다. 자기를 마치면 생각하기를 다시 시작합니다. 시뮬레이션은 철학자가 굶어 죽을 때까지 계속됩니다.
- 모든 철학자는 먹어야 하며, 굶어 죽어서는 안됩니다.
- 철학자들은 서로 대화하지 않습니다.
- 철학자들은 다른 철학자가 죽을 것인지에 대해 알지 못합니다.
- 철학자들은 죽는 것을 피해야 합니다!

<br>

# Global Rules

- 전역 변수는 금지됩니다!
- 각 프로그램은 같은 옵션을 가져야 합니다*:*
    
    철학자의 수, 철학자의 수명, 밥을 먹는데 걸리는 시간, 잠자는 시간, [각 철학자가 최소한 밥을 먹어야 하는 횟수]
    
    - *`number_of_philosophers`:* 철학자의 수 : 철학자의 수와 포크의 수입니다.
    - *`time_to_die`* : 철학자의 수명(밀리초 단위) : 철학자가 마지막으로 밥을 먹기 시작한 시점으로부터 `time_to_die` 시간만큼이 지나거나, 프로그램 시작 후 `time_to_die` 시간만큼이 지나도록 식사를 시작하지 않으면 해당 철학자는 사망합니다.
    - *`time_to_eat` :* 밥을 먹는데 걸리는 시간(밀리초 단위) : 철학자가 밥을 먹는데 걸리는 시간입니다. 해당 시간동안 철학자는 두 개의 포크를 잡고 있어야 합니다.
    - *`time_to_sleep` :* 잠자는 시간(밀리초 단위) : 잠을 자는 데 소모되는 시간 입니다.
    - *`number_of_times_each_philosopher_must_eat` :* 각 철학자가 최소한 밥을 먹어야 하는 횟수(선택적 인자): 모든 철학자가 `number_of_times_each_philosopher_must_eat` 번 이상 밥을 먹으면 시뮬레이션이 종료됩니다. 지정되지 않은 경우, 철학자가 죽을 때 시뮬레이션이 종료됩니다.
- 각 철학자는 `1`부터 `number_of_philosophers`까지의 고유 번호를 가지고 있습니다.
- 철학자 번호 1은 철학자 번호 `number_of_philosophers`의 옆에 앉습니다. 그 외에 철학자 번호 N 은 철학자 번호 N - 1 과 철학자 번호 N + 1 사이에 앉습니다.

### *About the logs of your program*

- 철학자의 상태 변화는 다음과 같이 포맷되어야 합니다:
    - *timestamp_in_ms X has taken a fork*
    - *timestamp_in_ms X is eating*
    - *timestamp_in_ms X is sleeping*
    - *timestamp_in_ms X is thinking*
    - *timestamp_in_ms X died*
    
    ### `timestamp_in_ms`를 현재 타임스탬프(밀리초)로 바꾸고 `X`를 철학자 번호로 바꿉니다.
    
- 철학자의 상태는 다른 철학자들의 상태와 뒤엉키거나 섞인 상태로 출력되면 안 됩니다.
- 철학자의 사망 시점과 이를 출력하기 까지의 틈이 10ms 이상이 되면 안 됩니다.
- 다시 말하지만, 철학자들이 최대한 죽지 않도록 설계해야 합니다!

> ⚠️ 프로그램에 `data races`가 있어서는 안 됩니다.
> 

<br>

# **Mandatory Part**

| 프로그램 이름 | philo |
| --- | --- |
| 제출할 파일 | philo/ 디렉토리 안에 Makefile, *.h, *.c, |
| Makefile | all, clean, fclean, re |
| 인자 | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| 사용가능한 외부 함수 | memset, printf, malloc, free, write, usleep, gettimeofday, pthtread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| Libft 사용여부 | No |
| 설명 | Philosophers with threads and mutexes |

필수 파트의 규칙은 다음과 같습니다:

- 각 철학자는 스레드로 구현되어 있어야 합니다.
- 두 철학자 사이에 한 개의 포크가 존재하므로, 철학자가 여러명일 경우 각 철학자의 왼쪽과 오른쪽에 포크가 하나씩 존재해야 합니다. 철학자가 한 명일 경우 테이블 위에 포크가 하나만 존재해야 합니다.
- 철학자가 포크를 복제하는 것을 막기 위해서, 각 포크의 현재 상태를 뮤텍스를 이용하여 보호해주어야 합니다.