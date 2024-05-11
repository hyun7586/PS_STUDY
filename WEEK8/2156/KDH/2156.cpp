#include <bits/stdc++.h>
using namespace std;

int N;
int dp[10001], arr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    /*
    조건)
    포도주를 연속으로 3잔 선택할 수 없음
    마실 수 있는 포도주의 최댓값

    변수)
    dp[i] : i시점에서 마실 수 있는 포도주의 최댓값(i는 1부터 시작)
    -> arr[i]를 마신 case일 수도 있고 마시지 않은 case일 수도 있음

    case 분리)
    1. arr[i]을 선택하는 경우
        1-1. arr[i]을 선택하면서 arr[i-1]을 선택하는 경우
        1-2. arr[i]을 선택하면서 arr[i-1]을 선택하지 않는 경우

    2. arr[i]을 선택하지 않는 경우
        2-1. 이전 시점에서 몇 잔을 연속으로 선택했는지 고려 안 해도 됨.
        그냥 이전 시점에서 최댓값만 고려하면 됨.

    결론)
    dp[i]=max(arr[i]+arr[i-1]+dp[i-2], arr[i]+dp[i-2], dp[i-1])

    */

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(max(arr[3] + arr[2], arr[3] + arr[1]), arr[2] + arr[1]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]), dp[i - 1]);
    }

    cout << dp[N];

    return 0;
}