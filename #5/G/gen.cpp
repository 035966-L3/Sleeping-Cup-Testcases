#include <bits/stdc++.h> 
#define int long long
#define rand randrand
using namespace std;
string tc;
int n, m0, m1, m2;
const int I = 1e9;
unsigned int seed = time(0);
inline unsigned int rand()
{
	seed ^= seed << 9;
	seed ^= seed >> 25;
	seed ^= seed << 14;
	return seed;
}
int rands()
{
	return rand() % (1 << 10) * (1 << 10) + rand() % (1 << 10);
}
int rd(int x)
{
	return (rands() % (1 << 20) * (1 << 20) + rands() % (1 << 20)) % x;
}
struct P
{
	int x, y, z;
};
bool invalid(P x)
{
	return (abs(x.x) > I || abs(x.y) > I || abs(x.z) > I);
}
P operator-(P x, P y)
{
	return (P){x.x - y.x, x.y - y.y, x.z - y.z};
}
P operator*(P x, int y)
{
	return (P){x.x * y, x.y * y, x.z * y};
}
P normal(P x, P y, P z)
{
	P a = x - y, b = x - z;
	int nx = a.y * b.z - a.z * b.y;
	int ny = a.z * b.x - a.x * b.z;
	int nz = a.x * b.y - a.y * b.x;
	return (P){nx, ny, nz};
}
bool operator==(P x, P y)
{
	int rt1 = 0, rt2 = 0;
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
	return x.x * y.x + x.y * y.y + x.z * y.z == 0;
}
P randp(int Y, int X)
{
	return (P){rd(Y) - X, rd(Y) - X, rd(Y) - X};
}
struct Q
{
	P x;
	int id, val;
};
bool cmp(Q x, Q y)
{
	return x.val < y.val;
}
bool operator < (P x, P y)
{
	if (x.x != y.x) return x.x < y.x;
	if (x.y != y.y) return x.y < y.y;
	return x.z < y.z;
}
const int X[8] = {0, (int) 1.5e3, (int) 5e8, (int) 1.5e6, (int) 1.5e8, (int) 1.5e4, (int) 1.5e2, (int) 3e5};
const int Y[8] = {0, 2 * X[1] + 1, 2 * X[2] + 1, 2 * X[3] + 1, 2 * X[4] + 1, 2 * X[5] + 1, 2 * X[6] + 1, 2 * X[7] + 1};
const int N = 2e4 + 12;
const P E = (P){0, 0, 0};
P in[N];
Q ins[N];
int pri[N];
string s1, s2;
int gen(int n, int m0, int m1, int m2)
{
	map<P, bool> mp;
	cout << n << endl;
	switch (m0)
	{
		case 1:
		{
			in[1] = randp(Y[2], X[2]), in[2] = randp(Y[2], X[2]);
			P v1 = randp(Y[1], X[1]), v2 = randp(Y[1], X[1]);
			while (v1 == E) v1 = randp(Y[1], X[1]);
			while (v2 == v1) v2 = randp(Y[1], X[1]);
			P nv = normal(in[1] - v1, in[1] - v2, in[1]);
			while (normal(in[1] - v1, in[1] - v2, in[1] - in[2]) == nv) in[2] = randp(Y[2], X[2]);
			mp[in[1]] = mp[in[2]] = true;
			for (int i = 3; i <= 2 * n - 1; i += 2)
			{
				int d1 = rd(Y[3]) - X[3], d2 = rd(Y[3]) - X[3];
				P d0 = E - v1 * d1 - v2 * d2;
				while (invalid(in[1] - d0) || invalid(in[2] - d0))
				{
					d1 = rd(Y[3]) - X[3], d2 = rd(Y[3]) - X[3];
					d0 = E - v1 * d1 - v2 * d2;
				}
				if (mp.count(in[1] - d0) || mp.count(in[2] - d0))
				{
					i -= 2;
					continue;
				}
				in[i] = in[1] - d0, in[i + 1] = in[2] - d0;
				mp[in[i]] = mp[in[i + 1]] = true;
			}
			for (int i = 1; i <= 2 * n; i++)
				ins[i] = (Q){in[i], i, rd(I)};
			sort(ins + 1, ins + 2 * n + 1, cmp);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].x.x << ' ' << ins[i].x.y << ' ' << ins[i].x.z << endl;
			fclose(stdout);
			freopen(s2.c_str(), "a", stdout);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].id % 2;
			cout << endl;
			fclose(stdout);
			freopen(s1.c_str(), "a", stdout);
			break;
		}
		case 2:
		{
			in[1] = randp(Y[2], X[2]), in[2] = randp(Y[2], X[2]);
			P v1 = randp(Y[1], X[1]), v2 = randp(Y[1], X[1]);
			while (v1 == E) v1 = randp(Y[1], X[1]);
			while (v2 == v1) v2 = randp(Y[1], X[1]);
			P nv = normal(in[1] - v1, in[1] - v2, in[1]);
			while (normal(in[1] - v1, in[1] - v2, in[1] - in[2]) == nv) in[2] = randp(Y[2], X[2]);
			mp[in[1]] = mp[in[2]] = true;
			for (int i = 3; i <= 2 * n - 1; i += 2)
			{
				int d11 = rd(Y[3]) - X[3], d21 = rd(Y[3]) - X[3];
				P d01 = E - v1 * d11 - v2 * d21;
				while (invalid(in[1] - d01))
				{
					d11 = rd(Y[3]) - X[3], d21 = rd(Y[3]) - X[3];
					d01 = E - v1 * d11 - v2 * d21;
				}
				int d12 = rd(Y[3]) - X[3], d22 = rd(Y[3]) - X[3];
				P d02 = E - v1 * d12 - v2 * d22;
				while (invalid(in[2] - d02))
				{
					d12 = rd(Y[3]) - X[3], d22 = rd(Y[3]) - X[3];
					d02 = E - v1 * d12 - v2 * d22;
				}
				if (mp.count(in[1] - d01) || mp.count(in[2] - d02))
				{
					i -= 2;
					continue;
				}
				in[i] = in[1] - d01, in[i + 1] = in[2] - d02;
				mp[in[i]] = mp[in[i + 1]] = true;
			}
			for (int i = 1; i <= 2 * n; i++)
				ins[i] = (Q){in[i], i, rd(I)};
			sort(ins + 1, ins + 2 * n + 1, cmp);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].x.x << ' ' << ins[i].x.y << ' ' << ins[i].x.z << endl;
			fclose(stdout);
			freopen(s2.c_str(), "a", stdout);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].id % 2;
			cout << endl;
			fclose(stdout);
			freopen(s1.c_str(), "a", stdout);
			break;
		}
		case 3:
		{
			in[1] = randp(Y[4], X[4]);
			P v = randp(Y[1], X[1]), dd1 = randp(Y[4], X[4]), dd2 = randp(Y[5], X[5]);
			while (v == E) v = randp(Y[1], X[1]);
			while (dd1 == E) dd1 = randp(Y[4], X[4]);
			while (dd2 == dd1) dd2 = randp(Y[5], X[5]);
			int c1 = rd(Y[5]) - X[5], c2 = rd(Y[5]) - X[5];
			while (c1 == 0) c1 = rd(Y[5]) - X[5];
			while (c2 == 0) c2 = rd(Y[5]) - X[5];
			in[2] = in[1] - dd1, in[3] = in[1] - dd2 * c1, in[4] = in[1] - dd1 - dd2 * c2;
			mp[in[1]] = mp[in[2]] = mp[in[3]] = mp[in[4]] = true;
			for (int i = 5; i <= 2 * n - 3; i += 4)
			{
				int de = rd(Y[3]) - X[3];
				P d0 = E - v * de, d1 = in[1] - d0, d2 = in[2] - d0, d3 = in[3] - d0, d4 = in[4] - d0;
				while (invalid(d1) || invalid(d2) || invalid(d3) || invalid(d4))
				{
					de = rd(Y[3]) - X[3];
					d0 = E - v * de;
					d1 = in[1] - d0, d2 = in[2] - d0, d3 = in[3] - d0, d4 = in[4] - d0;
				}
				if (mp.count(d1) || mp.count(d2) || mp.count(d3) || mp.count(d4))
				{
					i -= 4;
					continue;
				}
				in[i] = d1, in[i + 1] = d2, in[i + 2] = d3, in[i + 3] = d4;
				mp[in[i]] = mp[in[i + 1]] = mp[in[i + 2]] = mp[in[i + 3]] = true;
			}
			for (int i = 1; i <= 2 * n; i++)
				ins[i] = (Q){in[i], i, rd(I)};
			sort(ins + 1, ins + 2 * n + 1, cmp);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].x.x << ' ' << ins[i].x.y << ' ' << ins[i].x.z << endl;
			fclose(stdout);
			freopen(s2.c_str(), "a", stdout);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].id % 2;
			cout << endl;
			fclose(stdout);
			freopen(s1.c_str(), "a", stdout);
			break;
		}
		default:
		{
			in[1] = randp(Y[4], X[4]), in[2] = randp(Y[4], X[4]);
			P v1 = randp(Y[6], X[6]), v2 = randp(Y[6], X[6]);
			while (v1 == E) v1 = randp(Y[6], X[6]);
			while (v2 == v1) v2 = randp(Y[6], X[6]);
			P nv = normal(in[1] - v1, in[1] - v2, in[1]);
			while (normal(in[1] - v1, in[1] - v2, in[1] - in[2]) == nv) in[2] = randp(Y[4], X[4]);
			if (m1 > 0) mp[in[1]] = true;
			if (m2 > 0) mp[in[2]] = true;
			int cc11 = rd(Y[6]) - X[6], cc12 = rd(Y[6]) - X[6];
			while (cc11 == 0 && cc12 == 0) cc11 = rd(Y[6]) - X[6], cc12 = rd(Y[6]) - X[6];
			int cc13 = rd(Y[6]) - X[6], cc14 = rd(Y[6]) - X[6];
			while (cc13 == 0 && cc14 == 0) cc13 = rd(Y[6]) - X[6], cc14 = rd(Y[6]) - X[6];
			P l11 = E - v1 * cc11 - v2 * cc12, l12 = E - v1 * cc13 - v2 * cc14;
			int cc15 = rd(Y[3]) - X[3], cc16 = rd(Y[3]) - X[3];
			while (cc15 * cc12 == cc16 * cc11) cc15 = rd(Y[3]) - X[3], cc16 = rd(Y[3]) - X[3];
			in[2 * n - 1] = in[1] - v1 * cc15 - v2 * cc16;
			int cc21 = rd(Y[6]) - X[6], cc22 = rd(Y[6]) - X[6];
			while (cc21 == 0 && cc22 == 0) cc21 = rd(Y[6]) - X[6], cc22 = rd(Y[6]) - X[6];
			int cc23 = rd(Y[6]) - X[6], cc24 = rd(Y[6]) - X[6];
			while (cc23 == 0 && cc24 == 0) cc23 = rd(Y[6]) - X[6], cc24 = rd(Y[6]) - X[6];
			P l21 = E - v1 * cc21 - v2 * cc22, l22 = E - v1 * cc23 - v2 * cc24;
			int cc25 = rd(Y[3]) - X[3], cc26 = rd(Y[3]) - X[3];
			while (cc25 * cc22 == cc26 * cc21) cc25 = rd(Y[3]) - X[3], cc26 = rd(Y[3]) - X[3];
			in[2 * n] = in[2] - v1 * cc25 - v2 * cc26;
			mp[in[2 * n - 1]] = mp[in[2 * n]] = true;
			for (int i = 1; i <= 2 * n - 3; i += 2)
			{
				if (2 * m1 >= i)
				{
					if (i == 1) continue;
					int de = rd(Y[7]) - X[7];
					P d0 = E - l12 * de, d1 = in[1] - d0;
					while (invalid(d1))
					{
						de = rd(Y[7]) - X[7];
						d0 = E - l12 * de;
						d1 = in[1] - d0;
					}
					if (mp.count(d1))
					{
						i -= 2;
						continue;
					}
					in[i] = d1;
					mp[in[i]] = true;
				}
				else
				{
					int de = rd(Y[7]) - X[7];
					P d0 = E - l11 * de, d1 = in[2 * n - 1] - d0;
					while (invalid(d1))
					{
						de = rd(Y[7]) - X[7];
						d0 = E - l11 * de;
						d1 = in[2 * n - 1] - d0;
					}
					if (mp.count(d1))
					{
						i -= 2;
						continue;
					}
					in[i] = d1;
					if (m1 != -1) mp[in[i]] = true;
				}
			}
			for (int i = 2; i <= 2 * n - 2; i += 2)
			{
				if (2 * m2 >= i)
				{
					if (i == 2) continue;
					int de = rd(Y[7]) - X[7];
					P d0 = E - l22 * de, d1 = in[2] - d0;
					while (invalid(d1))
					{
						de = rd(Y[7]) - X[7];
						d0 = E - l22 * de;
						d1 = in[2] - d0;
					}
					if (mp.count(d1))
					{
						i -= 2;
						continue;
					}
					in[i] = d1;
					mp[in[i]] = true;
				}
				else
				{
					int de = rd(Y[7]) - X[7];
					P d0 = E - l21 * de, d1 = in[2 * n] - d0;
					while (invalid(d1))
					{
						de = rd(Y[7]) - X[7];
						d0 = E - l21 * de;
						d1 = in[2 * n] - d0;
					}
					if (mp.count(d1))
					{
						i -= 2;
						continue;
					}
					in[i] = d1;
					if (m2 != -1) mp[in[i]] = true;
				}
			}
			if (m1 == -1)
			{
				for (int i = 1; i <= 2 * n - 3; i += 2)
				{
					int d11 = rd(Y[7]) - X[7], d21 = rd(Y[7]) - X[7];
					P d01 = E - v1 * d11 - v2 * d21;
					while (invalid(in[2 * n - 1] - d01))
					{
						d11 = rd(Y[7]) - X[7], d21 = rd(Y[7]) - X[7];
						d01 = E - v1 * d11 - v2 * d21;
					}
					if (mp.count(in[2 * n - 1] - d01))
					{
						i -= 2;
						continue;
					}
					in[i] = in[2 * n - 1] - d01;
					mp[in[i]] = true;
				}
			}
			if (m2 == -1)
			{
				for (int i = 2; i <= 2 * n - 2; i += 2)
				{
					int d11 = rd(Y[7]) - X[7], d21 = rd(Y[7]) - X[7];
					P d01 = E - v1 * d11 - v2 * d21;
					while (invalid(in[2 * n] - d01))
					{
						d11 = rd(Y[7]) - X[7], d21 = rd(Y[7]) - X[7];
						d01 = E - v1 * d11 - v2 * d21;
					}
					if (mp.count(in[2 * n] - d01))
					{
						i -= 2;
						continue;
					}
					in[i] = in[2 * n] - d01;
					mp[in[i]] = true;
				}
			}
			for (int i = 1; i <= 2 * n; i++)
				ins[i] = (Q){in[i], i, rd(I)};
			sort(ins + 1, ins + 2 * n + 1, cmp);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].x.x << ' ' << ins[i].x.y << ' ' << ins[i].x.z << endl;
			fclose(stdout);
			freopen(s2.c_str(), "a", stdout);
			for (int i = 1; i <= 2 * n; i++)
				cout << ins[i].id % 2;
			cout << endl;
			fclose(stdout);
			freopen(s1.c_str(), "a", stdout);
			break;
		}
	}
	return 0;
}
signed main()
{
	while (cin >> tc >> n >> m0 >> m1 >> m2)
	{
		s1 = tc + ".in", s2 = tc + ".out";
		fclose(stdout);
		freopen(s1.c_str(), "w", stdout);
		fclose(stdout);
		freopen(s2.c_str(), "w", stdout);
		fclose(stdout);
		freopen(s1.c_str(), "a", stdout);
		puts("10");
		int T = 10;
		while (T--) gen(n, m0, m1, m2);
	}
	return 0;
}
