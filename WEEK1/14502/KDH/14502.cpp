#include <bits/stdc++.h>
using namespace std;

#define MAX 9

int graph[MAX][MAX];
int modified_graph[MAX][MAX];
bool visited[MAX][MAX];
int row, col, result = 0;
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

queue<pair<int, int>> q;

void solve();
void wall(int);
void modified_bfs();
int secure_areas();
void clear_visited();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
        {
            int num;
            cin >> num;
            graph[i][j] = modified_graph[i][j] = num;

            if (num == 2)
                q.push(make_pair(i, j));
        }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (modified_graph[i][j] == 0)
            {
                modified_graph[i][j] = 1;
                wall(1);

                modified_graph[i][j] = 0;
            }
        }
    }

    cout << result;

    return 0;
}

void wall(int cnt)
{
    // cnt는 지금까지 세워놓은 벽의 개수
    if (cnt == 3)
    {
        modified_bfs();
        result = max(secure_areas(), result);
        clear_visited();
        return;
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (modified_graph[i][j] == 0)
            {
                modified_graph[i][j] = 1;
                wall(cnt + 1);

                modified_graph[i][j] = 0;
            }
        }
    }
}

void modified_bfs()
{
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ti = tmp.first + direction[i][0];
            int tj = tmp.second + direction[i][1];

            if (ti < 1 || ti > row || tj < 1 || tj > col)
                continue;

            if (visited[ti][tj] == false && modified_graph[ti][tj] == 0)
            {
                visited[ti][tj] = true;
                modified_graph[ti][tj] = 2;
                q.push(make_pair(ti, tj));
            }
        }
    }
}

int secure_areas()
{
    int cnt = 0;

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (modified_graph[i][j] == 0)
                cnt += 1;

    return cnt;
}

void clear_visited()
{
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
            visited[i][j] = false;
}