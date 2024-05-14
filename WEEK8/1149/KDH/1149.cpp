#include <bits/stdc++.h>
using namespace std;

int n, minest = 987654321;
int **arr;
int **cost;

int main()
{
    cin >> n;

    // 답으로 고를 수 있는 경우의 수는 3가지임.
    // 1번집을 빨간색 / 초록색 / 파란색 중 하나로 칠하면 나머지 집의 색들은 알아서 정해짐.
    // 1번집을 빨간색으로 칠하는 경우의 cost 합은 arr[n-1][0]에 저장

    // arr[i][0] : 1번집을 빨간색으로 칠하고, i-1번째집까지 색칠했을 때 cost의 합
    // cost[i][0] : i번째집을 빨간색으로 칠할 때의 cost
    arr = new int *[n];
    cost = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[3];
        cost[i] = new int[3];
    }
    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    arr[0][0] = cost[0][0];
    arr[0][1] = cost[0][1];
    arr[0][2] = cost[0][2];

    for (int i = 1; i < n; i++)
    {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[i][2];
    }

    // 최종적으로 3가지 시나리오 중 cost 합이 가장 낮은 걸 고르면 됨.
    cout << min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));

    return 0;
}