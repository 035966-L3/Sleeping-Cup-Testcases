#include <bits/stdc++.h>
using namespace std;
void output(int n,int k,string s)
{
	cout<<n<<' '<<k<<endl;
	s.erase(0,1);
	cout<<s<<endl;
}
int dfs(int n,int k,string cur,bool out)
{
	if(cur.size()>n)
	{
		if(out) output(n,k,cur);
		return 1;
	}
	return dfs(n,k,cur+'0',out)+dfs(n,k,cur+'1',out);
}
int main()
{
	string tc,m2;
	int m1;
	while(cin>>tc>>m1>>m2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		int ans=0;
		for(int i=0;i<=m1-1;i++)
			ans+=dfs(m1,i,m2,false);
		cout<<ans<<endl;
		for(int i=0;i<=m1-1;i++)
			dfs(m1,i,m2,true);
	}
	return 0;
}
