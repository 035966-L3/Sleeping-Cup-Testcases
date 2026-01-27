#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 2;
const int M = 1e5 + 12;
const int D = 1 << N;
const int S = N + M;
const int T = N * M;
int b[D], e[M], t[S];
struct I
{
	int i;
	int j;
	int v;
};
I d[T];
bool cmp(I x, I y)
{
	return x.v < y.v;
}
inline int lowbit(int x)
{
	return x & (-x);
}
inline int popcount(int x)
{
	int c = 0;
	while (x)
	{
		c++;
		x -= lowbit(x);
	}
	return c;
}
int main()
{
	freopen("brooms.in", "r", stdin);
	freopen("brooms.out", "w", stdout); 
	int n, m, p, l = 0;
	scanf("%d %d", &n, &m);
	p = m - 1;
	for (int i = 1; i < (1 << n); i++)
		b[i] = m + n - popcount(i);
	for (int i = 1; i < (1 << n); i++)
		t[b[i]]++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			l++;
			scanf("%d", &d[l].v);
			d[l].i = i - 1;
			d[l].j = j;
		}
	sort(d + 1, d + l + 1, cmp);
	for (int i = l; i >= 1; i--)
	{
		int s = d[i].j, j = e[s];
		do
		{
			int o = (1 << d[i].i) | j;
			t[b[o]]--;
			b[o]--;
			t[b[o]]++;
			j = (j - 1) & e[s];
		}
		while (j != e[s]);
		e[s] |= 1 << d[i].i;
		while (t[p])
		{
			printf("%d", d[i].v);
			if (p == n - 1)
			{
				puts("");
				return 0;
			}
			putchar(' ');
			p--;
		}
	}
	return 0;
}
