#include <bits/stdc++.h>
using namespace std;
unsigned int x = 813699126;
inline unsigned int get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
char s[10];
int main()
{
	freopen("1.in", "wb", stdout);
	puts("20 16");
	puts("32323232323232323232");
	fclose(stdout);
	freopen("2.in", "wb", stdout);
	puts("1000000 1");
	for (int i = 1; i <= 1000000; i++)
		putchar('3');
	puts("");
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("1000000 1");
	for (int i = 1; i <= 1000000; i++)
		putchar('2');
	puts("");
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("1000000 1");
	for (int i = 1; i <= 750000; i++)
		putchar('3');
	for (int i = 1; i <= 250000; i++)
		putchar('2');
	puts("");
	fclose(stdout);
	freopen("5.in", "wb", stdout);
	puts("1000000 1000000000");
	for (int i = 1; i <= 750000; i++)
		putchar('3');
	for (int i = 1; i <= 250000; i++)
		putchar('2');
	puts("");
	freopen("6.in", "wb", stdout);
	puts("1000000 1000000000000000000");
	for (int i = 1; i <= 750000; i++)
		putchar('3');
	for (int i = 1; i <= 250000; i++)
		putchar('2');
	puts("");
	fclose(stdout);
	freopen("7.in", "wb", stdout);
	puts("1000000 10000000000000000000000");
	for (int i = 1; i <= 750000; i++)
		putchar('3');
	for (int i = 1; i <= 250000; i++)
		putchar('2');
	puts("");
	fclose(stdout);
	freopen("8.in", "wb", stdout);
	puts("1000000 1000000000000000000000000");
	for (int i = 1; i <= 750000; i++)
		putchar('3');
	for (int i = 1; i <= 250000; i++)
		putchar('2');
	puts("");
	fclose(stdout);
	for (int i = 9; i <= 18; i++)
	{
		sprintf(s, "%d.in", i);
		freopen(s, "wb", stdout);
		int n = get() % 100000 + 900000;
		printf("%d %d%05d%05d%05d\n", n, get() % 90000 + 10000, get() % 100000, get() % 100000, get() % 100000);
		while (n--) putchar('2' + (get() & 1));
		fclose(stdout);
	}
	return 0;
}
