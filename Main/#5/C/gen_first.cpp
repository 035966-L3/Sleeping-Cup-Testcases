#include <bits/stdc++.h>
using namespace std;
void output(int n,string s)
{
	int p=0;
	cout<<n<<endl;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			p++;
			cout<<s[p];
		}
		cout<<endl;
	}
}
int dfs(int n,string cur,bool out)
{
	if(cur.size()>n*(n-1)/2)
	{
		if(out) output(n,cur);
		return 1;
	}
	return dfs(n,cur+'<',out)+dfs(n,cur+'>',out);
}
int main()
{
	string tc,m2;
	int m1;
	while(cin>>tc>>m1>>m2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		cout<<dfs(m1,m2,false)<<endl;
		dfs(m1,m2,true);
	}
	return 0;
}
