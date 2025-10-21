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
	puts("1");
	puts("1");
	fclose(stdout);
	freopen("2.in", "w", stdout);
	puts("50");
	for (int i = 1; i <= 50; i++)
		puts("1");
	fclose(stdout);
	freopen("4.in", "w", stdout);
	cout << 50 << endl;
	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 3; j++)
			cout << i << endl;
	for (int i = 1; i <= 8; i++)
		cout << 15 << endl;
	fclose(stdout);
	freopen("6.in", "w", stdout);
	cout << 50 << endl;
	for (int i = 1; i <= 50; i++)
		cout << rd(4) << endl;
	fclose(stdout);
	freopen("7.in", "w", stdout);
	cout << 50 << endl;
	for (int i = 1; i <= 40; i++)
		cout << 9959 + i << endl;
	for (int i = 1; i <= 10; i++)
		cout << 10000 << endl;
	fclose(stdout);
	freopen("8.in", "w", stdout);
	puts("1");
	puts("1000000000");
	fclose(stdout);
	freopen("9.in", "w", stdout);
	cout << 50 << endl;
	for (int i = 1; i <= 50; i++)
		cout << rd(9) << endl;
	fclose(stdout);
	freopen("10.in", "w", stdout);
	cout << 50 << endl;
	for (int i = 1; i <= 40; i++)
		cout << 999999959 + i << endl;
	for (int i = 1; i <= 10; i++)
		cout << 1000000000 << endl;
	fclose(stdout);
	return 0;
}
