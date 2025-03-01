#include<bits/stdc++.h>
using namespace std;
int main(int argc,char** argv)
{
	freopen(argv[1],"r",stdin);
	string s,t="";
	while(getline(cin,s))
	{
		while(s[s.size()-1]==' ') s.erase(s.size()-1,1);
		t+=s+'\n';
	}
	fclose(stdin);
	freopen(argv[1],"w",stdout);
	cout<<t;
	return 0;
}
