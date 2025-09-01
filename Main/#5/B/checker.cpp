#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	for (int t = 1; t <= T; t++)
	{
		setTestCase(t);
		long long n = inf.readLong();
		long long jx = ans.readLong(-1, n), jy = ans.readLong(-1, n);
		__int128 px = ouf.readLong(-1, n), py = ouf.readLong(-1, n);
		if (px == -1 && py != -1) quitf(_wa, "Invalid output!");
		if (px != -1 && py == -1) quitf(_wa, "Invalid output!");
		if (px == -1 && jx != -1 && jy != -1) quitf(_wa, "Construction failed!");
		if (px != -1 && px * px - py * py != n) quitf(_wa, "Wrong construction!");
		if (px != -1 && px * px - py * py == n && jx == -1) quitf(_fail, "System error!");
	}
	quitf(_ok, "Accepted!");
	return 0;
}
