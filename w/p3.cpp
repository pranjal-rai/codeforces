//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define SZ(a) (int)(a.size())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define n_p next_permutation
#define b_s binary_search
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)
#define gcd __gcd
#define INF INT_MAX
#define init(a,b) memset(a,b,sizeof(a))
#define INFL LLONG_MAX
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;
typedef set<int> SI;
typedef set<LL> SLL;

void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
//LL modpow(LL a,LL b,LL m){LL r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//LL power(LL a, LL p){LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector <pair<pair<double,double> ,int> > v;
int check(int x,int y,int z)
{
    double x1,y1,x2,y2,x3,y3;
    x1=v[x].F.F;
    y1=v[x].F.S;
    x2=v[y].F.F;
    y2=v[y].F.S;
    x3=v[z].F.F;
    y3=v[z].F.S;
    double f=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    if(fabs(f)<=0.000000001)
        return 1;
    return 0;
}
int main()
{
    FastIO(); 
    double x,y;
    int n,i;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>x>>y;
        v.PB(MP(MP(x,y),i+1));
    }
    sort(all(v));
    for(i=0;i<n-2;i++)
    {
        if(!check(i,i+1,i+2))
        {
            cout <<v[i].S<<" "<<v[i+1].S<<" "<<v[i+2].S<<"\n";
            return 0;
        }
    }
    return 0;
}

