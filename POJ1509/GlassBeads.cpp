#include <cstdio>
#include <cstring>

const int MAXN = 10005;
char str [MAXN];

int solve(int len)
{
	if(len == 1)
		return 1;
	int i = 0, j = 1;
	int k;
	while(i < len && j < len)
	{
		for(k = 0; k < len; k++)
		{
			if(str[(i+k)%len] != str[(j+k)%len])
				break;
		}

		if(k == len)
			break;

		if(str[(i+k)%len] > str[(j+k)%len])
			i = i+k+1;
		else j = j+k+1;

		if(i == j)
			j++;
	}
	return (i < j)?(i+1):(j+1);
}

int main()
{
	int caseNum;
	scanf("%d", &caseNum);
	while(caseNum--)
	{
		scanf("%s", str);
		printf("%d\n", solve(strlen(str)));
	}
	return 0;
}