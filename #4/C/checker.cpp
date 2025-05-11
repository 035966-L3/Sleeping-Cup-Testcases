#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int N = 1e6 + 12;
bool a[N], b[N], c[N];
int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	inf.readChar();
	int k = inf.readInt();
	inf.readEoln();
	string t = inf.readLine();
	reverse(t.begin(), t.end());
	string s = ouf.readLine();
	reverse(s.begin(), s.end());
	if ((int) s.size() != n) quitf(_wa, "Invalid output!");
	for (int i = 0; i <= n - 1; i++)
	{
		if (s[i] != '0' && s[i] != '1') quitf(_wa, "Invalid output!");
		c[i] = t[i] - '0';
		a[i] = s[i] - '0';
	}
	for (int i = 0; i <= n - 1; i++)
		b[i] ^= a[i];
	for (int i = 0; i <= n - 1; i++)
		b[(i + k) % n] ^= a[i];
	for (int i = 0; i <= n - 1; i++)
		if (b[i] != c[i]) quitf(_wa, "Wrong construction!");
	quitf(_ok, "Accepted!");
	return 0;
}
