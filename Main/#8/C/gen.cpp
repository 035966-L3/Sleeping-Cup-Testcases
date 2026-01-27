#include <bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
	int k = 0;
	for (int i = 1; i <= 100000; i *= 10)
		for (int j = 1; j <= 9; j++)
		{
			k++;
			sprintf(s, "%d.in", k);
			freopen(s, "wb", stdout);
			cout << i * j << endl;
			fclose(stdout);
		}
	freopen("55.in", "wb", stdout);
	cout << 1000000 << endl;
	fclose(stdout);
	return 0;
}
