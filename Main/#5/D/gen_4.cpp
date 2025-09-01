#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("4.in", "w", stdout);
	srand(time(0));
	puts("1000");
	for (int i = 1; i <= 1000; i++)
	{
		cout << rand() % 9 + 1;
		for (int j = 1; j <= 999; j++)
			cout << rand() % 10;
		cout << endl;
	}
	return 0;
}
