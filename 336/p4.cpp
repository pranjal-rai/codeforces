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
int Max=INT_MAX;
LL dp[510][510];
VI v;
int cal(int l,int r)
{
    trace2(l,r);
    if(r<l)
        return 0;
    if(l==r)
        return 1;
    if(dp[l][r]!=Max)
        return dp[l][r];
    int i;
    for(i=l;i<=r;i++)
    {
        if(v[l]==v[i])
        {
            dp[l+1][i-1]=cal(l+1,i-1);
            dp[i+1][r]=cal(i+1,r);
            dp[l][r]=min(dp[l+1][i-1]+dp[i+1][r],dp[l][r]);
        }
    }
    return dp[l][r];
}
            

int main()
{
    FastIO(); 
    int n,i,j;
    cin >>n;
    v.resize(n);
    for(i=0;i<505;i++)
        for(j=0;j<505;j++)
            dp[i][j]=Max;
    for(i=0;i<n;i++)
        cin >>v[i];
    dp[0][n-1]=cal(0,n-1);
    cout <<dp[0][n-1]<<"\n";
    return 0;
}
