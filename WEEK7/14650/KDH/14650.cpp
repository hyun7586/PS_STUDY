#include <bits/stdc++.h>
using namespace std;

int N;
// digit[i] : i번째 숫자를 저장하는 배열
// 329482 -> 1번째 숫자==3, 2번째 숫자==2, 3번째 숫자==9...
int digit[10];

int solve(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0, 1, 2로 만들 수 있는 n자리 3의 배수의 개수
    cin >> N;

    cout << solve(0);

    return 0;
}

int solve(int n)
{
    // n번째 자리 숫자까지 정해졌을 때를 고려하는 함수

    // N번째 자리 숫자까지 모두 정해졌을 경우 : 각 자릿수를 더한 값이 3의 배수인지 체크
    if (n == N)
    {
        int cnt = 0, result = 0;

        for (int i = 1; i <= 9; i++)
            result += digit[i];

        if (result % 3 == 0)
            return 1;

        return 0;
    }

    // 아직 모든 자릿수가 정해지지 않았을 경우 : n+1번째 자릿수를 하나씩 배정해가며 재귀호출
    int candidate0 = 0, candidate1 = 0, candidate2 = 0;

    if (n != 0)
    {
        digit[n + 1] = 0;
        candidate0 = solve(n + 1);
    }

    digit[n + 1] = 1;
    candidate1 = solve(n + 1);

    digit[n + 1] = 2;
    candidate2 = solve(n + 1);

    return candidate0 + candidate1 + candidate2;
}