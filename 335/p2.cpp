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
int x,y;
int isvalid(int x0,int y0)
{
    if(x0<1||y0<1||x0>x||y0>y)
        return 0;
    return 1;
}
int main()
{
    FastIO(); 
    int x0,y0,i,j,steps=0,l,ans[100010]={0};
    int arr[550][550];
    init(arr,-1);
    string str;
    cin >>x>>y>>x0>>y0;
    cin >>str;
    l=str.length();
    steps=0;
    arr[x0][y0]=steps;
    for(i=0;i<l;i++)
    {
        steps++;
        if(str[i]=='L'&&isvalid(x0,y0-1))
            y0=y0-1;
        if(str[i]=='R'&&isvalid(x0,y0+1))
            y0=y0+1;
        if(str[i]=='U'&&isvalid(x0-1,y0))
            x0=x0-1;
        if(str[i]=='D'&&isvalid(x0+1,y0))
            x0=x0+1;
        if(arr[x0][y0]==-1)
        arr[x0][y0]=steps;
    }
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
            if(arr[i][j]==-1)
                arr[i][j]=steps;
    }
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++){
            ans[arr[i][j]]++;}
    }
    for(i=0;i<=l;i++)
        cout <<ans[i]<<" ";
    cout <<"\n";
    return 0;
}
