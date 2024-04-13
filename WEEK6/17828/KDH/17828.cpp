#include <bits/stdc++.h>
using namespace std;

int n, x;

void solve();

int main()
{
    scanf("%d %d", &n, &x);

    solve();

    return 0;
}

void solve()
{
    // 현재 문자의 개수로 x값을 표현할 수 있는 한, 앞에서부터 'A'를 최대한 많이 출력해야 함.
    // 현재 문자의 개수가 n개일 때 n개로 x를 표현할 수 있다면, 무조건 'A' 출력, 남은 문자 개수는 n-1, 표현해야 하는 값도 x-1

    // 처음 입력받은 x가 n개의 문자로 나타내기에 값이 너무 작거나 크면 ! 출력하고 return;
    if (x < n || x > 26 * n)
    {
        printf("!");
        return;
    }

    while (true)
    {
        // 지금 'A'를 추가한다면 남게 되는 n-1개의 문자로 x-1 값을 표현할 수 있는지 체크
        // 표현할 수 있다면 일단 'A' 출력하고 다음 상황으로 이동
        if (x - 1 <= (n - 1) * 26)
        {
            n -= 1;
            x -= 1;
            printf("A");
        }

        // 지금 'A'를 추가할 수 없는 상황이라면 : 남게 되는 n-1개의 문자로 x-1 값을 표현할 수 없는 경우
        // 만약 'B'를 추가한다면 괜찮은지, 'B'가 안 되면 'C'는 괜찮은지.... 계속 반복
        else
        {
            for (int i = 2; i <= 25; i++)
            {
                if (x - i <= (n - 1) * 26)
                {
                    n -= 1;
                    x -= i;
                    printf("%c", i + 64);

                    break;
                }
            }

            // 적절한 문자열을 찾게 되면 나머지 문자는 모두 Z 출력
            if (x > 0)
                for (int k = 0; k < n; k++)
                    printf("Z");

            break;
        }
    }
}