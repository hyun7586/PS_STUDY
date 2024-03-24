#include <bits/stdc++.h>
using namespace std;

int **arr;
int n;

void func(int threshold, int row, int col);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char ch = cin.get();
            if (ch == '\n')
                ch = cin.get();

            arr[i][j] = ch - '0';
        }

    func(n, 0, 0);

    return 0;
}

void func(int threshold, int row, int col)
{
    int flag = 1;
    int temp = arr[row][col];
    for (int i = row; i < row + threshold; i++)
        for (int j = col; j < col + threshold; j++)
            if (temp != arr[i][j])
                flag = 0;

    if (flag == 1)
    {
        cout << temp;
        return;
    }
    else
    {
        cout << "(";

        func(threshold / 2, row, col);
        func(threshold / 2, row, col + threshold / 2);
        func(threshold / 2, row + threshold / 2, col);
        func(threshold / 2, row + threshold / 2, col + threshold / 2);

        cout << ")";
    }
}