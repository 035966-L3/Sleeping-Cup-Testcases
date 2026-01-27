#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12;
const int D = 17;
const int E = 1 << D;
const int F = 5 * D * N;
struct I
{
	int l;
	int r;
};
bool operator<(I x, I y)
{
	if (x.l != y.l) return x.l < y.l;
	return x.r < y.r;
}
map <I, int> segs;
struct J
{
	int a;
	int b;
	int l;
	int r;
};
struct K
{
	J v[F];
	int c;
	int add(int l, int r, int ll, int rr, int k, int b)
	{
		if (!b)
		{
			c++;
			b = c;
		}
		v[b].b += (r - l + 1) * k;
		if (l == ll && r == rr)
		{
			v[b].a += k;
			return b;
		}
		int lmid = (ll + rr) >> 1, rmid = lmid + 1;
		if (r <= lmid)
		{
			v[b].l = add(l, r, ll, lmid, k, v[b].l);
			return b;
		}
		if (l >= rmid)
		{
			v[b].r = add(l, r, rmid, rr, k, v[b].r);
			return b;
		}
		v[b].l = add(l, lmid, ll, lmid, k, v[b].l);
		v[b].r = add(rmid, r, rmid, rr, k, v[b].r);
		return b;
	}
	int get(int r, int acc, int ll, int rr, int b)
	{
		if (!r) return 0;
		if (!b) return (r - ll + 1) * acc;
		if (r == rr) return v[b].b + (rr - ll + 1) * acc;
		int lmid = (ll + rr) >> 1, rmid = lmid + 1;
		if (r <= lmid) return get(r, acc + v[b].a, ll, lmid, v[b].l);
		return get(lmid, acc + v[b].a, ll, lmid, v[b].l) + get(r, acc + v[b].a, rmid, rr, v[b].r);
	}
	int search(int k, int acc, int ll, int rr, int b)
	{
		int cur = get(rr, acc, ll, rr, b);
		if (cur < k) return cur - k;
		if (ll == rr) return rr;
		int lmid = (ll + rr) >> 1, rmid = lmid + 1, ans = search(k, acc + v[b].a, ll, lmid, v[b].l);
		if (ans < 0) ans = search(-ans, acc + v[b].a, rmid, rr, v[b].r);
		return ans;
	}
};
K w;
int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	w.c = n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		w.add(i, i, 1, E, 1, x);
		segs[(I) {i, i}] = x;
	}
	while (q--)
	{
		int z, l, r, v, m, x, y;
		cin >> z;
		if (z == 1)
		{
			map <I, int> temp;
			cin >> l >> r >> v;
			map<I, int>:: iterator seg = segs.lower_bound((I) {l, 0});
			if (seg == segs.end()) seg--;
			if ((*seg).first.l > l) seg--;
			temp[(*seg).first] = (*seg).second;
			w.add((*seg).first.l, (*seg).first.r, 1, E, -1, (*seg).second);
			segs.erase(seg);
			while (1)
			{
				if (segs.empty()) break;
				map<I, int>:: iterator seg = segs.lower_bound((I) {l, 0});
				if (seg == segs.end()) break;
				if ((*seg).first.l > r) break;
				temp[(*seg).first] = (*seg).second;
				w.add((*seg).first.l, (*seg).first.r, 1, E, -1, (*seg).second);
				segs.erase(seg);
			}
			pair<I, int> t1 = (*(temp.begin()));
			if (t1.first.l < l)
			{
				segs[(I) {t1.first.l, l - 1}] = t1.second;
				w.add(t1.first.l, l - 1, 1, E, 1, t1.second);
			}
			pair<I, int> t2 = (*(temp.rbegin()));
			if (t2.first.r > r)
			{
				segs[(I) {r + 1, t2.first.r}] = t2.second;
				w.add(r + 1, t2.first.r, 1, E, 1, t2.second);
			}
			segs[(I) {l, r}] = v;
			w.add(l, r, 1, E, 1, v);
		}
		if (z == 2)
		{
			cin >> m;
			int cur = 1;
			for (int i = 1; i <= m; i++)
			{
				cin >> x >> y;
				if (cur == n + 2) continue;
				cur = w.search(w.get(cur - 1, 0, 1, E, x) + y, 0, 1, E, x) + 1;
				if (cur <= 0) cur = n + 2;
			}
			if (cur == n + 2)
			{
				puts("No");
				continue;
			}
			puts("Yes");
		}
	}
	return 0;
}
