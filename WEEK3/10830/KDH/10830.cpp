#include <iostream>
using namespace std;

long long n, b;
long long a[5][5];
long long tmp[5][5];
long long ans[5][5];

// 행렬 곱셈
void multi(long long x[5][5], long long y[5][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0; // 행렬 초기화
            for (int k = 0; k < n; k++)
            { // 행렬 곱셈
                tmp[i][j] += (x[i][k] * y[k][j]);
            }

            tmp[i][j] %= 1000; // 모듈러 곱셈
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        ans[i][i] = 1; // 정답행렬 단위행렬로 초기화
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            multi(ans, a);
        }
        multi(a, a);
        b /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
