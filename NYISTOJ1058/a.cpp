#include <iostream>

using namespace std;

// 部分和问题 nyist OJ 1058

#define MAX_NUM 20
int a[MAX_NUM]; // the given numbers
bool adder[MAX_NUM];
int n; // the number of numbers
int k; // the target sum

bool solve(int i, int sum) // i is the counter
{
    if (i == n)
        return sum == k;

    if (sum > k)
        return false;

    if (sum == k)
        return true;

    if (solve(i + 1, sum + a[i]))
    {
        adder[i] = true;
        return true;
    }

    if (solve(i + 1, sum))
    {
        adder[i] = false;
        return true;
    }
    return false;
}

int main()
{
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++){
            cin >> a[i];
            adder[i] = false;
        }
        if (solve(0, 0))
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                if (adder[i])
                    cout << a[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}