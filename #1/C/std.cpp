#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 12;
int K[N], D[N], R[N], A[N];
int move(int f, int s, int n)
{
    return (f + s + n) % n;
}
int dis(int f, int t, int n)
{
    int ans = abs(t - f);
    return min(ans, n - ans);
}
void build(int n, int d, int r, int l)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (l >= n / 2 && n % 2 == 1)
        {
            // i = 1, n = 7
            // pos: 0 1 2 3 4 5 6
            // dis: 1 0 1 2 3 3 2
            K[move(i, n / 2 + 1, n)] += -1 * A[i];
            K[move(i, n / 2 + 2, n)] += -1 * A[i];
            K[move(i, 1, n)] += 2 * A[i];
        }

        if (l >= n / 2 && n % 2 == 0)
        {
            // i = 1, n = 6
            // pos: 0 1 2 3 4 5
            // dis: 1 0 1 2 3 2
            K[move(i, n / 2 + 1, n)] += -2 * A[i];
            K[move(i, 1, n)] += 2 * A[i];
        }
        if (l < n / 2)
        {
            // i = 1, n = 8, l = 2
            // pos: 0 1 2 3 4 5 6 7
            // dis: 1 0 1 2 d d d 2
            R[move(i, l + 1, n)] += -l * A[i];
            K[move(i, l + 1, n)] += -1 * A[i];
            D[move(i, l + 1, n)] += 1 * A[i];
            R[move(i, -l, n)] += l * A[i] + A[i];
            K[move(i, -l, n)] += -1 * A[i];
            D[move(i, -l, n)] += -1 * A[i];
            K[move(i, 1, n)] += 2 * A[i];
        }
    }
}
signed main()
{
    freopen("spider.in", "r", stdin);
    freopen("spider.out", "w", stdout);
    int m, n, d, r;
    cin >> m >> n >> d >> r;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        A[x] += y;
    }
    int l = d / r;
    long long a0 = 0, d0 = 0, r0 = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (dis(0, i, n) <= l) a0 += dis(0, i, n) * r * A[i], r0 += dis(0, i, n) * A[i];
        else a0 += d * A[i], d0 += A[i];
    }
    long long a1 = 0, d1 = 0, r1 = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (dis(1, i, n) <= l) a1 += dis(1, i, n) * r * A[i], r1 += dis(1, i, n) * A[i];
        else a1 += d * A[i], d1 += A[i];
    }
    build(n, d, r, l);
    long long kk = r1 - r0 - R[1], dd = d1, rr = r1, aa = a1, ans = min(a0, a1);
    for (int i = 2; i <= n - 1; i++)
    {
        kk += K[i], dd += D[i], rr += R[i];
        rr += kk;
        aa = rr * r + dd * d;
        ans = min(ans, aa);
    }
    cout << ans << endl;
    return 0;
}
