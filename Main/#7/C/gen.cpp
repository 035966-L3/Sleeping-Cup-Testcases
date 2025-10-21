#include <bits/stdc++.h>
#define n f[1]
using namespace std;
int rds(int x)
{
	int c=0;
	for(int i=1;i<=x;i++)
		c*=10,c+=rand()%10;
	return c+1;
}
int rd(int x)
{
	return rds(9)%x+1;
}
int f[1012],a[1012],c[1012],d[1012][1012],p=1;
void gen(int tp1,int tp2)
{
	f[1]=900+rds(2);
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
	c[1]=d[1][1]=p=1;
	for(int i=2;i<=n;i++)
	{
		switch(tp1)
		{
			case 1:
			{
				f[i]=i-1;
				break;
			}
			case 2:
			{
				f[i]=1;
				break;
			}
			break;
			case 3:
			{
				f[i]=rd(i-1);
				break;
			}
			default:
			{
				int q=rd(p);
				if(q==p) p++;
				c[q+1]++;
				d[q+1][c[q+1]]=i;
				f[i]=d[q][rd(c[q])];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		switch(tp2)
		{
			case 1:
			{
				a[i]=1;
				break;
			}
			case 2:
			{
				a[i]=rds(2);
				break;
			}
			break;
			case 3:
			{
				if(rd(2)==1) a[i]=50;
				else a[i]=100;
				break;
			}
			default:
			{
				a[i]=rd(n);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<' '<<a[i]<<endl;
}
int main()
{
	srand(time(0));
	string tc;
	int t=20,tp1,tp2;
	while(cin>>tc>>tp1>>tp2)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
		cout<<t<<endl;
		for(int i=1;i<=t;i++)
			gen(tp1,tp2);
	}
	return 0;
}
