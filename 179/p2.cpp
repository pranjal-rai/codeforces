//techwiz911
#include<bits/stdc++.h>
#define pb push_back
#define SZ(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define gcd __gcd
#define b_c __builtin_popcount
#define mp make_pair
#define in insert
#define er erase
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define tr(c,it) for(typeof(c).begin() it=(c).begin();it!=(c).end();it++) 
#define X first
#define Y second
#define init(a,b) memset(a,b,sizeof(a))
#define n_p next_permutation
#define b_s binary_search
#define endl '\n'
#define INF INT_MAX
#define INFL LLONG_MAX
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef set<int> SI;
typedef set<LL> SLL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
int  mod = (int)1e9+7;

void FastIO()
{ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
LL modpow(LL a, LL p, LL mod)
{LL ret=1;while(p){if(p&1)ret=(ret*a)%mod;a=(a*a)%mod;p/=2;}return ret%mod;}
LL power(LL a, LL p)
{LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//Template Ends Here

LL dp[100010][4];

LL f0(char a, char b)
{
    if(a=='?' && b=='?') return 100;
    if(a=='?') return 10;
    if(b=='?') return 10;
    return 1;
}

//a is strictly greater than b
LL f1(char a, char b)
{
    if(a=='?' && b=='?') return 45;
    if(a=='?') return (9 - (b-'0'));
    if(b=='?') return (9 - (a-'0'));
    return a>b;
}

//a<b
LL f2(char a, char b)
{
    if(a=='?' && b=='?') return 45;
    if(a=='?') return (b-'0');
    if(b=='?') return (a-'0');
    return a<b;
}
//a==b
LL f3(char a, char b)
{
    if(a=='?' && b=='?') return 10;
    if(a=='?') return 1;
    if(b=='?') return 1;
    return a==b;
}

LL mult(LL a, LL b)
{
    return (a*b)%mod;
}

LL add(LL a, LL b)
{
    return (a+b)%mod;
}

int main()
{
    FastIO(); 
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    dp[0][0] = 0;
    dp[0][1] = f1(s[0], t[0]);
    dp[0][2] = f2(s[0], t[0]);
    dp[0][3] = f3(s[0], t[0]);
    for(int i=1;i<s.length();i++)
    {
        char a = s[i];
        char b = t[i];

        dp[i][0] = mult(dp[i-1][0],f0(a,b));
        dp[i][0] = add(dp[i][0], mult(dp[i-1][1], f2(a,b)));
        dp[i][0] = add(dp[i][0], mult(dp[i-1][2], f1(a,b)));

        dp[i][1] = mult(dp[i-1][1], f1(a,b));
        dp[i][1] = add(dp[i][1], mult(dp[i-1][1], f3(a,b)));
        dp[i][1] = add(dp[i][1], mult(dp[i-1][3], f1(a,b)));
        
        dp[i][2] = mult(dp[i-1][2], f2(a,b));
        dp[i][2] = add(dp[i][2], mult(dp[i-1][2], f3(a,b)));
        dp[i][2] = add(dp[i][2], mult(dp[i-1][3], f2(a,b)));

        dp[i][3] = mult(dp[i-1][3], f3(a, b));

    }
    cout<<dp[n-1][0]<<"\n";
    return 0;
}
