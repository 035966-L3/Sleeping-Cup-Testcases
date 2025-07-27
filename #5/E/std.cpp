#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 12, P = 1e4 + 7;
int X[N][N][7];
// 0 - 6: input, A, B, C, D, A + D, B + D 
int main()
{
    freopen("record.in", "r", stdin);
    freopen("record.out", "w", stdout);
    signed n, m;
    __int128 T = 0, L = 0, E = 0;
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            scanf("%c ", &c);
            if (c == 'G') X[i][j][0] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][1] = X[i - 1][j][1] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            X[i][j][1] = max(X[i][j][1] - 1, 0);
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][2] = X[i + 1][j][2] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            X[i][j][2] = max(X[i][j][2] - 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][3] = X[i][j - 1][3] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            X[i][j][3] = max(X[i][j][3] - 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            if (X[i][j][0]) X[i][j][4] = X[i][j + 1][4] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            X[i][j][4] = max(X[i][j][4] - 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][5] = X[i - 1][j][5] + X[i - 1][j][4];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][5] -= X[i - 1][j][4];
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][6] = X[i + 1][j][6] + X[i + 1][j][4];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i][j][0]) X[i][j][6] -= X[i + 1][j][4];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            T += (__int128) X[i][j][2] * X[i][j][3] * X[i][j][4];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            L += (__int128) X[i][j][1] * X[i][j][4];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            E += (__int128) X[i][j][4] * X[i][j][5] * X[i][j][6];
    T %= P, L %= P, E %= P;
    cout << (int) T << ' ' << (int) L << ' ' << (int) E << endl;
    return 0;
}
