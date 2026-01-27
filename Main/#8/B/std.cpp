#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
void write(int x)
{
	if (x <= 9)
	{
		putchar_unlocked(x + '0');
		return;
	}
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void write_solution(int x)
{
	write(x);
	putchar_unlocked('\n');
}
inline void write_no_solution()
{
	putchar_unlocked('-');
	putchar_unlocked('1');
	putchar_unlocked('\n');
}
struct Point
{
	int x, y, i;
};
Point p[7];
int main()
{
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	int n = read(), q = read();
	p[0] = (Point) {read(), read(), 1};
	for (int i = 2; i <= n; i++)
	{
		int x = read(), y = read();
		if (x == p[0].x && y != p[0].y) p[1] = (Point) {x, y, i};
		if (x != p[0].x && y == p[0].y) p[2] = (Point) {x, y, i};
		if (x != p[0].x && y != p[0].y)
		{
			if (!p[3].i)
			{
				p[3] = (Point) {x, y, i};
				continue;
			}
			if (x == p[3].x && y != p[3].y) p[4] = (Point) {x, y, i};
			if (x != p[3].x && y == p[3].y) p[5] = (Point) {x, y, i};
			if (x != p[3].x && y != p[3].y) p[6] = (Point) {x, y, i};
		}
			
	}
	while (q--)
	{
		int x = read(), y = read();
		for (int i = 0; i <= 7; i++)
		{
			if (i == 7)
			{
				write_no_solution();
				break;
			}
			if (x != p[i].x && y != p[i].y && p[i].i)
			{
				write_solution(p[i].i);
				break;
			}
		}
	}
	return 0;
}
