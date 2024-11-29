#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
string ending(int x)
{
    x%=100;
    if(x/10==1) return "th";
    if(x%10==1) return "st";
    if(x%10==2) return "nd";
    if(x%10==3) return "rd";
    return "th";
}
const string c="%d out of %d numbers incorrect (first at %d%s, expected %d, found %d)";
int main(int argc,char* argv[])
{
    registerInteraction(argc,argv);
    ios::sync_with_stdio(0);
    int k=inf.readInt(),q=inf.readInt();
    cout<<k<<' '<<q<<endl;
    int p=q;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
			cout<<inf.readInt()<<' ';
		cout<<endl;
	}
	int wa=0,wp=0,we=0,wr=0;
    while(q--)
    {
		cout<<inf.readInt()<<' '<<inf.readInt()<<endl;
		int an=ans.readInt();
		int get;
		cin>>get;
		if(an!=get)
		{
			wa++;
			if(wa==1) wp=p-q,we=an,wr=get;
		}
	}
    if(wa) quitf(_wa,c.c_str(),wa,p,wp,ending(wp).c_str(),we,wr);
    quitf(_ok,"%d numbers",p);
    return 0;
}
