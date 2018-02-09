#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 50000+5;
int num[MAXN], dp1[MAXN], dp2[MAXN], max1[MAXN], max2[MAXN];
#define INF 0x3fffffff
// dp1[n] = max(0, dp1[n-1]) + array[n]
// dp2[n] = max(0, dp2[n+1]) + array[n]

int main()
{
    int T, n, maxsum;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }

        max1[0] = dp1[0] = num[0];
        max2[n-1] = dp2[n-1] = num[n-1];

        for(int j = 1; j < n; j++)
        {
            dp1[j] = max(0, dp1[j-1])+num[j];
            max1[j] = max(max1[j-1], dp1[j]);
            dp2[n-1-j] = max(0, dp2[n-j])+num[n-1-j];
            max2[n-1-j] = max(max2[n-j], dp2[n-1-j]);
        }
        
        maxsum = -INF;
        for(int i = 0; i < n-1; i++)
            maxsum = max(maxsum, max1[i]+max2[i+1]);

        printf("%d\n", maxsum);
    }
    return 0;
}