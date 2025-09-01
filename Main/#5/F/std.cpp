#include <bits/stdc++.h>
#define int unsigned
using namespace std;
const int N = 1 << 16, M = 1 << 18, I = (int) INT_MAX + 1;
int sum[M], invc[M];
bool rev[M];
inline int read()
{
	int x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0') x = x * 10 + c - '0', c = getchar_unlocked();
	return x;
}
inline void write(int x)
{
	if (!x) return;
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void writeline(int x)
{
	if (x) write(x);
	else putchar_unlocked('0');
	putchar_unlocked('\n');
}
inline int pairs(int x)
{
	return x * (x - 1) >> 1;
}
inline bool update(int pos, int ssz, int all)
{
	rev[pos] = !rev[pos];
	invc[pos] = all - invc[pos];
	invc[pos] -= pairs(sum[pos]);
	sum[pos] = ssz - sum[pos];
	invc[pos] -= pairs(sum[pos]);
	return rev[0];
}
inline bool pushdown(int pos, int spos, int ssz, int all)
{
	rev[pos] = !rev[pos];
	return update(spos, ssz, all) | update(spos | 1, ssz, all);
}
inline bool pushup(int pos, int spos, int ssz)
{
	sum[pos] = sum[spos] + sum[spos | 1];
	invc[pos] = invc[spos] + invc[spos | 1] + sum[spos] * (ssz - sum[spos | 1]);
	return rev[0];
}
bool reverse(int l, int r, int nl, int nr, int sz, int pos)
{
	if (l == nl && r == nr) return update(pos, sz, pairs(sz));
	int lm = (nl + nr) >> 1, rm = lm + 1, ssz = sz >> 1, spos = pos << 1;
	if (rev[pos]) pushdown(pos, spos, ssz, pairs(ssz));
	if (l <= lm) reverse(l, min(lm, r), nl, lm, ssz, spos);
	if (r >= rm) reverse(max(rm, l), r, rm, nr, ssz, spos | 1);
	return pushup(pos, spos, ssz);
}
pair <int, int> count(int l, int r, int nl, int nr, int sz, int pos)
{
	if (l == nl && r == nr) return make_pair(sum[pos], invc[pos]);
	int lm = (nl + nr) >> 1, rm = lm + 1, ssz = sz >> 1, spos = pos << 1;
	pair <int, int> al = make_pair(I, 0), ar = make_pair(I, 0);
	if (rev[pos]) pushdown(pos, spos, ssz, pairs(ssz));
	if (l <= lm) al = count(l, min(lm, r), nl, lm, ssz, spos);
	if (r >= rm) ar = count(max(rm, l), r, rm, nr, ssz, spos | 1);
	int res1 = al.first + ar.first, res2 = max(al.second, ar.second);
	if (res1 < I) res2 = al.second + ar.second + al.first * (r - lm - ar.first);
	return make_pair(res1 & INT_MAX, res2 | pushup(pos, spos, ssz));
}
signed main()
{
	freopen("inversion.in", "r", stdin);
	freopen("inversion.out", "w", stdout);
	int n = read(), q = read() << 1;
	while (q--)
	{
		int l = read(), r = read();
		if (q & 1) reverse(l, r, 0, N - 1, N, 1);
		else writeline(count(l, r, 0, N - 1, N, 1).second);
	}
	return 0;
}
