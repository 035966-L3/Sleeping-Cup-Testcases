#include <bits/stdc++.h>
using namespace std;
string rand_string()
{
	int l = rand() % 20 + 1;
	string res = "";
	while (l--)
	{
		char f = rand() % 52 + 65;
		if (f > 90) f += 6;
		res += f;
	}
	return res;
}
int main()
{
	freopen("1.in", "w", stdout);
	puts("1");
	puts("2");
	puts("Sleeping 7 3 5");
	puts("Cup 7 3 6");
	fclose(stdout);
	freopen("2.in", "w", stdout);
	puts("2");
	puts("1");
	puts("Sleeping 77 5 6");
	puts("3");
	puts("C 7 3 4");
	puts("h 7 3 5");
	puts("n 7 3 6");
	fclose(stdout);
	freopen("3.in", "w", stdout);
	cout << 20 << endl;
	srand(time(0));
	int T = 20;
	while (T--)
	{
		int a = rand() % 3 + 18;
		cout << a << endl;
		map <string, int> p1;
		map <long long, int> p2;
		for (int i = 1; i <= a; i++)
		{
			string b = rand_string();
			while (p1.count(b)) b = rand_string();
			int m = rand() % 100000 * 10000 + rand() % 10000 + 1;
			int n = rand() % 100000 * 10000 + rand() % 10000 + 1;
			int t = rand() % 1000 + 1;
			long long k = 1ll * t * (2ll * m + 1ll * n);
			while (p2.count(k))
			{
				m = rand() % 100000 * 10000 + rand() % 10000 + 1;
				n = rand() % 100000 * 10000 + rand() % 10000 + 1;
				t = rand() % 1000 + 1;
				k = 1ll * t * (2ll * m + 1ll * n);
			}
			p1[b] = i;
			p2[k] = i;
			cout << b << ' ' << m << ' ' << n << ' ' << t << endl;
		}
	}
	fclose(stdout);
	freopen("4.in", "w", stdout);
	cout << 20 << endl;
	T = 20;
	int j = 0;
	while (T--)
	{
		int a = rand() % 3 + 8;
		cout << a * 2 << endl;
		map <string, int> p;
		for (int i = 1; i <= a; i++)
		{
			j++;
			int s = 2999997 - rand() % 300;
			string b1 = rand_string();
			while (p.count(b1)) b1 = rand_string();
			int t1 = 1002 - 2 * j;
			int m1 = s / 3 * (t1 - 1);
			int n1 = s / 3 * (t1 - 1);
			if (s % 3 == 1) n1 += t1 - 1;
			if (s % 3 == 2) m1 += t1 - 1;
			n1++;
			p[b1] = 2 * i - 1;
			string b2 = rand_string();
			while (p.count(b2)) b2 = rand_string();
			int t2 = 1001 - 2 * j;
			int m2 = s / 3 * (t2 + 1);
			int n2 = s / 3 * (t2 + 1);
			if (s % 3 == 1) n2 += t2 + 1;
			if (s % 3 == 2) m2 += t2 + 1;
			n2++;
			p[b2] = 2 * i;
			cout << b1 << ' ' << m1 << ' ' << n1 << ' ' << t1 << endl;
			cout << b2 << ' ' << m2 << ' ' << n2 << ' ' << t2 << endl;
		}
	}
	fclose(stdout);
	return 0;
}
