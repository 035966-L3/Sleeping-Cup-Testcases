#include <bits/stdc++.h>
#include "testlib.h"
#define ratio RATIO
using namespace std;
struct Ratio
{
	int x;
	int y;
};
Ratio ratio(int x)
{
	return (Ratio) {x, 1};
}
Ratio ratio(int x, int y)
{
	return (Ratio) {x / __gcd(x, y), y / __gcd(x, y)};
}
void operator+=(Ratio& l, Ratio& r)
{
	int z1 = l.x * r.y + l.y * r.x;
	int z2 = l.y * r.y;
	int z3 = __gcd(z1, z2);
	l = (Ratio) {z1 / z3, z2 / z3};
}
Ratio operator/(Ratio l, int r)
{
	l.y *= r;
	int z3 = __gcd(l.x, l.y);
	return (Ratio) {l.x / z3, l.y / z3};
}
bool operator==(Ratio x, Ratio y)
{
	return (x.x * y.y == x.y * y.x);
}
stack<Ratio> machine;
int main(int argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	int n = ouf.readInt(0, 25);
	int m = ouf.readInt(n, 2 * n);
	if (n > 7) quitf(_wa, "Your answer was worse than the jury!");
	while (m--)
	{
		int code = ouf.readInt(0, max((int) machine.size(), 1));
		if (code <= 1) machine.push(ratio(code));
		else
		{
			Ratio sum = ratio(0);
			for (int i = 1; i <= code; i++)
			{
				sum += machine.top();
				machine.pop();
			}
			for (int i = 1; i <= code; i++)
				machine.push(sum / code);
		}
	}
	while (!machine.empty())
	{
		if (machine.top() == ratio(18, 25)) quitf(_ok, "Accepted!");
		machine.pop();
	}
	quitf(_wa, "You didn't get the expected product!");
	return 0;
}
