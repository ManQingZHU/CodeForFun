#include <cstdio>
#include <algorithm>

using namespace std;

#define maxN 102
#define INF 0x3fffffff
int grid[maxN][maxN];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &grid[i][j]);

    // submatrix from row i to row j
    int temp, sum, ans = -INF;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum = 0;
            for (int k = 0; k < N; k++)
            {
                temp = 0;
                for (int t = i; t <= j; t++)
                    temp += grid[t][k];
                
                sum = (sum<0)?temp:sum+temp;
                ans = max(ans, sum);
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}