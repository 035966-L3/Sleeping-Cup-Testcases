#include <bits/stdc++.h>
using namespace std;
unsigned int z = 813699126;
inline unsigned int get()
{
	z ^= z << 7;
	z ^= z >> 23;
	z ^= z << 12;
	return z;
}
inline int rd()
{
	int x = 0;
	for (int i = 1; i <= 9; i++)
		x = x * 10 + get() % 10;
	return x + 1;
}
int main()
{
	freopen("1.in", "wb", stdout);
	puts("2 3");
	puts("1 3");
	puts("3 3");
	puts("1 2");
	puts("2 2");
	puts("3 3");
	fclose(stdout);
	freopen("2.in", "wb", stdout);
	puts("1000000 1000000");
	for (int i = 1; i <= 200000; i++)
		puts("1000000000 1000000000");
	int xx = rd();
	for (int i = 1; i <= 200000; i++)
		printf("%d 1000000000\n", xx);
	int yy = rd();
	for (int i = 1; i <= 200000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 200000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 200000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	for (int i = 1; i <= 200000; i++)
		puts("1000000000 1000000000");
	for (int i = 1; i <= 200000; i++)
		printf("%d 1000000000\n", xx);
	for (int i = 1; i <= 200000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 200000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 200000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("1000000 1000000");
	for (int i = 1; i <= 199999; i++)
		puts("1000000000 1000000000");
	xx = rd();
	for (int i = 1; i <= 200000; i++)
		printf("%d 1000000000\n", xx);
	yy = rd();
	for (int i = 1; i <= 200000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 200000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 200000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	puts("999999999 999999999");
	for (int i = 1; i <= 500000; i++)
		puts("1000000000 1000000000");
	for (int i = 1; i <= 100000; i++)
		printf("%d 1000000000\n", xx);
	for (int i = 1; i <= 100000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 100000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 100000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	for (int i = 1; i <= 100000; i++)
	{
		int x = rd();
		int y = rd();
		printf("%d %d\n", x, y);
	}
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("7 9");
	puts("1 1");
	puts("1 2");
	puts("2 1");
	puts("2 2");
	puts("2 3");
	puts("3 2");
	puts("3 3");
	puts("1 1");
	puts("1 2");
	puts("1 3");
	puts("2 1");
	puts("2 2");
	puts("2 3");
	puts("3 1");
	puts("3 2");
	puts("3 3");
	fclose(stdout);
	freopen("5.in", "wb", stdout);
	puts("3 9");
	puts("1 1");
	puts("2 2");
	puts("3 3");
	puts("1 1");
	puts("1 2");
	puts("1 3");
	puts("2 1");
	puts("2 2");
	puts("2 3");
	puts("3 1");
	puts("3 2");
	puts("3 3");
	fclose(stdout);
	freopen("6.in", "wb", stdout);
	puts("10000 10000");
	for (int i = 1; i <= 1999; i++)
		puts("1000000000 1000000000");
	xx = rd();
	for (int i = 1; i <= 2000; i++)
		printf("%d 1000000000\n", xx);
	yy = rd();
	for (int i = 1; i <= 2000; i++)
		printf("1000000000 %d\n", yy);
	puts("666666666 666666666");
	for (int i = 1; i <= 2000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 2000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	for (int i = 1; i <= 5000; i++)
		puts("1000000000 1000000000");
	for (int i = 1; i <= 1000; i++)
		printf("%d 1000000000\n", xx);
	for (int i = 1; i <= 1000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 1000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 1000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	for (int i = 1; i <= 1000; i++)
	{
		int x = rd();
		int y = rd();
		printf("%d %d\n", x, y);
	}
	fclose(stdout);
	freopen("7.in", "wb", stdout);
	puts("10000 10000");
	for (int i = 1; i <= 2000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 2000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	puts("666666666 666666666");
	for (int i = 1; i <= 1999; i++)
		puts("1000000000 1000000000");
	xx = rd();
	for (int i = 1; i <= 2000; i++)
		printf("%d 1000000000\n", xx);
	yy = rd();
	for (int i = 1; i <= 2000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 5000; i++)
		puts("1000000000 1000000000");
	for (int i = 1; i <= 1000; i++)
		printf("%d 1000000000\n", xx);
	for (int i = 1; i <= 1000; i++)
		printf("1000000000 %d\n", yy);
	for (int i = 1; i <= 1000; i++)
	{
		int x = rd();
		printf("%d 1000000000\n", x);
	}
	for (int i = 1; i <= 1000; i++)
	{
		int y = rd();
		printf("1000000000 %d\n", y);
	}
	for (int i = 1; i <= 1000; i++)
	{
		int x = rd();
		int y = rd();
		printf("%d %d\n", x, y);
	}
	fclose(stdout);
	freopen("8.in", "wb", stdout);
	puts("5 9");
	puts("1 1");
	puts("1 2");
	puts("2 2");
	puts("3 2");
	puts("3 3");
	puts("1 1");
	puts("1 2");
	puts("1 3");
	puts("2 1");
	puts("2 2");
	puts("2 3");
	puts("3 1");
	puts("3 2");
	puts("3 3");
	fclose(stdout);
	return 0;
}
