#include <bits/stdc++.h>
#define int unsigned
using namespace std;
int x;
inline int get()
{
	x ^= x << 9;
	x ^= x >> 25;
	x ^= x << 14;
	return x;
}
#define discard get
const int N = 1 << 16, Q = 1 << 20;
signed main()
{
	x = time(0);
	for (int i = 1; i <= Q; i++)
		discard();
	freopen("1.in", "w", stdout);
	printf("%u %u\n", N, Q);
	int T = Q << 1;
	while (T--)
	{
		int l = get() % N, r = get() % N;
		if (l > r) swap(l, r);
		printf("%u %u\n", l, r);
	}
	return 0;
}
