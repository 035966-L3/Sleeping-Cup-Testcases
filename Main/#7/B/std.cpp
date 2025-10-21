#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12;
char s[N];
int pre[N];
int n;
int k;
int main()
{
	freopen("ricecake.in", "r", stdin);
	freopen("ricecake.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %s", &n, &k, s + 1);
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + s[i] - '0';
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '1')
			{
				int i1 = min(i + k, n);
				int i2 = max(i - k - 1, 0);
				ans += pre[i1] - pre[i2] - 1;
			}
		cout << ans / 2 << endl;
	}
	return 0;
}
