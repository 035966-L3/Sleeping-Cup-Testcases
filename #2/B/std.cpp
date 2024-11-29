#include <bits/stdc++.h>
using namespace std;
const int K = 1000 + 12;
char x[K][K];
int main()
{
	freopen("honey1.in", "r", stdin);
	freopen("honey1.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int k, sx, sy;
		cin >> k;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
			{
				cin >> x[i][j];
				if (x[i][j] == 'B') sx = i, sy = j;
			}
		for (int i = 0; i <= k + 1; i++)
			x[0][i] = x[i][0] = x[i][k + 1] = x[k + 1][i] = 'X';
		queue<pair<int, int> > q;
		q.push(make_pair(sx, sy));
		x[sx][sy] = 'X';
		bool ok = false;
		while (!q.empty())
		{
			pair<int, int> u = q.front();
			q.pop();
			if (x[u.first][u.second + 1] == 'L')
			{
				ok = true;
				puts("Yes");
				break;
			}
			if (x[u.first][u.second + 1] != 'X')
			{
				x[u.first][u.second + 1] = 'X';
				q.push(make_pair(u.first, u.second + 1));
			}
			if (x[u.first][u.second - 1] == 'L')
			{
				ok = true;
				puts("Yes");
				break;
			}
			if (x[u.first][u.second - 1] != 'X')
			{
				x[u.first][u.second - 1] = 'X';
				q.push(make_pair(u.first, u.second - 1));
			}
			if (x[u.first + 1][u.second] == 'L')
			{
				ok = true;
				puts("Yes");
				break;
			}
			if (x[u.first + 1][u.second] != 'X')
			{
				x[u.first + 1][u.second] = 'X';
				q.push(make_pair(u.first + 1, u.second));
			}
			if (x[u.first - 1][u.second] == 'L')
			{
				ok = true;
				puts("Yes");
				break;
			}
			if (x[u.first - 1][u.second] != 'X')
			{
				x[u.first - 1][u.second] = 'X';
				q.push(make_pair(u.first - 1, u.second));
			}
		}
		if (!ok) puts("No");
	}
	return 0;
}
