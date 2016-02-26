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
    VPLL v;
    LL d1,d2,d3,x1,x2,x3,y1,y2,y3;
    cin >>x1>>y1>>x2>>y2>>x3>>y3;
    if((x1==x2&&x2==x3)||(y1==y2&&y2==y3))
    {
        cout<<1<<"\n";
        return 0;
    }
    v.PB(MP(x1,y1));v.PB(MP(x2,y2));v.PB(MP(x3,y3));
    sort(all(v));
    if(v[0].F==v[1].F)
    {
        if(v[2].S<=v[0].S||v[2].S>=v[1].S)
            cout <<2<<"\n";
        else
            cout <<3<<"\n";
        return 0;
    }
    if(v[1].F==v[2].F)
    {
        if(v[0].S<=v[1].S||v[0].S>=v[2].S)
            cout <<2<<"\n";
        else
            cout <<3<<"\n";
        return 0;
    }
    v.clear();
    v.PB(MP(y1,x1));v.PB(MP(y2,x2));v.PB(MP(y3,x3));
    sort(all(v));
    if(v[0].F==v[1].F)
    {
        if(v[2].S<=v[0].S||v[2].S>=v[1].S)
            cout <<2<<"\n";
        else
            cout <<3<<"\n";
        return 0;
    }
    if(v[1].F==v[2].F)
    {
        if(v[0].S<=v[1].S||v[0].S>=v[2].S)
            cout <<2<<"\n";
        else
            cout <<3<<"\n";
        return 0;
    }
    cout <<3<<"\n";
    return 0;
}
