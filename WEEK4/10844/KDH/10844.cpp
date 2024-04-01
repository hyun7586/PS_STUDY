#include <bits/stdc++.h>
using namespace std;

int N;
int mod = 1000000000;
long long dp[101][10];
long long cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    // 길이가 n인 계단 수 몇개 있는지 -> 10억 mod 연산 후 경우의 수 출력

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int n = 2; n <= N; n++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i + 1 < 10)
            {
                dp[n][i] += dp[n - 1][i + 1];
                dp[n][i] %= mod;
            }

            if (0 <= i - 1)
            {
                dp[n][i] += dp[n - 1][i - 1];
                dp[n][i] %= mod;
            }
        }
    }

    for (int i = 1; i < 10; i++)
        cnt += dp[N][i];

    cout << cnt % mod;

    return 0;
}