#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int m = 0, n = 0;
char txt1[102][32], txt2[102][32], lcs[102][32];

int dp[102][102];

int main()
{
    while (scanf("%s", txt1[m++]) == 1)
    {

        while (scanf("%s", txt1[m++]) == 1)
            if (strcmp(txt1[m - 1], "#") == 0)
                break;

        while (scanf("%s", txt2[n++]) == 1)
            if (strcmp(txt2[n - 1], "#") == 0)
                break;
        m--, n--;

        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (strcmp(txt1[i - 1], txt2[j - 1]) == 0)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (strcmp(txt1[i - 1], txt2[j - 1]) == 0)
            {
                strcpy(lcs[dp[i][j] - 1], txt1[i - 1]);
                i--, j--;
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
        for (int k = 0; k < dp[m][n]; k++)
            printf("%s ", lcs[k]);
        printf("\n");
        m = 0, n = 0;
    }

    return 0;
}
