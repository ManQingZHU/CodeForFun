#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
#define MAXNUM 3500
int W[MAXNUM];
int D[MAXNUM];
#define MAXWEIGHT 12900
int dp[MAXWEIGHT];

int solve()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = M; j >= 0; j--)
		{
			if(j >= W[i])
				dp[j] = max(dp[j], dp[j-W[i]]+D[i]);
		}
	}

	return dp[M];
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i] >> D[i];
	}
	cout << solve();

	return 0;
}