#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int selected[9];

void func(int cnt);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // arr[i]=i : 1~n을 저장한 배열
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    func(0);

    return 0;
}

void func(int cnt)
{
    // 현재까지 cnt개의 숫자를 선택한 상황

    // m개의 숫자를 모두 골랐다면
    if (cnt == m)
    {
        int result[9];
        for (int i = 1; i <= n; i++)
            if (selected[i])
                result[selected[i]] = i;

        for (int i = 1; i <= m; i++)
            cout << result[i] << " ";

        cout << '\n';
        return;
    }

    // 아직 m개의 숫자를 모두 고르지 않았다면
    for (int i = 1; i <= n; i++)
    {
        if (selected[i] == 0)
        {
            selected[i] = cnt + 1;
            func(cnt + 1);
            selected[i] = 0;
        }
    }
}