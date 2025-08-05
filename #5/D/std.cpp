#include <bits/stdc++.h>
using namespace std;
const int P = 1e8 + 7;
int read()
{
	int x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
		x = min(x, 1000);
	}
	return x;
}
int divs(int a, int b, int p = P)
{
	if (b % a == 0) return b / a;
	int x = divs(p % a, a - b % a, a);
	return (1ll * x * p + b) / a;
}
long long calc(long long x, long long y)
{
	return divs((833 + x * y) % P, (y * y + 2023 * x) % P);
}
signed main()
{
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	int T = read();
	while (T--)
	{
		int n = read();
		int res = n;
		for (int i = n - 1; i >= 1; i--)
			res = calc(res, i);
		cout << res << endl;
	}
	return 0;
}
