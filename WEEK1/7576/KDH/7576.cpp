#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int graph[MAX][MAX], notation[MAX][MAX];
bool visited[MAX][MAX];
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int row, col, result = 0;
queue<pair<int, int>> q;

void modified_bfs();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> col >> row;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> graph[i][j];

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (graph[i][j] == 1)
                q.push(make_pair(i, j));

    modified_bfs();

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
        {
            if (graph[i][j] == 0)
            {
                cout << -1;
                return 0;
            }

            if (result < graph[i][j])
                result = graph[i][j];
        }

    cout << result - 1;

    return 0;
}

void modified_bfs()
{
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ti = temp.first + direction[i][0];
            int tj = temp.second + direction[i][1];

            if (ti < 1 || ti > row || tj < 1 || tj > col)
                continue;

            if (visited[ti][tj] == false && graph[ti][tj] == 0)
            {
                visited[ti][tj] = true;
                graph[ti][tj] = graph[temp.first][temp.second] + 1;
                q.push(make_pair(ti, tj));
            }
        }
    }
}