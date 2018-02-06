#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 0x3fffffff
const int MAXN = 10000+5;
vector<int> conn[MAXN];
int dp[MAXN][3]; 
// 0: client with all client sons
// 1: client with exact one server son 
// 2: server

int DP(int idx, int stat, int prev)
{
    if(dp[idx][stat] != -1)
        return dp[idx][stat];

    if(stat == 0){
        dp[idx][stat] = 0;
        for(vector<int>::iterator it=conn[idx].begin(); it != conn[idx].end(); ++it)
        {
            if(*it != prev)
                dp[idx][stat] += DP(*it, 1, idx);
        }
    }else if(stat == 1){
        int minVal = INF, temp;
        for(vector<int>::iterator it=conn[idx].begin(); it != conn[idx].end(); ++it)
        {
            if(*it != prev)
            {
                temp = -DP(*it,1, idx)+DP(*it, 2, idx);
                minVal = min(minVal, temp);
            } 
        }
        dp[idx][stat] = DP(idx, 0, prev) + minVal;
    }else{
       dp[idx][stat] = 1;
       for(vector<int>::iterator it=conn[idx].begin(); it != conn[idx].end(); ++it)
        {
            if(*it != prev)
                dp[idx][stat] += min(DP(*it, 0, idx), DP(*it, 2, idx));
        } 
    }
    return dp[idx][stat];
}

int main()
{
    bool terminal = false;
    int N, u, v;
    while(!terminal)
    {
        scanf("%d", &N);

        memset(dp,-1, sizeof(dp));
        for(int i = 1; i <= N; i++)
            conn[i].clear();

        for(int i = 0; i < N-1; i++)
        {
            scanf("%d %d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }

        // TODO

        scanf("%d", &N);
        if(N == -1)
            terminal = true;
    }

    return 0;
}