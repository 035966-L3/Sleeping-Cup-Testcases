#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 12;
bool ok[N], ans[N];
int n, k;
string s;
void fill(int i)
{
	if (ok[i]) return;
	ok[i] = true;
	int next = (i + k) % n;
	ans[next] = ans[i] ^ (s[next] - '0');
	fill(next);
}
int main()
{
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
	cin >> n >> k >> s;
	reverse(s.begin(), s.end());
	k %= n;
	for (int i = 0; i <= n - 1; i++)
		fill(i);
	for (int i = n - 1; i >= 0; i--)
		putchar(ans[i] + '0');
	return 0;
}
