#include<bits/stdc++.h>
using namespace std;
bool rdb(double ratio)
{
    int randint=rand();
    if(ratio<1e-10) return false;
    if(ratio>(double)1-(1e-10)) return true;
    double randreal=1.0*randint/RAND_MAX;
    return (randreal<=ratio);
}
int rdi(int x)
{
    int c=0;
    for(int i=1;i<=x;i++)
        c*=10,c+=rand()%10;
    return c+1;
}
double rdf()
{
    return 1.0*rand()/RAND_MAX;
}
int generate(string tc)
{
    string filename=tc+".in";
    freopen(filename.c_str(),"wb",stdout);
    double same_rate,x_rate,xx_rate;
    int n,np;
    cin>>n>>np>>same_rate>>x_rate>>xx_rate;
    srand(time(0));
    if(same_rate<0) same_rate=rdf();
    if(x_rate<0) x_rate=rdf();
    if(xx_rate<0) xx_rate=rdf();
    n--;
    n+=rdi(np);
    printf("%d\n",n);
    bool ok=true;
    for(int i=1;i<=n-1;i++)
    {
        if(rdb(same_rate))
        {
            if(rdb(xx_rate)) puts("XX");
            else puts("ZZ");
        }
        else
        {
            ok=(!ok);
            if(rdb(x_rate)) puts("XZ");
            else puts("ZX"); 
        }
    }
    if(ok)
    {
        if(rdb(xx_rate)) puts("XX");
        else puts("ZZ");
    }
    else
    {
        ok=(!ok);
        if(rdb(x_rate)) puts("XZ");
        else puts("ZX"); 
    }
    return 0;
}
int main()
{
	srand(time(0));
    string tc;
    while(cin>>tc) generate(tc);
    return 0;
}
