#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
char s[10];
int a[N];
bool b[N];
unsigned long long o[N];
unsigned long long x = 813699126813699126ll;
inline unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
int first(int n, int q, int u, int s, int t)
{
	int e = 0;
	cout << n << ' ' << q << endl;
	for (int i = 1; i <= 2 * n; i++)
		a[i] = get() % u + 1;
	for (int i = 1; i <= n - 1; i++)
		cout << a[i] << ' ';
	cout << a[n] << endl;
	unsigned long long B = (long double) 1.0 / t * powl(2, 64);
	for (int i = 1; i <= q / 3; i++)
		for (int j = 1; j <= 4; j++)
			o[4 * (i - 1) + j] = get() * 4 + j;
	sort(o + 1, o + q / 3 * 4 + 1);
	o[q / 3 * 4 + 1] = 0;
	for (int y = 1; y <= q / 3 * 4 + 1; y++)
	{
		int z, l, r, v, w;
		z = o[y] % 4;
		if (z == 1)
		{
			do
			{
				l = get() % n + 1;
				r = l;
				while (get() >= B) r++;
			}
			while (r > n);
			v = rand() % u + 1;
			cout << 1 << ' ' << l << ' ' << r << ' ' << v;
			for (int i = l; i <= r; i++)
				a[i] = v;
		}
		if (z == 2)
		{
			deque <long long> dq;
			do
			{
				dq.clear();
				w = get() % s + 1;
				memset(b, 0, sizeof b);
				for (int i = 1; i <= w; i++)
					b[get() % n + 1] = true;
	
				dq.push_back(0);
				for (int i = 1; i <= n; i++)
					if (b[i])
					{
						if (dq.back() % 1000000 == a[i])
						{
							long long u = dq.back();
							dq.pop_back();
							dq.push_back(u + 1000000);
							continue;
						}
						dq.push_back(1000000 + a[i]);
					}
				dq.pop_front();
			}
			while (e + dq.size() > 100000);
			cout << 2 << ' ' << dq.size();
			e += dq.size();
			while (!dq.empty())
			{
				cout << ' ' << dq.front() % 1000000 << ' ' << dq.front() / 1000000;
				dq.pop_front();
			}
		}
		if (z == 3)
		{
			do
			{
				l = get() % n + 1;
				r = l;
				while (get() >= B) r++;
			}
			while (r > n);
			v = rand() % u + 1;
			for (int i = n + l; i <= n + r; i++)
				a[i] = v;
		}
		if (z == 0)
		{
			deque <long long> dq;
			do
			{
				dq.clear();
				w = get() % s + 1;
				memset(b, 0, sizeof b);
				for (int i = 1; i <= w; i++)
					b[get() % (2 * n) + 1] = true;
				dq.push_back(0);
				for (int i = 1; i <= 2 * n; i++)
					if (b[i])
					{
						if (dq.back() % 1000000 == a[i])
						{
							long long u = dq.back();
							dq.pop_back();
							dq.push_back(u + 1000000);
							continue;
						}
						dq.push_back(1000000 + a[i]);
					}
				dq.pop_front();
			}
			while (e + dq.size() > 100000);
			cout << 2 << ' ' << dq.size();
			e += dq.size();
			while (!dq.empty())
			{
				cout << ' ' << dq.front() % 1000000 << ' ' << dq.front() / 1000000;
				dq.pop_front();
			}
		}
		if (z != 3) cout << endl;
	}
	return 0;
}
int second(int p, int q)
{
	printf("100000 %d\n", q);
	for (int i = 1; i <= 99999; i++)
		printf("%i ", i);
	puts("100000");
	for (int i = 1; i <= q; i++)
	{
		printf("2 %d", p);
		if (get() % 2)
		{
			memset(b, 0, sizeof b);
			for (int j = 1; j <= p; j++)
			{
				int c;
				do c = get() % 100000 + 1; while (b[c]);
				b[c] = true;
			}
			for (int j = 1; j <= 100000; j++)
				if (b[j]) printf(" %d 1", j);
			puts("");
			continue;
		}
		for (int j = 1; j <= p; j++)
			printf(" %d 1", get() % 100000 + 1);
		puts("");
	}
	return 0;
}
int main()
{
	freopen("1.in", "wb", stdout);
	puts("10 20");
	puts("3 4 3 4 2 1 1 4 4 3");
	puts("2 4 3 1 1 1 3 1 1 1");
	puts("2 1 3 3");
	puts("1 4 5 1");
	puts("2 3 3 1 4 1 3 2");
	puts("2 2 4 2 3 2");
	puts("1 2 9 3");
	puts("2 3 3 3 1 1 4 1");
	puts("1 5 9 2");
	puts("2 3 3 1 2 2 3 1");
	puts("1 2 2 3");
	puts("1 2 4 4");
	puts("1 6 6 2");
	puts("2 2 4 3 2 1");
	puts("2 3 2 3 3 1 4 1");
	puts("1 6 6 4");
	puts("1 1 7 2");
	puts("1 1 5 2");
	puts("2 4 2 3 3 1 2 1 1 1");
	puts("1 2 3 3");
	puts("2 1 2 3");
	fclose(stdout);
	freopen("2.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("100000 ");
	puts("100000");
	for (int i = 1; i <= 100000; i++)
		puts("2 1 100000 100000");
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("100000 1");
	for (int i = 1; i <= 99999; i++)
		printf("100000 ");
	puts("100000");
	printf("2 100000");
	for (int i = 1; i <= 100000; i++)
		printf(" 100000 1");
	puts("");
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("100000 ");
	puts("100000");
	for (int i = 1; i <= 100000; i++)
		puts("1 100000 100000 100000");
	fclose(stdout);
	freopen("5.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("100000 ");
	puts("100000");
	for (int i = 1; i <= 100000; i++)
		puts("1 1 100000 100000");
	fclose(stdout);
	freopen("6.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("100000 ");
	puts("100000");
	for (int i = 1; i <= 100000; i++)
	{
		int z = get() % 2 + 1;
		if (z == 1)
		{
			int l = get() % 100000 + 1, r = get() % 100000 + 1;
			if (l > r) swap(l, r);
			printf("1 %d %d 100000\n", l, r);
		}
		if (z == 2) printf("2 1 100000 %d\n", get() % 100000 + 1);
	}
	fclose(stdout);
	freopen("7.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("%i ", i);
	puts("100000");
	for (int i = 1; i <= 100000; i++)
		printf("2 1 %d 1\n", i);
	fclose(stdout);
	freopen("8.in", "wb", stdout);
	puts("100000 1");
	for (int i = 1; i <= 99999; i++)
		printf("%i ", i);
	puts("100000");
	printf("2 100000"); 
	for (int i = 1; i <= 100000; i++)
		printf(" %d 1", i);
	puts("");
	fclose(stdout);
	freopen("9.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 99999; i++)
		printf("%i ", i);
	puts("100000");
	for (int i = 1; i <= 100000; i++)
		printf("1 %d %d %d\n", i, i, i);
	fclose(stdout);
	int k = 9;
	for (int i = 10, j = 10000; j >= 10; i *= 10, j /= 10)
	{
		k++;
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		second(i, j);
		fclose(stdout);
	}
	for (int i1 = 10000, i2 = 27, i3 = 10; i1 >= 10; i1 /= 10, i2 *= 10, i3 *= 10)
		for (int i = 1; i <= 5; i++)
		{
			k++;
			sprintf(s, "%d.in", k);
			freopen(s, "wb", stdout);
			first(100000, i1, i1, i2, i3);
			fclose(stdout);
		}
	freopen("34.in", "wb", stdout);
	puts("100000 100000");
	for (int i = 1; i <= 49999; i++)
		printf("100000 99999 ");
	puts("100000 99999");
	for (int i = 1; i <= 50000; i++)
	{
		printf("2 1 100000 %d\n", i);
		printf("2 1 99999 %d\n", i);
	}
	fclose(stdout);
	freopen("35.in", "wb", stdout);
	puts("3 2");
	puts("1 1 1");
	puts("1 2 2 2");
	puts("2 1 1 3");
	fclose(stdout);
	return 0;
}
