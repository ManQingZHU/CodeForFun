#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 6000+5;
vector<int> relation[MAXN]; // adjacent list
int dp[MAXN][2];
int c[MAXN];

int DP(int idx, int sta, int prev)
{
    if(dp[idx][sta] != -1)
        return dp[idx][sta];

    if(sta){ // black
        dp[idx][sta] = c[idx-1];
        for(vector<int>::iterator iter = relation[idx].begin(); iter != relation[idx].end(); ++iter)
        {
            if(*iter != prev)
                dp[idx][sta] += DP(*iter, 0, idx);
        }
    }else{ // white
        dp[idx][sta] = 0;
        for(vector<int>::iterator iter = relation[idx].begin(); iter != relation[idx].end(); ++iter)
        {
            if(*iter != prev)
                dp[idx][sta] += max(DP(*iter, 0, idx), DP(*iter, 1, idx));
        }   
    }

    return dp[idx][sta];
}

int main(){
    int N, u, v;
    while(scanf("%d", &N) == 1){
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < N; i++)
        {
            scanf("%d", &c[i]);
            relation[i].clear();
        }

        for(int i = 0; i < N-1; i++)
        {
            scanf("%d %d", &u, &v);
            relation[u].push_back(v);
            relation[v].push_back(u);
        }
        scanf("%d %d", &u, &v);

        printf("%d\n", max(DP(1,1,-1), DP(1,0,-1)));
    }
    return 0;
}