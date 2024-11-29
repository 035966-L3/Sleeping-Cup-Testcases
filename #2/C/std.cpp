#include <bits/stdc++.h>
using namespace std;
const int K = 1000 + 12;
char x[K][K];
bool y[K][K][4];
struct S
{
	int x;
	int y;
	int w;
};
// 0 - 3: right, left, down, up
int main()
{
	freopen("honey2.in", "r", stdin);
	freopen("honey2.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(y, 0, sizeof y);
		int k;
		cin >> k;
		queue<S> q;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
			{
				cin >> x[i][j];
				if (x[i][j] == 'B') x[i][j] = 'R';
				if (x[i][j] == 'L')
				{
					for (int w = 0; w <= 3; w++)
					{
						y[i][j][w] = true;
						q.push((S) {i, j, w});
					}
				}
			}
		for (int i = 0; i <= k + 1; i++)
			x[0][i] = x[i][0] = x[i][k + 1] = x[k + 1][i] = 'X';
		while (!q.empty())
		{
			S u = q.front();
			q.pop();
			if (u.w == 0 && x[u.x][u.y + 1] != 'X')
			{
				if (!y[u.x][u.y + 1][0]) q.push((S) {u.x, u.y + 1, 0});
				if (!y[u.x][u.y + 1][2]) q.push((S) {u.x, u.y + 1, 2});
				y[u.x][u.y + 1][0] = y[u.x][u.y + 1][2] = true;
			}
			if (u.w == 1 && x[u.x][u.y - 1] != 'X')
			{
				if (!y[u.x][u.y - 1][1]) q.push((S) {u.x, u.y - 1, 1});
				if (!y[u.x][u.y - 1][3]) q.push((S) {u.x, u.y - 1, 3});
				y[u.x][u.y - 1][1] = y[u.x][u.y - 1][3] = true;
			}
			if (u.w == 2 && x[u.x + 1][u.y] != 'X')
			{
				if (!y[u.x + 1][u.y][2]) q.push((S) {u.x + 1, u.y, 2});
				if (!y[u.x + 1][u.y][1]) q.push((S) {u.x + 1, u.y, 1});
				y[u.x + 1][u.y][2] = y[u.x + 1][u.y][1] = true;
			}
			if (u.w == 3 && x[u.x - 1][u.y] != 'X')
			{
				if (!y[u.x - 1][u.y][3]) q.push((S) {u.x - 1, u.y, 3});
				if (!y[u.x - 1][u.y][0]) q.push((S) {u.x - 1, u.y, 0});
				y[u.x - 1][u.y][3] = y[u.x - 1][u.y][0] = true;
			}
		}
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
			{
				x[i][j] = 'X';
				for (int w = 0; w <= 3; w++)
					if (y[i][j][w]) x[i][j] = 'L';
			}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
				cout << x[i][j];
			cout << endl;
		}
	}
	return 0;
}
