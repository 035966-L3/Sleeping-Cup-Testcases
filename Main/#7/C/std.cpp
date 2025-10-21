#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 12;
const int M = 2000 + 12;
const int P = 1e9 + 7;
int C[N][N];
struct Bag
{
	int n;
	int maxsum[N];
	int count[N];
};
Bag b[N];
void init()
{
	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= P) C[i][j] -= P;
		}
}
void operator+=(Bag& x, Bag y)
{
	Bag z = x;
	for (int i = 0; i <= x.n; i++)
		x.maxsum[i] = x.count[i] = 0;
	x.n = z.n + y.n;
	for (int i = 0; i <= z.n; i++)
		for (int j = 0; j <= y.n; j++)
		{
			if (z.maxsum[i] + y.maxsum[j] > x.maxsum[i + j])
			{
				x.maxsum[i + j] = z.maxsum[i] + y.maxsum[j];
				x.count[i + j] = 0;
			}
			if (z.maxsum[i] + y.maxsum[j] == x.maxsum[i + j])
			{
				x.count[i + j] += 1ll * z.count[i] * y.count[j] % P * C[i + j][i] % P;
				if (x.count[i + j] >= P) x.count[i + j] -= P;
			}
		}
}
void operator+=(Bag& x, int y)
{
	x.n++;
	for (int i = x.n; i >= 1; i--)
	{
		x.maxsum[i] = x.maxsum[i - 1] + y;
		x.count[i] = x.count[i - 1];
	}
}
struct Fk
{
	int to[M];
	int ns[M];
	int fs[N];
	int m = 0;
	void init(int n)
	{
		for (int i = 1; i <= m; i++)
			to[i] = ns[i] = 0;
		for (int i = 1; i <= n; i++)
			fs[i] = 0;
		m = 0;
	}
	void add(int f, int t)
	{
		m++;
		to[m] = t;
		ns[m] = fs[f];
		fs[f] = m;
	}
};
Fk fk;
int f[N];
int a[N];
void dfs(int x)
{
	int ii = fk.fs[x];
	while (ii)
	{
		if (fk.to[ii] != f[x])
		{
			dfs(fk.to[ii]);
			b[x] += b[fk.to[ii]];
		}
		ii = fk.ns[ii];
	}
	b[x] += a[x];
}
int main()
{
	freopen("garbage.in", "r", stdin);
	freopen("garbage.out", "w", stdout);
	init();
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n >> a[1];
		for (int i = 2; i <= n; i++)
			cin >> f[i] >> a[i];
		fk.init(n);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; i++)
			b[i].count[0] = 1;
		for (int i = 2; i <= n; i++)
		{
			fk.add(i, f[i]);
			fk.add(f[i], i);
		}
		dfs(1);
		int bs = 0;
		for (int i = 0; i <= n - 1; i++)
			b[1].maxsum[i + 1] -= i * (i + 1) / 2;
		for (int i = 0; i <= n - 1; i++)
			if (b[1].maxsum[i + 1] > b[1].maxsum[bs + 1]) bs = i;
		cout << b[1].maxsum[bs + 1] << ' ' << bs << ' ' << b[1].count[bs + 1] << endl;
	}
	return 0;
}
