#include <bits/stdc++.h>
using namespace std;

int N, sum;
int dp[10001];
int coins[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sum;
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    dp[0] = 1;
    // dp[i] : 합계 i를 만들 수 있는 경우의 수
    //  ex : coins={1, 2, 5, 10}
    //  dp[w]=dp[w-1]+dp[w-2]+dp[w-5]+dp[w-10]

    for (int i = 0; i < N; i++)
        // coins[i] 하나씩 순서대로 고려할 거임.
        for (int j = coins[i]; j <= sum; j++)
            // coins[i]을 사용했을 때 -> coins[i], coins[i]+1, coins[i]+2 ... 값들에 대해 경우의 수 하나씩 추가해야 함.
            // coins[i] + j-coins[i] 로 합계 j를 만드는 경우
            dp[j] += dp[j - coins[i]];

    cout << dp[sum];

    return 0;
}
