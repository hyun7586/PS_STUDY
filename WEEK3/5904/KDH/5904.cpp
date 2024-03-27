#include <bits/stdc++.h>
using namespace std;

long long len[31];

void func(int index, int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    len[0] = 3;
    for (int i = 1; i <= 29; i++)
        len[i] = 2 * len[i - 1] + i + 3;

    func(n - 1, 29);

    return 0;
}

void func(int index, int k)
{
    if (k == 0)
    {
        if (index == 0)
        {
            cout << 'm';
            exit(0);
        }
        else
        {
            cout << 'o';
            exit(0);
        }
    }

    int bound1 = len[k - 1];
    int bound2 = len[k - 1] + k + 3;

    if (index < bound1)
        func(index, k - 1);

    else if (bound1 <= index && index < bound2)
    {
        if (index == bound1)
        {
            cout << 'm';
            exit(0);
        }
        else
        {
            cout << 'o';
            exit(0);
        }
    }

    else if (bound2 <= index)
        func(index - bound2, k - 1);
}