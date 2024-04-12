#include <bits/stdc++.h>
using namespace std;

// value[i] : input으로 받아온 value값을 저장하는 배열
// dp[i] : i번째 원소에서 시작해서 만들 수 있는 가장 긴 증가하는 부분수열의 길이(i번째 원소를 선택)
int value[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> value[i];

    /***
    <algorithm>

    value[] ={10, 20, 10, 30, 20, 50}
    2번째 원소(20)에서 시작하는 가장 긴 수열은 3~6번째 원소들에서 만든 가장 긴 수열에 붙인 거임
    2번째 원소에서 시작하는 가장 긴 수열 : 아래의 수열 중 20보다 큰 값으로 시작하면서 가장 길이가 긴 수열을 고르면 됨

    3번째 원소에서 시작한 가장 긴 수열 : 10, 20, 50
    4번째 원소에서 시작한 가장 긴 수열 : 30, 50
    5번째 원소에서 시작한 가장 긴 수열 : 20, 50
    6번째 원소에서 시작한 가장 긴 수열 : 50

    2번째 원소에서 시작하는 가장 긴 수열 : 20 + 4번째 원소에서 시작하는 가장 긴 수열 : 20, 30, 50
    dp[2]=dp[4]+1
    */
    for (int i = n; i >= 1; i--)
    {
        // 가장 마지막 원소에서 시작하는 가장 긴 수열의 길이는 1
        if (i == n)
        {
            dp[i] = 1;
            continue;
        }

        // i+1부터 n번째 원소 중 value[i]보다 값이 크면서 수열의 길이가 가장 긴 케이스를 골라야 함
        int max_of_rest = 0;

        for (int j = i + 1; j <= n; j++)
            if (value[i] < value[j])
                if (max_of_rest < dp[j])
                    max_of_rest = dp[j];

        dp[i] += max_of_rest + 1;
    }

    // dp값들 중 가장 큰 값 골라야 함.
    // 항상 첫번째 원소에서 시작한 수열이 가장 긴 수열이 아닐 때도 있음.
    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, dp[i]);

    cout << result;

    return 0;
}