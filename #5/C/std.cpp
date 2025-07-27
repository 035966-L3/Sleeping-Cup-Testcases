#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 12;
char c[N][N];
int rk[N];
int sta[N];
int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n;
        scanf("%d ", &n);
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i - 1; j++)
            {
                scanf("%c ", &c[i][j]);
                c[j][i] = '>' + '<' - c[i][j];
            }
        for (int i = 1; i <= n; i++)
        {
            rk[i] = 1;
            for (int j = 1; j <= n; j++)
                if (i != j && c[i][j] == '<') rk[i]++;
        }
        bool ok = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (rk[i] <= rk[j] && c[i][j] == '<') ok = false;
                if (rk[i] >= rk[j] && c[i][j] == '>') ok = false;
            }
        if (!ok)
        {
            for (int i = 1; i <= n - 1; i++)
               printf("-1 ");
            puts("-1");
        }
        else
        {
            for (int i = 1; i <= n; i++)
                sta[rk[i]] = i;
            for (int i = 1; i <= n - 1; i++)
               printf("%d ", sta[i]);
            printf("%d\n", sta[n]);
        }
    }
    return 0;
}
