#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int Map[16][16];

void print_map();
void func(int row);
bool possibility_check(int row, int col);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 보드판의 가장 첫번째칸은 1, 1임(row, col 값은 1부터 시작함)
    func(1);

    cout << cnt;

    return 0;
}

// Map 확인용 출력함수
void print_map()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << Map[i][j];
        }
        cout << '\n';
    }

    cout << '\n';
}

void func(int row)
{
    // 현재 row에서 어떤 col에 퀸을 놓을지 결정하는 함수

    // 현재 row 중 col을 1부터 순서대로 넣어볼 거임
    for (int col = 1; col <= n; col++)
    {
        // row, col 자리에 퀸을 놓을 수 있다면
        if (possibility_check(row, col))
        {
            // 퀸을 놓음
            Map[row][col] = 1;

            // 놓았던 그 자리가 가장 마지막 퀸이라면 -> 경우의 수 +=1;
            if (row == n)
                cnt += 1;
            // 아직 퀸을 더 놓아야 하면 -> 다음 row로 이동(재귀)
            else
                func(row + 1);

            // Map을 전역변수로 이용하기 때문에 호출이 끝나면 반드시 원래 상태로 되돌려놔야 함.
            Map[row][col] = 0;
        }
    }
}

bool possibility_check(int row, int col)
{
    // 해당 row, col 위치에 퀸을 놓을 수 있는지 확인하는 함수, 놓을 수 있다면 true return함.
    // 각 행에 퀸을 하나씩 배치하기 때문에 같은 행에 퀸이 여러 개 있는 경우는 고려 x
    // 항상 변수 두 개를 이용한 index를 활용할 때는 bound check해야 함.

    // 같은 열에 위치한 퀸이 있으면 바로 false
    for (int i = 1; i < row; i++)
        if (Map[i][col] == 1)
            return false;

    // 오른쪽 대각선 방향 check : row보다 위쪽부분만 check하면 됨
    for (int i = 1; i <= n - col; i++)
        // bound check
        if (row - i >= 0 && col + i <= n)
            if (Map[row - i][col + i] == 1)
                return false;

    // 왼쪽 대각선 방향 check : row보다 위쪽 부분만 check하면 됨
    for (int i = 1; i < col; i++)
        // bound check
        if (row - i >= 0 && col - i >= 0)
            if (Map[row - i][col - i] == 1)
                return false;

    return true;
}