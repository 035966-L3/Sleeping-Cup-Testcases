#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sd.in", "r", stdin);
    freopen("sd.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        if (!n)
        {
            cout << "0 0" << endl;
            continue;
        }
        switch (n % 4)
        {
            case 0:
            {
                cout << n / 4 + 1 << ' ' << n / 4 - 1 << endl;
                break;
            }
            case 2:
            {
                cout << "-1 -1" << endl;
                break;
            }
            default:
            {
                cout << n / 2 + 1 << ' ' << n / 2 << endl;
                break;
            }
        }
    }
    return 0;
}
