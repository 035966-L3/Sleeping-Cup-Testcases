#include <bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
	int k = 0;
	for (int i = 1; i <= 10000000; i *= 10)
		for (int j = 1; j <= 9; j++)
		{
			if (i != 1 && j != 1 && j != 3) continue;
			k++;
			sprintf(s, "%d.in", k);
			freopen(s, "wb", stdout);
			cout << i * j << endl;
			fclose(stdout);
		}
	freopen("24.in", "wb", stdout);
	cout << 100000000 << endl;
	fclose(stdout);
	return 0;
}
