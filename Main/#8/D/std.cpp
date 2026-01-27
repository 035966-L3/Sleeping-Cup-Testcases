#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 12;
inline __int128 read()
{
	__int128 x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
inline std::string readline()
{
	std::string x = "";
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x += c;
		c = getchar_unlocked();
	}
	return x;
}
void write(__int128 x)
{
	if (x <= 9)
	{
		putchar_unlocked(x + '0');
		return;
	}
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void writeline(__int128 x)
{
	write(x);
	putchar_unlocked('\n');
}
int main()
{
	freopen("sorrow.in", "r", stdin);
	freopen("sorrow.out", "w", stdout);
	__int128 n = read(), k = read();
	string s = readline();
	reverse(s.begin(), s.end());
	s = ' ' + s;
	__int128 r = 0, ans = n * (n + 1) / 2;
	__int128 c3 = 0, c2 = 0, c23 = 0, c233 = 0, c2333 = 0;
	for (int i = 1; i <= n; i++)
	{
		while (c2333 < k && r <= n)
		{
			r++;
			if (s[r] == '2') c2++;
			if (s[r] == '3')
			{
				c3++;
				c2333 += c233;
				c233 += c23;
				c23 += c2;
			}
		}
		ans -= (r - i);
		if (s[i] == '3') c3--;
		if (s[i] == '2')
		{
			c2--;
			c2333 -= c3 * (c3 - 1) * (c3 - 2) / 6;
			c233 -= c3 * (c3 - 1) / 2;
			c23 -= c3;
		}
	}
	writeline(ans);
	return 0;
}
