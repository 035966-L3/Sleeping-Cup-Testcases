#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
bool ok(int n)
{
	if (n <= 2) return false;
	if (prime(n)) return false;
	long long f = 1;
	for (int i = 2; n % i != 0; i++)
	{
		f = f * i % n;
		if (f == 1) return true;
	}
	return false;
}
int main()
{
	freopen("12.in", "w", stdout);
	int T = 1000;
	cout << T << endl;
	for (int i = 1000000000; T; i--)
	{
		if (ok(i))
		{
			cout << i << endl;
			cerr << T << ' ' << i << endl;
			T--;
		}
		if (i % 100000 == 0) cerr << i << endl;
	}
	fclose(stdout);
	freopen("13.in", "w", stdout);
	T = 1000;
	cout << T << endl;
	for (int i = 192877198; T; i--)
	{
		if (ok(i))
		{
			cout << i << endl;
			cerr << T << ' ' << i << endl;
			T--;
		}
		if (i % 100000 == 0) cerr << i << endl;
	}
	fclose(stdout);
	freopen("14.in", "w", stdout);
	T = 0;
	for (int i = 460218; i >= 3; i--)
		if (ok(i)) T++;
	cout << 1000 << endl;
	for (int t = 1; t <= 9; t++)
		for (int i = 460218; i >= 3; i--)
			if (ok(i)) cout << i << endl;
	T *= 9;
	for (int i = 1000 - T; i >= 1; i--)
		cout << i << endl;
	fclose(stdout);
	return 0;
}
