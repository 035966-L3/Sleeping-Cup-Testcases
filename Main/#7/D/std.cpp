#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 12;
const int D = 17;
const int W = 18;
int a[N];
int b[N];
int logs[N];
int st[W][W][N];
void setst(int n, int x)
{
	for (int i = 1; i <= D; i++)
		for (int j = 1; j <= n - (1 << (i - 1)); j++)
			st[x][i][j] = min(st[x][i - 1][j + (1 << (i - 1))], st[x][i - 1][j]);
}
int getst(int l, int r, int x)
{
	int y = logs[r - l + 1];
	return min(st[x][y][l], st[x][y][r - (1 << y) + 1]);
}
int main()
{
	freopen("translation.in", "r", stdin);
	freopen("translation.out", "w", stdout);
	for (int i = 1; i <= D; i++)
		logs[1 << i] = i;
	for (int i = 3; i <= N - 1; i++)
		if (!logs[i]) logs[i] = logs[i - 1];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int m = (n << 1);
		memset(st, 0x7f, sizeof st);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i + n] = a[i];
			b[a[i]] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			st[0][0][i] = b[a[i]] + 1;
			b[a[i]] = i;
		}
		for (int i = 0; i <= D; i++)
			st[i][0][1] = 1;
		setst(m, 0);
		for (int i = 1; i <= D; i++)
		{
			for (int j = 2; j <= m; j++)
				st[i][0][j] = getst(st[i - 1][0][j], j, i - 1);
			setst(m, i);
		}
		for (int i = n + 1; i <= m; i++)
		{
			int ans = 1;
			int cur = i;
			for (int j = D; j >= 0; j--)
			{
				int to = getst(cur, i, j);
				if (to > i - n)
				{
					ans += (1 << j);
					cur = to;
				}
			}
			printf("%d", ans);
			if (i < m) putchar(' ');
		}
		puts("");
	}
	return 0;
}
