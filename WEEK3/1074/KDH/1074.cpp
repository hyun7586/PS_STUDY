#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c, cnt = 0;
    cin >> n >> r >> c;

    while (n > 0)
    {
        n -= 1;
        int x = pow(2, n);

        if (0 <= r && r < x)
        {
            if (0 <= c && c < x)
            {
                continue;
            }
            else if (x <= c && c < 2 * x)
            {
                c = c - x;
                cnt += pow(x, 2);
            }
        }
        else if (x <= r && r < 2 * x)
        {
            if (0 <= c && c < x)
            {
                r = r - x;
                cnt += 2 * pow(x, 2);
            }
            else if (x <= c && c < 2 * x)
            {
                c = c - x;
                r = r - x;
                cnt += 3 * pow(x, 2);
            }
        }
    }

    cout << cnt;

    return 0;
}