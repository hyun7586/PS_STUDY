#include <bits/stdc++.h>
using namespace std;

int N;
int dp[501][501];
int arr[501][501];

void Input();
int solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    cout << solve();

    return 0;
}

void Input()
{
    // 삼각형을 왼쪽정렬해서 직각삼각형 형태로 배열에 저장
    // dp 배열의 인덱스는 1부터 시작
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            cin >> dp[i][j];
}

int solve()
{
    // dp 마지막 row에서 최댓값을 저장할 변수
    int result = 0;

    // dp[i][j]=dp[i][j]+max(dp[i-1][j-1], dp[i-1][j])
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int temp = dp[i - 1][j];

            // j-1이 참조가 가능한지 bound check
            if (j - 1 >= 1)
                temp = max(temp, dp[i - 1][j - 1]);

            dp[i][j] += temp;
        }
    }

    // dp[N] 에서 가장 큰 값 찾기
    for (int j = 1; j <= N; j++)
        result = max(result, dp[N][j]);

    return result;
}