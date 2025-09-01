#include <bits/stdc++.h>
using namespace std;
string rand_string()
{
	int l = rand() % 20 + 1;
	string res = "";
	while (l--)
	{
		char f = rand() % 52 + 65;
		if (f > 90) f += 6;
		res += f;
	}
	return res;
}
int main()
{
	freopen("4.in", "w", stdout);
	cout << 20 << endl;
	srand(time(0));
	int T = 20;
	int j = 0;
	while (T--)
	{
		int a = rand() % 3 + 8;
		cout << a * 2 << endl;
		map<string, int> p;
		for (int i = 1; i <= a; i++)
		{
			j++;
			int s = 2999997 - rand() % 300;
			string b1 = rand_string();
			while (p.count(b1)) b1 = rand_string();
			int t1 = 1002 - 2 * j;
			int m1 = s / 3 * (t1 - 1);
			int n1 = s / 3 * (t1 - 1);
			if (s % 3 == 1) n1 += t1 - 1;
			if (s % 3 == 2) m1 += t1 - 1;
			n1++;
			p[b1] = 2 * i - 1;
			string b2 = rand_string();
			while (p.count(b2)) b2 = rand_string();
			int t2 = 1001 - 2 * j;
			int m2 = s / 3 * (t2 + 1);
			int n2 = s / 3 * (t2 + 1);
			if (s % 3 == 1) n2 += t2 + 1;
			if (s % 3 == 2) m2 += t2 + 1;
			n2++;
			p[b2] = 2 * i;
			cout << b1 << ' ' << m1 << ' ' << n1 << ' ' << t1 << endl;
			cout << b2 << ' ' << m2 << ' ' << n2 << ' ' << t2 << endl;
		}
	}
	return 0;
}
