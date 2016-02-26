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

LL n,m,i,x,ans1=0,ans2=0;
set<LL>s;
int main()
{
    FastIO(); 
    cin >>n>>m;
    x=3;
    for(i=0;i<m;i++)
    {
        s.insert(x);
        ans1=max(ans1,x);
        x=x+3;
    }
    x=2;
    for(i=0;i<n;i++)
    {
        if(s.find(x)!=s.end())
        {
            i--;
            x=x+2;
            continue;
        }
        else
        {
            s.insert(x);
            ans1=max(ans1,x);
            x=x+2;
        }
    }
    s.clear();
    x=2;
    for(i=0;i<n;i++)
    {
        s.insert(x);
        ans2=max(ans2,x);
        x=x+2;
    }
    x=3;
    for(i=0;i<m;i++)
    {
        if(s.find(x)!=s.end())
        {
            i--;
            x=x+3;
            continue;
        }
        else
        {
            s.insert(x);
            ans2=max(ans2,x);
            x=x+3;
        }
    }
     cout<<min(ans1,ans2)<<"\n";   
    return 0;
}
