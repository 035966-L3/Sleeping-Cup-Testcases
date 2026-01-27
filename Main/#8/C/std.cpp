#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 12;
const int P = 1e9 + 7;
int a[N], fc[N], ffc[N];
int divs(int a, int b = 1, int p = P)
{
	if (b % a == 0) return b / a;
	int x = divs(p % a, a - b % a, a);
	return (1ll * x * p + b) / a;
}
int main()
{
	freopen("trees.in", "r", stdin);
	freopen("trees.out", "w", stdout);
	int n;
	cin >> n;
	fc[0] = 1;
	for (int i = 1; i <= n; i++)
		fc[i] = 1ll * fc[i - 1] * i % P;
	ffc[n] = divs(fc[n]);
	for (int i = n - 1; i >= 0; i--)
		ffc[i] = 1ll * ffc[i + 1] * (i + 1) % P;
	a[1] = 1;
	for (int y = 1; y <= n; y++)
	{
		long long cur = 1;
		for (int x = y, z = 1; x <= n; x += y, z++)
		{
			cur = cur * ffc[y] % P * a[y] % P;
			long long val = 1ll * fc[x] * ffc[z] % P;
			a[x + 1] += cur * val % P;
			if (a[x + 1] >= P) a[x + 1] -= P;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += a[i];
		if (ans >= P) ans -= P;
	}
	cout << ans << endl;
	return 0;
}
