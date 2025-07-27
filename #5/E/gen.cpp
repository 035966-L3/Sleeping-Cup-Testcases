#include <bits/stdc++.h>
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
int main()
{
    srand(time(0));
	string tc;
	int nn,np,tp;
	while(cin>>tc>>nn>>np>>tp)
	{
		tc+=".in";
		freopen(tc.c_str(),"w",stdout);
        int n=nn-1+rdi(np);
        int m=nn-1+rdi(np);
        cout<<n<<' '<<m<<endl;
        switch(tp)
        {
            case 1:
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        cout<<'R';
                    cout<<endl;
                }
                break;
            }
            case 2:
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                        cout<<'G';
                    cout<<endl;
                }
                break;
            }
            default:
            {
                double ratio=rdf();
                for(int i=2;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(rdb(ratio)) cout<<'R';
                        else cout<<'G';
                    }
                    cout<<endl;
                }
                break;
            }
        }
	}
	return 0;
}
