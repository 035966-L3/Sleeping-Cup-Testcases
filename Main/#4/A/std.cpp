#include <bits/stdc++.h>
using namespace std;
const int A = 20 + 2;
struct Team
{
	string b;
	int m;
	int n;
	int t;
	long long k;
};
Team team[A];
bool cmp(Team x, Team y)
{
	return x.k > y.k;
}
int main()
{
	freopen("football.in", "r", stdin);
	freopen("football.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int a;
		cin >> a;
		for (int i = 1; i <= a; i++)
		{
			cin >> team[i].b >> team[i].m >> team[i].n >> team[i].t;
			team[i].k = 1ll * team[i].t * (2ll * team[i].m + 1ll * team[i].n);
		}
		sort(team + 1, team + a + 1, cmp);
		for (int i = 1; i <= a; i++)
		{
			cout << team[i].b;
			if (i != a) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
