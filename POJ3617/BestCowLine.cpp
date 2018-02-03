#include <iostream>

using namespace std;

int N;

#define MAXSIZE 2005
char cows[MAXSIZE];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cows[i];
	}

	int left = 0, right = N-1;
	int cnt = 0;
	while(left <= right)
	{
		bool flag = true;
		for(int i = 0; left + i <= right - i; i++)
		{
			if(cows[left+i] < cows[right-i])
			{
				flag = true;
				break;
			}
			if(cows[left+i] > cows[right-i])
			{
				flag = false;
				break;
			}
		}

		if(flag){
			cout << cows[left++];
			cnt++;
		}
		else{
			cout << cows[right--];
			cnt++;
		}
		if(cnt % 80 == 0)
			cout << endl;
	}

	cout << endl;
	
	return 0;
}