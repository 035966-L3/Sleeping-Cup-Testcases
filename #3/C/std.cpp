#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	int n = 100000, r = 1000;
	long long oc = 0;
	long double xs = 0, ys = 0;
	for (int i = 1; i <= n; i++)
	{
		long double x, y;
		int z;
		cin >> x >> y >> z;
		if (z) oc++, xs += x, ys += y;
	}
	cout << fixed << setprecision(3);
	cout << xs / oc << ' ' << ys / oc << endl;
	cout << sqrtl(oc * 1.0 * r * r / n / acos(-1)) << endl;
	return 0;
}
