#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("3.in", "w", stdout);
	srand(time(0));
	puts("1000");
	for (int i = 1; i <= 120; i++)
		cout << i << endl;
		for (int i = 1; i <= 880; i++)
		{
			cout << "120";
			for (int j = 1; j <= i; j++)
				cout << rand() % 10;
			cout << endl;
		}
	return 0;
}
