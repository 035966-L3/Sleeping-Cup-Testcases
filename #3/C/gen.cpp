#include <bits/stdc++.h>
#define int long long 
using namespace std;
int rd(int m)
{
	int x = 0;
	x += rand();
	x *= RAND_MAX;
	x %= m;
	x += rand();
	x *= RAND_MAX;
	x %= m;
	x += rand();
	x *= RAND_MAX;
	x %= m;
	x += rand();
	x *= RAND_MAX;
	x %= m;
	x += rand();
	x *= RAND_MAX;
	x %= m;
	return x;
}
signed main(signed argc, char** argv)
{
    srand(time(0));
    int x1 = rd(1000001), x2 = rd(1000001), x3 = rd(1000001);
    while (abs(x2 - x1) < 200000 || x3 + abs(x2 - x1) > 1000000 || x3 - abs(x2 - x1) < 0 || (x2 - x1) % 2 != 0)
    	x1 = rd(1000001), x2 = rd(1000001), x3 = rd(1000001);
    if (x1 < x2) swap(x1, x2);
    freopen(argv[2], "wb", stdout);
    cout << fixed << setprecision(3);
	cout << (x1 + x2) / 2 / 1000.0 << ' ' << x3 / 1000.0 << endl;
	cout << (x1 - x2) / 2 / 1000.0 << endl;
	fclose(stdout);
	int v1 = (x1 + x2) / 2, v2 = x3, v3 = (x1 - x2) / 2;
	freopen(argv[1], "wb", stdout);
	for (int i = 1; i <= 100000; i++)
	{
		int z1 = rd(1000001), z2 = rd(1000001);
		cout << z1 / 1000.0 << ' ' << z2 / 1000.0 << ' ';
		if ((z1 - v1) * (z1 - v1) + (z2 - v2) * (z2 - v2) > v3 * v3) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}
