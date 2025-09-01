#include <bits/stdc++.h>
using namespace std;
#define y1 Y1
int steps(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2) return 0;
	if (x2 > x1 && y2 - y1 > x2 - x1) return 1;
	if (x1 > x2 && y1 - y2 > x1 - x2) return 1;
	return 2;
}
int main()
{
	freopen("tangent.in", "r", stdin);
	freopen("tangent.out", "w", stdout);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << steps(x1, y1, x2, y2) << endl;
	return 0;
}
