#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("5.in", "w", stdout);
    srand(time(0));
	puts("1000");
    for (int i = 1; i <= 1000; i++)
    {
        cout << "1";
        for (int j = 1; j <= 1000; j++)
            cout << "0";
        cout << endl;
    }
	return 0;
}
