#include <bits/stdc++.h>
#define int long long
using namespace std;
int tc,m1,m2;
int rd(int x)
{
	return (1ll*rand()%(1<<20)*(1<<20)+rand()%(1<<20))%x;
}
bool prime(int x)
{
	if(x==1) return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
bool ok(int x)
{
	switch(m2)
	{
		case 2: return !prime(x);
		case 1: return prime(x);
		default: return true;
	}
}
signed main()
{
	srand(time(0));
	while(cin>>tc>>m1>>m2)
	{
		stringstream ss;
		ss<<tc<<".in";
		string s;
		ss>>s;
		fclose(stdout);
		freopen(s.c_str(),"w",stdout);
		int T=1000000;
		cout<<T<<endl;
		switch(m1)
		{
			case 1:
			{
				for(int i=1;T;i++)
					if(ok(i))
					{
						cout<<i<<endl;
						T--;
					}
				break;
			}
			case 2:
			{
				for(int i=1000000000;T;i--)
					if(ok(i))
					{
						cout<<i<<endl;
						T--;
					}
				break;
			}
			case 3:
			{
				int i=1000000000;
				while(!ok(i)) i--;
				while(T--) cout<<i<<endl;
				break;
			}
			default:
			{
				while(T)
				{
					int h=rd(1000000000)+1;
					if(ok(h))
					{
						cout<<h<<endl;
						T--;
					}
				}
				break;
			}
		}
	}
	return 0;
}
