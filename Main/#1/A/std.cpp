#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);
	int n;
	cin >> n;
	int b = 0, c = 0;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if (s == "XZ") b++, c++;
		if (s == "ZX") b--, c++;
	}
	int a = n + abs(b) / 2 + c / 2;
	cout << a << endl;
	return 0;
}
