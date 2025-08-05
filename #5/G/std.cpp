#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 12;
struct P
{
	int x, y, z;
};
const P E = (P){0, 0, 0};
P operator-(P x, P y)
{
	return (P){x.x - y.x, x.y - y.y, x.z - y.z};
}
bool operator==(P x, P y)
{
	__int128 rt1 = 0, rt2 = 0;
	if (x.x == 0 && y.x != 0) return false;
	if (x.x != 0 && y.x == 0) return false;
	if (x.y == 0 && y.y != 0) return false;
	if (x.y != 0 && y.y == 0) return false;
	if (x.z == 0 && y.z != 0) return false;
	if (x.z != 0 && y.z == 0) return false;
	if (x.x != 0) rt1 = x.x, rt2 = y.x;
	if (x.y != 0) rt1 = x.y, rt2 = y.y;
	if (x.z != 0) rt1 = x.z, rt2 = y.z;
	if (x.x * rt2 != y.x * rt1) return false;
	if (x.y * rt2 != y.y * rt1) return false;
	if (x.z * rt2 != y.z * rt1) return false;
	return true;
}
bool operator!=(P x, P y)
{
	return !(x == y);
}
bool straight(P x, P y)
{
	return (__int128) x.x * y.x + (__int128) x.y * y.y + (__int128) x.z * y.z == 0;
}
P simplify(P a)
{
	int d = max(abs(a.x), max(abs(a.y), abs(a.z)));
	if (a.x) d = __gcd(abs(a.x), d);
	if (a.y) d = __gcd(abs(a.y), d);
	if (a.z) d = __gcd(abs(a.z), d);
	if (a.x < 0) d = -d;
	if (a.x == 0 && a.y < 0) d = -d;
	if (a.x == 0 && a.y == 0 && a.z < 0) d = -d;
	if (d) a.x /= d, a.y /= d, a.z /= d;
	return a;
}
P in[N];
bool ans[N];
P normal(int x, int y, int z)
{
	P a = in[x] - in[y], b = in[x] - in[z];
	int nx = a.y * b.z - a.z * b.y;
	int ny = a.z * b.x - a.x * b.z;
	int nz = a.x * b.y - a.y * b.x;
	return (P){nx, ny, nz};
}
bool operator<(P x, P y)
{
	if (x.x != y.x) return x.x < y.x;
	if (x.y != y.y) return x.y < y.y;
	return x.z < y.z;
}
bool check(int x, int y, int n)
{
	if (n == 2)
	{
		P p1 = in[x], p2 = in[y], p3 = in[6 - x - y], p4 = in[4];
		if (p1 - p2 == p1 - p3 || p1 - p2 == p1 - p4) return false;
		if (p1 - p2 == p3 - p4 || normal(x, y, 6 - x - y) != normal(x, y, 4))
		{
			ans[x] = ans[y] = true;
			for (int i = 1; i <= 2 * n; i++)
				printf("%d", ans[i]);
			puts("");
			return true;
		}
		return false;
	}
	memset(ans, 0, sizeof ans);
	ans[x] = ans[y] = true;
	map<P, int> mp1, mp2;
	int line = 2;
	P curline = in[x] - in[y];
	for (int i = 1; i <= 2 * n; i++)
	{
		if (i == x || i == y) continue;
		if (in[x] - in[i] == curline)
		{
			line++;
			ans[i] = true;
			continue;
		}
		P cur = simplify(normal(x, y, i));
		if (!mp1.count(cur)) mp1[cur] = 1;
		else mp1[cur]++;
	}
	if (line == n)
	{
		for (int i = 1; i <= 2 * n; i++)
			printf("%d", ans[i]);
		puts("");
		return true;
	}
	int xx = 1;
	while (x == xx || y == xx || ans[xx]) xx++;
	int yy = xx + 1;
	while (x == yy || y == yy || ans[yy]) yy++;
	int lines = 2;
	P curlines = in[xx] - in[yy];
	for (int i = 1; i <= 2 * n; i++)
	{
		if (i == x || i == y || i == xx || i == yy) continue;
		if (in[xx] - in[i] == curlines)
		{
			lines++;
			continue;
		}
		P cur = simplify(normal(xx, yy, i));
		if (!mp2.count(cur)) mp2[cur] = 1;
		else mp2[cur]++;
	}
	if (lines == n)
	{
		memset(ans, 0, sizeof ans);
		ans[xx] = ans[yy] = true;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (i == xx || i == yy) continue;
			if (in[xx] - in[i] == curlines)
			{
				ans[i] = true;
				continue;
			}
		}
		for (int i = 1; i <= 2 * n; i++)
			printf("%d", ans[i]);
		puts("");
		return true;
	}
	for (map<P, int>:: iterator s = mp1.begin(); s != mp1.end(); s++)
	{
		if ((s -> second) != n - line) continue;
		P now = (s -> first);
		if (normal(x, y, xx) != now && normal(x, y, yy) != now)
		{
			if (!mp2.count(now)) continue;
			if (mp2[now] != n - lines) continue;
			for (int i = 1; i <= 2 * n; i++)
			{
				if (i == x || i == y || i == xx || i == yy) continue;
				if (ans[i]) continue;
				if (in[xx] - in[i] == curlines) continue;
				P cur = normal(x, y, i);
				if (cur == now) ans[i] = true;
			}
			for (int i = 1; i <= 2 * n; i++)
				printf("%d", ans[i]);
			puts("");
			return true;
		}
		else
		{
			int xxx = 1;
			while (x == xxx || y == xxx || normal(x, y, xxx) == now || ans[xxx]) xxx++;
			int yyy = xxx + 1;
			while (x == yyy || y == yyy || normal(x, y, yyy) == now || ans[yyy]) yyy++;
			bool oks = true;
			P nows = in[xxx] - in[yyy];
			if (!straight(nows, now)) oks = false;
			for (int i = 1; i <= 2 * n; i++)
			{
				if (i == x || i == y || i == xxx || i == yyy) continue;
				if (ans[i]) continue;
				if (in[xxx] - in[i] == nows) continue;
				if (normal(x, y, i) == now) continue;
				P cur = normal(xxx, yyy, i);
				if (cur != now) oks = false;
			}
			if (!oks) continue;
			for (int i = 1; i <= 2 * n; i++)
			{
				if (i == x || i == y || i == xxx || i == yyy) continue;
				if (ans[i]) continue;
				if (in[xxx] - in[i] == nows) continue;
				P cur = normal(x, y, i);
				if (cur == now) ans[i] = true;
			}
			for (int i = 1; i <= 2 * n; i++)
				printf("%d", ans[i]);
			puts("");
			return true;
		}
	}
	return false;
}
int solve()
{
	memset(ans, 0, sizeof ans);
	signed n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		signed x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		in[i] = (P){x, y, z};
	}
	if (n == 1)
	{
		puts("01");
		return 0;
	}
	if (check(1, 2, n)) return 0;
	if (check(1, 3, n)) return 0;
	if (check(2, 3, n)) return 0;
	// The two statements below will be never executed.
	puts("I hate computational geometry!!!");
	return 0;
}
signed main()
{
	freopen("surface.in", "r", stdin);
	freopen("surface.out", "w", stdout);
	signed T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
