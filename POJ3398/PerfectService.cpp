#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 0x3fff
const int MAXN = 10000+5;
vector<int> conn[MAXN];
int dp[MAXN][3]; 
// 0: client with all client sons
// 1: client with exact one server son 
// 2: server

void DP(int idx, int prev)
{
    dp[idx][0] = 0;
    dp[idx][1] = INF;
    dp[idx][2] = 1;
    
    int value;
   for(vector<int>::iterator it=conn[idx].begin(); it != conn[idx].end(); ++it)  
   {
       value = *it;
       if(value == prev)
            continue;
        DP(value, idx);
        dp[idx][0] += dp[value][1];
        dp[idx][1] = min(dp[idx][1], dp[value][2]-dp[value][1]);
        dp[idx][2] += min(dp[value][0], dp[value][2]);
   }
   dp[idx][1] += dp[idx][0];
}

int main()
{
    int N, u, v;
    while(scanf("%d", &N))
    {
        for(int i = 1; i <= N; i++)
            conn[i].clear();

        for(int i = 0; i < N-1; i++)
        {
            scanf("%d %d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }
        scanf("%d", &N);
        
        DP(1,-1);
        printf("%d\n", min(dp[1][1], dp[1][2]));

        if(N == -1)
            break;
    }

    return 0;
}