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
	freopen("3.in", "w", stdout);
	cout << 20 << endl;
	srand(time(0));
	int T = 20;
	while (T--)
	{
		int a = rand() % 3 + 18;
		cout << a << endl;
		map<string, int> p1;
		map<long long, int> p2;
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
	return 0;
}
