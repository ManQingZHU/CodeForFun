#include <iostream>
#include <algorithm>

using namespace std;

int R, n;
#define MAXNUM 1000
int x[MAXNUM];

int solve()
{
	sort(x, x + n);
	int leftest = 0;
	int put = 0;
	int ans = 0;
	int i;

	while (leftest < n)
	{
		for (i = leftest; i < n; i++)
		{
			if (x[i] > x[leftest] + R)
				break;
		}

		put = i - 1;

		ans++;

		for (; i < n; i++)
		{
			if (x[i] > x[put] + R)
				break;
		}
		leftest = i;
	}

	return ans;
}

int main()
{
	while (cin >> R >> n && R != -1 && n != -1)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		cout << solve() << endl;
	}

	return 0;
}