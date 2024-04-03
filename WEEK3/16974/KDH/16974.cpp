#include <bits/stdc++.h>
using namespace std;

long long len[51];
long long p[51];
long long cnt = 0, x, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    x -= 1;

    p[0] = 1;
    len[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = 2 * p[i - 1] + 1;
        len[i] = 2 * len[i - 1] + 3;
    }

    while (n >= 0)
    {
        if (n == 0)
        {
            if (x == 0)
                cnt += 1;

            break;
        }

        if (x == 0)
        {
            // case 1 : b
            break;
        }
        else if (1 <= x && x <= len[n - 1])
        {
            // case 2 : x is in range B[n-1]
            x = x - 1;
            n--;
        }
        else if (x == len[n - 1] + 1)
        {
            // case 3 : p
            cnt += p[n - 1] + 1;
            break;
        }
        else if (2 + len[n - 1] <= x && x <= 1 + 2 * len[n - 1])
        {
            // case 4 : x is in range B[n-1]
            cnt += p[n - 1] + 1;
            x = x - (2 + len[n - 1]);
            n--;
        }
        else if (x == 2 * len[n - 1] + 2)
        {
            // case 5 : b
            cnt += 2 * p[n - 1] + 1;
            break;
        }
    }

    cout << cnt;

    return 0;
}
