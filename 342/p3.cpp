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
    int arr[600][600]={0};
    int i,j,n,k,sum=0,y;
    set<int> s;
    set<int>::iterator it;
    cin>>n>>k;
    for(i=1;i<=n*n;i++)
    {
        s.insert(i);
    }
    int x=n*n-(n-k);
    for(i=1;i<=n;i++)
    {
        arr[i][k]=x;
        s.erase(x);
        x=x-(n-k+1);
    }
    for(i=1;i<=n;i++)
    {
        x=arr[i][k];
        y=x+1;
        for(j=k+1;j<=n;j++)
        {
            arr[i][j]=y;
            s.erase(y);
            y++;
        }
    }
    for(i=n;i>=1;i--)
    {
        for(j=1;j<k;j++)
        {
            it=s.begin();
            x=*it;
            arr[i][j]=x;
            s.erase(x);
        }
    }
    for(i=1;i<=n;i++)
    {
        sum=sum+arr[i][k];
    }
    cout <<sum<<"\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout <<arr[i][j]<<" ";
        cout <<"\n";
    }
    return 0;
}

