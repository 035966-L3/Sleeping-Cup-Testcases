#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, n, m;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		cout << n * m / 2 - 1 << '.' << n * m % 2 * 5 << "00\n";
	}
	return 0;
}
