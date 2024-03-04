#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int graph[MAX][MAX], notation[MAX][MAX];
bool visited[MAX][MAX];
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<int, int>> start_nodes;
int row, col;

void modified_bfs(int r, int c);

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
    {
        for (int j = 1; j <= col; j++)
        {
            if (graph[i][j] == 1)
                start_nodes.push_back(make_pair(i, j));
        }
    }

    for (auto each : start_nodes)
        modified_bfs(each.first, each.second);

    return 0;
}

void modified_bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ti = temp.first + direction[i][0];
            int tj = temp.second + direction[i][1];

            if (visited[ti][tj] == false && graph[ti][tj] == 0)
            {
                visited[ti][tj] = true;
                q.push(make_pair(ti, tj));
            }
        }
    }
}