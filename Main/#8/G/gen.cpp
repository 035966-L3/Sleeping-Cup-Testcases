#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 2;
const int M = 1e5 + 12;
int d[N][M];
map <unsigned int, int> p;
char s[10];
unsigned int x = 813699126;
inline unsigned int get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
int main()
{
	freopen("1.in", "wb", stdout);
	puts("5 15");
	puts("50 29 51 18 61 17 53 52 23 26 47 34 21 71 9");
	puts("3 10 68 15 55 11 62 39 19 60 56 67 22 13 41");
	puts("8 49 48 5 27 28 36 2 6 54 58 57 14 38 30");
	puts("35 43 74 63 20 45 66 42 65 75 31 1 73 12 64");
	puts("7 40 4 69 46 33 59 24 44 25 72 70 37 16 32");
	fclose(stdout);
	freopen("2.in", "wb", stdout);
	puts("1 1");
	puts("1");
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("10 100000");
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 99999; j++)
			printf("%d ", (i - 1) * 100000 + j);
		printf("%d\n", i * 100000);
	}
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("10 100000");
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 99999; j++)
			printf("%d ", i + (j - 1) * 10);
		printf("%d\n", i + 999990);
	}
	fclose(stdout);
	freopen("5.in", "wb", stdout);
	puts("10 100000");
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 100000; j++)
		{
			d[i][j] = get();
			p[d[i][j]] = 0;
		}
	int l = 0;
	for (map <unsigned int, int>:: iterator t = p.begin(); t != p.end(); t++)
	{
		l++;
		p[t -> first] = l;
	}
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 100000; j++)
			d[i][j] = p[d[i][j]];
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 99999; j++)
			printf("%d ", d[i][j]);
		printf("%d\n", d[i][100000]);
	}
	fclose(stdout);
	int k = 5;
	for (int t = 9; t >= 1; t--)
	{
		k++;
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		memset(d, 0, sizeof d);
		int now = 1;
		puts("10 100000");
		for (int i = 1; i <= 1000000; i++)
		{
			bool ok = false;
			do
			{
				ok = false;
				int cur = now;
				while (get() % 10 < t)
				{
					cur++;
					if (cur > 100000) cur = now;
				}
				int pos = 0;
				for (int j = 1; j <= 10; j++)
					if (!d[j][cur]) ok = true;
				if (!ok) continue;
				do pos = get() % 10 + 1; while (d[pos][cur]);
				d[pos][cur] = i;
			}
			while (!ok);
			for (int j = 1; j <= 11; j++)
			{
				if (j == 11)
				{
					now++;
					break;
				}
				if (!d[j][now]) break;
			}
		}
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 99999; j++)
				printf("%d ", d[i][j]);
			printf("%d\n", d[i][100000]);
		}
		fclose(stdout);
	}
	return 0;
}
