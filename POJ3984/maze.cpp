#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int> P;

int maze[5][5];
int dis[5][5];
P fa[5][5];

#define LENGTH 25
int path[LENGTH][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs()
{
    queue<P> Q;
    Q.push(P(0, 0));

    while (!Q.empty())
    {
        P p = Q.front();
        Q.pop();

        int x = p.first;
        int y = p.second;

        if (x == 4 && y == 4)
            return;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && maze[nx][ny] == 0 && dis[nx][ny] == -1)
            {
                dis[nx][ny] = dis[x][y] + 1;
                fa[nx][ny] = P(x, y);
                Q.push(make_pair(nx, ny));
            }
        }
    }
}

void backTrack()
{
    stack<P> S;
    S.push(P(4, 4));
    while (1)
    {
        P p = S.top();
        int x = p.first;
        int y = p.second;
        if (x == 0 && y == 0)
            break;

        S.push(fa[x][y]);
    }

    while (!S.empty())
    {
        P p = S.top();
        S.pop();
        int x = p.first;
        int y = p.second;
        cout << '(' << x << ", " << y << ')' << endl;
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> maze[i][j];
            dis[i][j] = -1;
        }
    }
    dis[0][0] = 0;
    bfs();
    backTrack();

    return 0;
}