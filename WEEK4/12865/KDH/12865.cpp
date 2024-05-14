#include <bits/stdc++.h>
using namespace std;

int N, W;
// weight, profit을 저장하는 vector
// vector의 첫번쨰 element는 0번째 index부터 시작함.
vector<pair<int, int>> stuff;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        int weight, profit;
        cin >> weight >> profit;
        stuff.push_back(make_pair(weight, profit));
    }

    // 실질적인 총 profit값을 저장하는 vector
    // dp[n][w] : n-1번째 item까지 고려한 상태고, w만큼의 용량이 담았을 때 지금까지 담은 profit의 합의 최댓값
    vector<vector<int>> dp(N + 1, vector<int>(W + 1));

    for (int n = 0; n <= N; n++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (n == 0 || w == 0)
                // malloc vector를 하면 0으로 초기화해 주지 않기 때문에 bound check 필요함
                dp[n][w] = 0;

            // n-1번째 item을 넣을 수 있는지 없는지 체크
            // 넣을 수 있다면 -> 넣었을 때 dp값, 제외했을 떄 dp값 중 큰 값을 가짐
            else if (stuff[n - 1].first <= w)
            {
                dp[n][w] = max(dp[n - 1][w - stuff[n - 1].first] + stuff[n - 1].second, dp[n - 1][w]);
            }
            // 넣을 수 없다면 그대로 n-1번째 item을 제외한 dp값을 가짐
            // n-1번째 item을 못 담는다면 n-1번째 item까지 고려한 상태의 dp==n-2번째 item까지 고려한 상태의 dp
            else
            {
                dp[n][w] = dp[n - 1][w];
            }
        }
    }

    cout << dp[N][W];

    return 0;
}