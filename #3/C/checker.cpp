#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
	long double x0 = ouf.readReal(0, 1000), y0 = ouf.readReal(0, 1000), r0 = ouf.readReal(0, 1000);
	long double xx = ans.readReal(0, 1000), yy = ans.readReal(0, 1000), rr = ans.readReal(0, 1000);
	bool k1 = false, k2 = false;
	if ((xx - x0) * (xx - x0) + (yy - y0) * (yy - y0) <= 100) k1 = true;
	if ((rr - r0) * (rr - r0) <= 100) k2 = true;
	quitp(0.5 * k1 + 0.5 * k2, "Center difference is %.3llf (%s) / Radius difference is %.3llf (%s)",
			sqrtl((xx - x0) * (xx - x0) + (yy - y0) * (yy - y0)), (k1 ? "Correct" : "Incorrect"),
			fabsl(rr - r0), (k2 ? "Correct" : "Incorrect"));
	return 0;
}