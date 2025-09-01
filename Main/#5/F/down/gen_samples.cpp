#include <bits/stdc++.h>
#define int unsigned
using namespace std;
int x;
inline int get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
#define discard get
const int N = 1 << 8;
bool A[N];
signed main(signed argc, char** argv)
{
	x = time(0);
	for (int i = 1; i <= N * N; i++)
		discard();
	FILE *f1 = fopen(argv[1], "wb"), *f2 = fopen(argv[2], "wb");
	fprintf(f1, "%u %u\n", N, N);
	int T = N << 1;
	while (T--)
	{
		int l = get() % N, r = get() % N;
		if (l > r) swap(l, r);
		fprintf(f1, "%u %u\n", l, r);
		if (T % 2)
		{
			for (int i = l; i <= r; i++)
				A[i] = (!A[i]);
		}
		else
		{
			int ans = 0;
			for (int i = l; i <= r - 1; i++)
				for (int j = i + 1; j <= r; j++)
					if (A[i] == true && A[j] == false) ans++;
			fprintf(f2, "%u\n", ans);
		}
	}
	return 0;
}
