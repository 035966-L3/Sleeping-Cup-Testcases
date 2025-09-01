#include <bits/stdc++.h>
using namespace std;
string check(string answer, string output)
{
	if (answer == output) return "Accepted.";
	int line = 1, column = 1, al = answer.size(), ol = output.size();
	stringstream conv;
	string res;
	conv << "Wrong Answer: ";
	for (int i = 0; i < min (al, ol); i++)
	{
		if (answer[i] != output[i])
		{
			if (answer[i] == '\n') conv << "Extra Character";
			else if (output[i] == '\n') conv << "Missing Character";
			else conv << "Wrong Answer";
			conv << " on Line " << line << ", Column " << column << ".";
			getline(conv, res);
			return res;
		}
		if (answer[i] == '\n') line++, column = 1;
		else column++;
	}
	if (al > ol)
	{
		if (answer[ol] == '\n') conv << "Missing Line on Line " << line + 1 <<".";
		else conv << "Missing Character on Line " << line << ", Column " << column << ".";
	}
	else
	{
		if (output[al] == '\n') conv << "Extra Line on Line " << line + 1 <<".";
		else conv << "Extra Character on Line " << line << ", Column " << column << ".";
	}
	getline(conv, res);
	return res;
}
int main()
{
	freopen("check.in", "r", stdin);
	freopen("check.out", "w", stdout);
	string ansa, out;
	stringstream s0, s1, s2;
	bool sepa = false;
	char c = getchar();
	while (c != EOF)
	{
		s0 << (int) c << endl;
		if (c == 127) sepa = true;
		else if (sepa) s2 << '*';
		else s1 << '*';
		c = getchar();
	}
	s1 >> ansa;
	s2 >> out;
	int tmp = 0, cnt = 0;
	sepa = false;
	while (s0 >> tmp)
	{
		if (tmp == 127)
		{
			sepa = true;
			cnt = 0;
		}
		else
		{
			if (sepa) out[cnt] = tmp;
			else ansa[cnt] = tmp;
			cnt++;
		}
	}
	cout << check(ansa, out);
	return 0;
}
