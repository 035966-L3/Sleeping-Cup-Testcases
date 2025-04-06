#include <bits/stdc++.h>
using namespace std;
unsigned int n, x;
inline unsigned int get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
unsigned int f[120012];
void first()
{
    for (int i = 1; i <= (int) n; i++)
        f[i] = get();
    sort(f + 1, f + n + 1);
    cout << f[n / 2 + 1] << endl;
}
void second()
{
    unsigned int l = (1ll << 31) - (1ll << 31) * 100000 / n - 1;
    unsigned int r = (1ll << 31) + (1ll << 31) * 100000 / n;
    unsigned int low = 0, med = 0, high = 0;
    for (int i = 1; i <= (int) n; i++)
    {
        unsigned int k = get();
        if (k > r) high++;
        if (k < l) low++;
        if(k >= l && k <= r)
        {
            med++;
            f[med] = k;
        }
    }
    sort(f + 1, f + med + 1);
    cout << f[n / 2 + 1 - low] << endl;
}
int main()
{
    freopen("median.in", "r", stdin);
    freopen("median.out", "w", stdout); 
    cin >> n >> x;
    if (n <= 100001) first();
    else second();
    return 0;
}
