#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int solve(int n)
{
	if (n <= 2) return n - 1;
	if (prime(n)) return n - 2;
	long long f = 1;
	int ans = 1;
	for (int i = 2; n % i != 0; i++)
	{
		f = f * i % n;
		if (f == 1) ans = i;
	}
	return ans;
}
int main()
{
	freopen("factorial.in", "r", stdin);
	freopen("factorial.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
