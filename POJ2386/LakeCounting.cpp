#include <iostream>

using namespace std;

#define MAX_SIZE 105
char field[MAX_SIZE][MAX_SIZE];
int N, M;

void dfs(int x, int y)
{
    field[y][x] = '.';

    for(int dx = -1; dx <=1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            int nx = dx + x;
            int ny = dy + y;
            if(nx >= 0 && nx < M && ny >= 0 && ny < N && field[ny][nx] == 'W')
                dfs(nx, ny);
        }
    }
    
}

int solve()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
           if(field[i][j] == 'W'){
               dfs(j,i);
               ans++;
           }
        }
    }
    return ans;
}

int main()
{
    while (cin >> N >> M)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> field[i][j];
            }
        }

        cout << solve() << endl;
    }
    return 0;
}