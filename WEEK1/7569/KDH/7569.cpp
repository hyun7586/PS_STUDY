#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int graph[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int direction[6][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {1, 0, 0}};
int row, col, height, result = 0;
queue<tuple<int, int, int>> q;

void modified_bfs();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> col >> row >> height;
    for (int k = 1; k <= height; k++)
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                cin >> graph[k][i][j];

    for (int k = 1; k <= height; k++)
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                if (graph[k][i][j] == 1)
                    q.push(make_tuple(k, i, j));

    modified_bfs();

    for (int k = 1; k <= height; k++)
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
            {
                if (graph[k][i][j] == 0)
                {
                    cout << -1;
                    return 0;
                }

                if (result < graph[k][i][j])
                    result = graph[k][i][j];
            }

    cout << result - 1;

    return 0;
}

void modified_bfs()
{
    while (!q.empty())
    {
        tuple<int, int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int th = get<0>(temp) + direction[i][0];
            int ti = get<1>(temp) + direction[i][1];
            int tj = get<2>(temp) + direction[i][2];

            if (th < 1 || th > height || ti < 1 || ti > row || tj < 1 || tj > col)
                continue;

            if (visited[th][ti][tj] == false && graph[th][ti][tj] == 0)
            {
                visited[th][ti][tj] = true;
                graph[th][ti][tj] = graph[get<0>(temp)][get<1>(temp)][get<2>(temp)] + 1;
                q.push(make_tuple(th, ti, tj));
            }
        }
    }
}