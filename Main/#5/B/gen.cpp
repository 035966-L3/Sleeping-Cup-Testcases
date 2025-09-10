#include <bits/stdc++.h>
using namespace std;
long long rd(int x)
{
	long long c = 0;
	for (int i = 1; i <= x; i++)
		c = c * 10 + rand() % 10;
	return c + 1;
}
int main()
{
	srand(time(0));
	freopen("1.in", "w", stdout);
	puts("4");
	puts("0");
	puts("1");
	puts("2");
	puts("3");
	fclose(stdout);
	freopen("2.in", "w", stdout);
	puts("100000");
	for (int i = 0; i <= 99999; i++)
		cout << i << endl;
	fclose(stdout);
	freopen("3.in", "w", stdout);
	puts("100000");
	puts("0");
	for (int i = 1; i <= 99998; i++)
		cout << rd(18) << endl;
	puts("1000000000000000000");
	fclose(stdout);
	return 0;
}
