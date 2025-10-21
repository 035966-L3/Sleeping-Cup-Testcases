#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("league.in", "r", stdin);
	freopen("league.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		if (n == 1) cout << 0 << endl;
		if (n >= 2 && n <= 15) cout << n * (n - 1) * 4 - 3 << endl;
		if (n >= 16) cout << n * (n - 1) / 2 * 4 - 3 << endl;
	}
	return 0;
}
