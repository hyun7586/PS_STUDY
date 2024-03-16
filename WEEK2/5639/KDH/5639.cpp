#include <bits/stdc++.h>
using namespace std;

int pre[10000];

void print_PostOrder(int pre[], int n, int minVal, int maxVal, int &pre_index);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, pre_index = 0, num;

    while (cin >> num)
    {
        pre[n++] = num;
    }

    print_PostOrder(pre, n, *min_element(pre, pre + n), *max_element(pre, pre + n), pre_index);

    return 0;
}

void print_PostOrder(int pre[], int n, int minVal, int maxVal, int &pre_index)
{
    if (pre_index == n)
        return;

    if (pre[pre_index] < minVal || pre[pre_index] > maxVal)
        return;

    int val = pre[pre_index++];

    print_PostOrder(pre, n, minVal, val, pre_index);
    print_PostOrder(pre, n, val, maxVal, pre_index);
    cout << val << '\n';
}