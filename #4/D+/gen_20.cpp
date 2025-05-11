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
	freopen("20.in", "w", stdout);
	cout << 1000000 << endl;
    string s = "";
	ifstream f1("12.in"), f2("13.in"), f3("14.in");
    string tmp = "";
    f1 >> tmp;
    for (int i = 1; i <= 1000; i++)
    {
        f1 >> tmp;
        s += tmp + "\n";
    }
    f1.close();
    f2 >> tmp;
    for (int i = 1; i <= 1000; i++)
    {
        f2 >> tmp;
        s += tmp + "\n";
    }
    f2.close();
    f3 >> tmp;
    for (int i = 1; i <= 107; i++)
    {
        f3 >> tmp;
        s += tmp + "\n";
    }
    f3.close();
    s += "2\n1\n";
    for (int i = 1; i <= 474; i++)
        cout << s;
	for (int i = 334; i >= 1; i--)
		cout << i << endl;
	return 0;
}
