#include<bits/stdc++.h>
using namespace std;
int u[262][262],v[62512];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int k,q,tc,m1,m2,m3,m4,ce;
int rd(int x)
{
	return rand()%x;
}
void size()
{
	switch(m1)
	{
		case 1:{k=10,q=100;break;}
		case 2:{k=9+rd(1),q=90+rd(10);break;}
		case 3:{k=250,q=100000;break;}
		case 4:{k=225+rd(25),q=90000+rd(10000);break;}
	}
	cout<<k<<' '<<q<<endl;
}
void gen1()
{
	int ec=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ec<<' ';
			ec++;
		}
		cout<<endl;
	}
}
void gen2()
{
	int ec=k*k/2;
	for(int i=1;i<=k/2;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ec<<' ';
			ec++;
		}
		cout<<endl;
	}
	ec=0;
	for(int i=1;i<=k/2;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ec<<' ';
			ec++;
		}
		cout<<endl;
	}
}
void gen3()
{
	int ec=k;
	for(int i=1;i<=k-1;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ec<<' ';
			ec++;
		}
		cout<<endl;
	}
	ec=0;
	for(int j=1;j<=k;j++)
	{
		cout<<ec<<' ';
		ec++;
	}
	cout<<endl;
}
void gen4()
{
	int ec=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<ec<<' ';
			ec+=k*k/4;
			if(ec>=k*k) ec-=k*k,ec++;
		}
		cout<<endl;
	}
}
void gen5()
{
	memset(u,-1,sizeof u);
	int ec=0,xx=1,yy=1,w=0;
	while(1)
	{
		if(xx+dx[w]>k||xx+dx[w]<1||yy+dy[w]>k||yy+dy[w]<1) w++,w%=4;
		else if(u[xx+dx[w]+dx[w]][yy+dy[w]+dy[w]]>=0&&u[xx+dx[w]+dx[w]][yy+dy[w]+dy[w]]<k*k) w++,w%=4;
		u[xx][yy]=ec,ec++;
		if(xx==k/2+1&&yy==k/2+1) break;
		xx+=dx[w],yy+=dy[w];
	}
	ce=ec,xx=2,yy=1,w=0,ec=k*k-1;
	while(1)
	{
		if(u[xx+dx[w]][yy+dy[w]]>=0&&u[xx+dx[w]][yy+dy[w]]<k*k) w++,w%=4;
		u[xx][yy]=ec,ec--;
		if(xx==k/2+1&&yy==k/2) break;
		xx+=dx[w],yy+=dy[w];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
			cout<<u[i][j]<<' ';
		cout<<endl;
	}
}
void sh()
{
	for(int i=0;i<=k*k-1;i++)
		v[i]=i;
	shuffle(v,v+k*k,default_random_engine(time(0)));
	int ec=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<v[ec]<<' ';
			ec++;
		}
		cout<<endl;
	}
}
void fix1()
{
	while(q--) cout<<0<<' '<<k*k-1<<endl;
}
void fix2()
{
	while(q--) cout<<0<<' '<<k*k-k<<endl;
}
void fix3()
{
	while(q--) cout<<0<<' '<<k*k-k<<endl;
}
void fix4()
{
	while(q--) cout<<k*k/4-1<<' '<<k*k/2<<endl;
}
void fix5()
{
	while(q--) cout<<0<<' '<<ce<<endl;
}
void var1()
{
	while(q--)
	{
		int x=0,y=0;
		while(x==y) x=rd(k*k),y=rd(k*k);
		if(x>y) swap(x,y);
		cout<<x<<' '<<y<<endl;
	}
}
void var2()
{
	while(q--)
	{
		int x=rd(k*k/2),y=k*k/2+rd(k*k/2-k);
		cout<<x<<' '<<y<<endl;
	}
}
void var3()
{
	while(q--)
	{
		int x=rd(k),y=k+rd(k*k-2*k);
		cout<<x<<' '<<y<<endl;
	}
}
void var4()
{
	while(q--)
	{
		int x=rd(k*k/4),y=k*k/4+rd(k*k/4);
		cout<<x<<' '<<y<<endl;
	}
}
void var5()
{
	while(q--)
	{
		int x=0,y=0;
		while(x==y) x=rd(ce),y=rd(ce);
		if(x>y) swap(x,y);
		cout<<x<<' '<<y<<endl;
	}
}
void ev()
{
	while(q--)
	{
		int x=0,y=0;
		while(x==y) x=rd(k*k),y=rd(k*k);
		if(x>y) swap(x,y);
		cout<<x<<' '<<y<<endl;
	}
}
void gen()
{
	switch(m2)
	{
		case 1:{gen1();break;}
		case 2:{gen2();break;}
		case 3:{gen3();break;}
		case 4:{gen4();break;}
		case 5:{gen5();break;}
		case 0:{sh();break;}
	}
}
void fix()
{
	switch(m4)
	{
		case 1:{fix1();break;}
		case 2:{fix2();break;}
		case 3:{fix3();break;}
		case 4:{fix4();break;}
		case 5:{fix5();break;}
	}
}
void var()
{
	switch(m4)
	{
		case 1:{var1();break;}
		case 2:{var2();break;}
		case 3:{var3();break;}
		case 4:{var4();break;}
		case 5:{var5();break;}
	}
}
void ask()
{
	switch(m3)
	{
		case 1:{fix();break;}
		case 2:{var();break;}
		case 0:{ev();break;}
	}
}
int main()
{
	srand(time(0));
	while(cin>>tc>>m1>>m2>>m3>>m4)
	{
		memset(u,0,sizeof u);
		memset(v,0,sizeof v);
		stringstream ss;
		ss<<tc<<".in";
		string s;
		ss>>s;
		freopen(s.c_str(),"w",stdout);
		size();
		gen();
		ask();
		fclose(stdout);
	}
	return 0;
}
