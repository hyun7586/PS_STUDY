#include <bits/stdc++.h>
using namespace std;

// dp 배열은 넉넉하게 2000으로 설정
// dp[i][j]=combination(i, j) : 서로 다른 i개 중에 j개를 선택하는 경우의 수
int dp[2000][2000];
int mod = 10007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 길이가 n인 오름차수
    int n;
    cin >> n;

    // combination을 dp로 구현하되, combination(10+n-1, n)까지만 구하면 됨.
    for (int i = 1; i <= 10 + n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
                dp[i][j] = 1;

            else if (j == 1)
                dp[i][j] = i;

            else
                dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }

    cout << dp[10 + n - 1][n];

    return 0;
}