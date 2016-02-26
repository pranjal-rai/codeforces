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

int main()
{
    FastIO(); 
    LL a,b,i,n,p,l,r,l1,l2,r1,r2,y,x,s,e;
    double ans=0.0;
    VPLL v;
    cin >>n>>p;
    for(i=0;i<n;i++)
    {
        cin >>l>>r;
        v.PB(MP(l,r));
    }
    for(i=0;i<n-1;i++)
    {
        l1=v[i].F;
        l2=v[i+1].F;
        r1=v[i].S;
        r2=v[i+1].S;
        x=l1;
        y=r1;
        if(x%p!=0)
            s=x/p+1;
        else
            s=x/p;
        e=y/p;
        a=(e-s+1);
        x=l2;
        y=r2;
        if(x%p!=0)
            s=x/p+1;
        else
            s=x/p;
        e=y/p;
        b=(e-s+1);
//        cout <<a*(r2-l2+1-b)+b*(r1-l1+1)<<"\n";
        ans=ans+((double)(1.0*(a*(r2-l2+1-b)+b*(r1-l1+1))))/((r1-l1+1)*(r2-l2+1));
    }
    l1=v[n-1].F;
    l2=v[0].F;
    r1=v[n-1].S;
    r2=v[0].S;
    x=l1;
    y=r1;
    if(x%p!=0)
        s=x/p+1;
    else
        s=x/p;
    e=y/p;
    a=(e-s+1);
    x=l2;
    y=r2;
    if(x%p!=0)
        s=x/p+1;
    else
        s=x/p;
    e=y/p;
    b=(e-s+1);
  //      cout <<a*(r2-l2+1-b)+b*(r1-l1+1)<<"\n";
    ans=ans+((double)(1.0*(a*(r2-l2+1-b)+b*(r1-l1+1))))/((r1-l1+1)*(r2-l2+1));
    cout <<ans*2000<<"\n";
    return 0;
}
