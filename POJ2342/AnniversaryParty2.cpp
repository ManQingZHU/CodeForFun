#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 6000+5;
vector<int> relation[MAXN]; // adjacent list
int dp[MAXN][2];
int c[MAXN];

void DP(int idx, int prev)
{
    dp[idx][0] = 0;
    dp[idx][1] = c[idx];

    int value;
    for(vector<int>::iterator it = relation[idx].begin(); it != relation[idx].end(); ++it)
    {
        value = *it;
        if(value == prev)
            continue;
        DP(value,idx);
        dp[idx][0] += max(dp[value][0], dp[value][1]);
        dp[idx][1] += dp[value][0];
    }
}

int main(){
    int N, u, v;
    while(scanf("%d", &N) == 1){
        for(int i = 1; i <= N; i++)
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
        DP(1,-1);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}