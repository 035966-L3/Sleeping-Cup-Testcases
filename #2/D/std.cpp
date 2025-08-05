#include <bits/stdc++.h>
using namespace std;
const int K = 250 + 12;
const int L = 500 + 12;
const int M = 62500 + 12;
const int N = 125000 + 12;
const int O = 0xffff;
int alt[K][K];
pair<int, int> at[M];
int eto[M];
int k, q, A;
pair<unsigned short, unsigned short> e[N];
int ec = 0;
struct Q
{
	unsigned short id;
	unsigned short ld;
	unsigned short sz;
	unsigned short mina;
};
struct R
{
	unsigned short ld[M], sz[M], ans[M], mina[M];
	stack<Q> rec;
	void init()
	{
		for (unsigned short i = 1; i <= k * k; i++)
			ld[i] = i, sz[i] = 1;
		for (unsigned char i = 1; i <= k; i++)
			for (unsigned char j = 1; j <= k; j++)
				mina[(i - 1) * k + j] = alt[i][j];
	}
	unsigned short get(unsigned short x)
	{
		if (ld[x] == x) return x;
		ld[x] = get(ld[x]);
		return ld[x];
	}
	void mrg(int x, int y)
	{
		x = this -> get(x);
		y = this -> get(y);
		if (x == y) return;
		unsigned short xx = sz[x], yy = sz[y];
		if (xx < yy)
		{
			swap(x, y);
			swap(xx, yy);
		}
		ld[y] = x;
		sz[x] = xx + yy;
		sz[y] = 0;
		mina[x] = min(mina[x], mina[y]);
		mina[y] = O;
	}
	unsigned short get_rec(unsigned short x)
	{
		rec.push((Q) {x, ld[x], sz[x], mina[x]});
		if (ld[x] == x) return x;
		ld[x] = get_rec(ld[x]);
		return ld[x];
	}
	unsigned short mrg_rec(int x, int y, int v)
	{
		x = this -> get_rec(x);
		y = this -> get_rec(y);
		if (x == y) return 0;
		unsigned short xx = sz[x], yy = sz[y];
		if (xx < yy)
		{
			swap(x, y);
			swap(xx, yy);
		}
		ld[y] = x;
		unsigned short res = 0;
		if (mina[x] <= v && mina[y] > v) res = yy;
		if (mina[x] > v && mina[y] <= v) res = xx;
		sz[x] = xx + yy;
		sz[y] = 0;
		mina[x] = min(mina[x], mina[y]);
		mina[y] = O;
		return res;
	}
	void recover()
	{
		while (!rec.empty())
		{
			Q u = rec.top();
			rec.pop();
			ld[u.id] = u.ld;
			sz[u.id] = u.sz;
			mina[u.id] = u.mina;
		}
	}
};
R rt[L];
int main()
{
	ios::sync_with_stdio(0);
	cin >> k >> q;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			cin >> alt[i][j];
	for (int i = 0; i <= k + 1; i++)
		alt[0][i] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[k + 1][i] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[i][0] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[i][k + 1] = O;
	A = k;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			at[alt[i][j]] = make_pair(i, j);
	for (int i = 0; i <= k * k - 1; i++)
	{
		int x = at[i].first, y = at[i].second;
		if (alt[x][y + 1] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 1) * k + (y + 1));
		}
		if (alt[x][y - 1] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 1) * k + (y - 1));
		}
		if (alt[x + 1][y] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, x * k + y);
		}
		if (alt[x - 1][y] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 2) * k + y);
		}
		eto[i] = ec;
	}
	rt[0].init();
	for (int i = A, j = 1; i <= ec; i += A, j++)
	{
		rt[j] = rt[j - 1];
		for (int ii = i, jj = 1; jj <= A; ii--, jj++)
			rt[j].mrg(e[ii].first, e[ii].second);
	}
	for (int i = 0, j = 0; i <= ec; i += A, j++)
	{
		for (unsigned short ii = 1; ii <= k * k; ii++)
			if (rt[j].mina[ii] != 0xffff) rt[j].ans[rt[j].mina[ii]] += rt[j].sz[ii];
		for (unsigned short ii = 1; ii <= k * k; ii++)
			rt[j].ans[ii] += rt[j].ans[ii - 1];
	}
	for (int i = 0, j = 0; i <= ec; i += A, j++)
		for (int ii = 1; ii <= k * k; ii++)
			rt[j].get(ii);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int z = eto[y - 1] / A;
		int ans = rt[z].ans[x];
		for (int i = z * A + 1; i <= eto[y - 1]; i++)
			ans += rt[z].mrg_rec(e[i].first, e[i].second, x);
		cout << y - ans << endl;
		rt[z].recover();
	}
	return 0;
}
