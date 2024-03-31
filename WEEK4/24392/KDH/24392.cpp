#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
ll arr[1001][1001];
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (arr[i][j])
            {
                ll temp = 0;
                if (-1 < j - 1)
                    temp += arr[i + 1][j - 1];

                temp += arr[i + 1][j];

                if (j + 1 < M)
                    temp += arr[i + 1][j + 1];

                arr[i][j] = temp % mod;
            }
        }
    }

    long long result = 0;
    for (int j = 0; j < M; j++)
        result += arr[0][j];

    cout << result % mod;

    return 0;
}