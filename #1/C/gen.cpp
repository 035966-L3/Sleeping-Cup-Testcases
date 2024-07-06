#include<bits/stdc++.h>
using namespace std;
long long rd(int x)
{
	long long c=0;
	for(int i=1;i<=x;i++)
		c*=10,c+=rand()%10;
	return c+1;
}
long long rds(long long l,long long r)
{
	return l+rd(18)%(r-l+1);
}
int man()
{
	string s;
	cin>>s;
	s+=".in";
	freopen(s.c_str(),"w",stdout);
	bool p1,p2,p3,p4;
	cin>>p1>>p2>>p3>>p4;
	int m=90000+rd(4);
	if(p3) m=100000;
	int z;
	int n;
	cin>>z;
	switch(z)
	{
		case 2:{n=100000;break;}
		case 1:{n=99999;break;}
		default:{n=90000+rd(4);break;}
	};
	int q;
	cin>>q;
	int d=rd(8),r;
	if(p4) d=100000000;
	switch(q)
	{
		case 5:{r=rds(d+1,100000000);break;}
		case 4:{r=d;break;}
		case 3:{int l=rds(1,n/2-1);r=rds(d/(l+1),d/l);break;}
		case 2:{int l=n/2;r=rds(d/(l+1),d/l);break;}
		case 1:{int l=n/2;r=rds(1,d/l);break;}
		default:{r=rd(8);break;}
	};
	cout<<m<<' '<<n<<' '<<d<<' '<<r<<endl;
	for(int i=1;i<=m;i++)
	{
		int x=rds(0,n-1),y=rd(5);
		if(p1) x=n-1;
		if(p2) y=100000;
		if(p1==0&&p2==1&&p3==1&&z==2) x=i-1;
		cout<<x<<' '<<y<<endl;
	}
	return 0;
}
int main()
{
	while(1) man();
	return 0;
}
