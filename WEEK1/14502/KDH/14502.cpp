#include <bits/stdc++.h>
using namespace std;

#define MAX 9

int graph[MAX][MAX];
int row, col, result = 0;
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

queue<pair<int, int>> q;

void wall(int);
void modified_bfs();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> graph[i][j];

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (graph[i][j] == 2)
                q.push(make_pair(i, j));

    wall(0);

    cout << result;

    return 0;
}

void wall(int cnt)
{
    if (cnt == 3)
    {
        modified_bfs();
        return;
    }

    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                wall(cnt + 1);

                graph[i][j] = 0;
            }
}

void modified_bfs()
{
    queue<pair<int, int>> temp_q = q;

    int modified_graph[MAX][MAX];
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            modified_graph[i][j] = graph[i][j];

    while (!temp_q.empty())
    {
        pair<int, int> tmp = temp_q.front();
        temp_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ti = tmp.first + direction[i][0];
            int tj = tmp.second + direction[i][1];

            if (ti < 1 || ti > row || tj < 1 || tj > col)
                continue;

            if (modified_graph[ti][tj] == 0)
            {
                modified_graph[ti][tj] = 2;
                temp_q.push(make_pair(ti, tj));
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (modified_graph[i][j] == 0)
                count += 1;

    result = max(count, result);
}
