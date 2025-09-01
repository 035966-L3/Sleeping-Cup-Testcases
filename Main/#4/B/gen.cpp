#include <bits/stdc++.h>
#define int long long
#define y1 Y1
using namespace std;
int tc,m;
const int X=1e9,Y=2*X+1;
int rd(int x)
{
	return (1ll*rand()%(1<<20)*(1<<20)+rand()%(1<<20))%x;
}
signed main()
{
	srand(time(0));
	while(cin>>tc>>m)
	{
		stringstream ss;
		ss<<tc<<".in";
		string s;
		ss>>s;
		fclose(stdout);
		freopen(s.c_str(),"w",stdout);
		if(m==16)
		{
			int x1=rd(Y)-X,y1=rd(Y)-X;
			cout<<x1<<' '<<y1<<' '<<x1<<' '<<y1<<endl;
			continue;
		}
		if(m==0||m==4) m=4-m;
		int x1,x2,y1,y2;
		switch(min(m%8,8-m%8))
		{
			case 0:
			{
				x1=rd(Y)-X,x2=rd(Y)-X,y1=rd(Y)-X,y2=y1;
				while(x2==x1) x2=rd(Y)-X;
				if(x2<x1) swap(x2,x1);
				break;
			}
			case 1:
			{
				do
				{
					x1=rd(Y)-X,x2=rd(Y)-X,y1=rd(Y)-X,y2=y1;
					while(x2==x1) x2=rd(Y)-X;
					while(y2==y1) y2=rd(Y)-X;
					if(x2<x1) swap(x2,x1);
					if(y2<y1) swap(y2,y1);
				}
				while(x2-x1==y2-y1);
				if(x2-x1>y2-y1) swap(x1,y1),swap(x2,y2);
				break;
			}
			case 2:
			{
				x1=rd(Y)-X,y1=rd(Y)-X;
				while(abs(x1-y1)==2*X) x1=rd(Y)-X,y1=rd(Y)-X;
				int l=-min(x1+X,y1+X),r=min(X-x1,X-y1);
				int p=rd(r-l+1)+l;
				while(p==0) p=rd(r-l+1)+l;
				x2=x1+p,y2=y1+p;
				if(x2<x1) swap(x2,x1);
				if(y2<y1) swap(y2,y1);
				break;
			}
			case 3:
			{
				do
				{
					x1=rd(Y)-X,x2=rd(Y)-X,y1=rd(Y)-X,y2=y1;
					while(x2==x1) x2=rd(Y)-X;
					while(y2==y1) y2=rd(Y)-X;
					if(x2<x1) swap(x2,x1);
					if(y2<y1) swap(y2,y1);
				}
				while(x2-x1==y2-y1);
				if(x2-x1<y2-y1) swap(x1,y1),swap(x2,y2);
				break;
			}
			case 4:
			{
				x1=rd(Y)-X,x2=x1,y1=rd(Y)-X,y2=rd(Y)-X;
				while(y2==y1) y2=rd(Y)-X;
				if(y2<y1) swap(y2,y1);
				break;
			}
		}
		if(m%8>=5) swap(y1,y2);
		if(m>=8) swap(x1,x2),swap(y1,y2);
		cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	}
	return 0;
}
