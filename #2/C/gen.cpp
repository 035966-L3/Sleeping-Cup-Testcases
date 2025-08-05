#include <bits/stdc++.h>
using namespace std;
char x[1012][1012];
int T,k,tc,m1,m2;
int rd(int x)
{
	return rand()%x;
}
void gen(int m1,int m2)
{
	switch(m1)
	{
		case 1: {k=10;break;}
		case 2: {k=8+rd(3);break;}
		case 3: {k=1000;break;}
		case 4: {k=900+rd(100);break;}
	}
	switch(m2)
	{
		case 1:
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=k;j++)
					x[i][j]='R';
			break;
		}
		case 2:
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=k;j++)
					x[i][j]='L';
			break;
		}
		case 3:
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=k;j++)
					x[i][j]='X';
			break;
		}
		case 4:
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=k;j++)
				{
					int s=rd(200);
					if(s<=1) x[i][j]='L';
					else if(s<=61) x[i][j]='X';
					else x[i][j]='R';
				}
			break;
		}
		case 5:
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=k;j++)
				{
					int s=rd(300);
					if(s<=0) x[i][j]='L';
					else if(s<=120) x[i][j]='X';
					else x[i][j]='R';
				}
			break;
		}
	}
	int w1=rd(k)+1,w2=rd(k)+1;
	x[w1][w2]='B';
	cout<<k<<endl;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
			cout<<x[i][j];
		cout<<endl;
	}
}
int main()
{
	srand(time(0));
	while(cin>>tc>>m1>>m2)
	{
		memset(x,0,sizeof x);
		stringstream ss;
		ss<<tc<<".in";
		string s;
		ss>>s;
		freopen(s.c_str(),"w",stdout);
		T=10;
		cout<<T<<endl;
		while(T--) gen(m1,m2);
		fclose(stdout);
	}
	return 0;
}
