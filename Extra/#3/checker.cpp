#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
long double w[6][1012];
inline long double dis(long double a,long double b,long double c,long double d)
{
    return sqrtl((c-a)*(c-a)+(d-b)*(d-b));
}
inline bool blunt(long double a,long double b,long double c)
{
    return (a*a+c*c<b*b||a*a+b*b<c*c);
}
inline long double height(long double a,long double b,long double c)
{
    long double p=(a+b+c)/2;
    return 2*sqrtl(p*(p-a)*(p-b)*(p-c))/a;
}
inline long double check(long double dx,long double dy,int p)
{
    long double c=dis(dx,dy,w[0][p],w[1][p]);
    long double b=dis(dx,dy,w[2][p],w[3][p]);
    long double a=dis(w[0][p],w[1][p],w[2][p],w[3][p]);
    long double res=min(b,c);
    res=min(res,dis(dx,dy,w[4][p],w[5][p]));
    if(!blunt(a,b,c)) res=min(res,height(a,b,c));
    return res;
}
int main(int argc,char** argv)
{
    registerTestlibCmd(argc,argv);
    int n=inf.readInt();
    for(int i=1;i<=n;i++)
        for(int j=0;j<=5;j++)
            w[j][i]=inf.readInt();
    long double dx=ouf.readDouble(0,10000);
    long double dy=ouf.readDouble(0,10000);
    long double dz=0;
    for(int i=1;i<=n;i++)
        dz=max(dz,check(dx,dy,i));
    ans.readDouble();
    ans.readDouble();
    long double s1=ans.readDouble();
    long double s2=ans.readDouble();
    long double s0=0;
    if(dz<=s1) s0=1;
    if(dz<s2&&dz>s1) s0=(s2-dz)/(s2-s1);
    quitp(s0,"R = %.8Lf",dz);
    return 0;
}
