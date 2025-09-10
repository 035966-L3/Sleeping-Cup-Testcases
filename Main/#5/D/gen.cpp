#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("1.in", "w", stdout);
	puts("3");
	puts("1");
	puts("2");
	puts("3");
	fclose(stdout);
	freopen("2.in", "w", stdout);
	puts("1000");
	for (int i = 1; i <= 1000; i++)
		cout << i << endl;
	fclose(stdout);
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
	fclose(stdout);
	freopen("4.in", "w", stdout);
	puts("1000");
	for (int i = 1; i <= 1000; i++)
	{
		cout << rand() % 9 + 1;
		for (int j = 1; j <= 999; j++)
			cout << rand() % 10;
		cout << endl;
	}
	fclose(stdout);
	freopen("5.in", "w", stdout);
	puts("1000");
	for (int i = 1; i <= 1000; i++)
	{
		cout << "1";
		for (int j = 1; j <= 1000; j++)
			cout << "0";
		cout << endl;
	}
	fclose(stdout);
	freopen("6.in", "w", stdout);
	puts("1000");
	printf("1");
	for(int i = 1; i <= 1000; i++)
		printf("0");
	puts("");
	for (int i = 1; i <= 999; i++)
		printf("%d\n", i);
	fclose(stdout);
	return 0;
}
