#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
struct Point
{
	int x, y;
};
inline bool check(Point lighting, Point query)
{
	if (query.x == lighting.x || query.y == lighting.y) return false;
	return true;
}
int main(int argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt(), q = inf.readInt();
	Point camps[n + 1];
	for (int i = 1; i <= n; i++)
		camps[i] = (Point) {inf.readInt(), inf.readInt()};
	for (int w = 1; w <= q; w++)
	{
		Point lighting = (Point) {inf.readInt(), inf.readInt()};
		int outn = ouf.readInt(-1, n), ansn = ans.readInt();
		if (outn != -1 && !check(lighting, camps[outn])) quitf(_wa, "The camp you selected was ruined. (n = %d, Query %d / %d)", n, w, q);
		if (outn == -1 && ansn != -1) quitf(_wa, "At least one of the camps was not ruined but you didn't find it. (n = %d, Query %d / %d)", n, w, q);
	}
	quitf(_ok, "Accepted! (n = %d, q = %d)", n, q);
}
