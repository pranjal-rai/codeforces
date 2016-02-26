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
int arr[100][100],check[100];
int n,i,j,x,f,counter=0;
int computemin()
{
    int ans=n;
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(check[i]==1)
            continue;
        for(j=1;j<=n;j++)
        {
            if(check[j]==1||i==j)
                continue;
            ans=min(ans,arr[i][j]);
        }
    }
    return ans;
}


int main()
{
    FastIO(); 
    VI v;
    cin >>n;
    v.resize(n+1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cin >>arr[i][j];
    }
    while(counter<n)
    {
        x=computemin();
        for(i=1;i<=n;i++)
        {
            f=1;
            if(check[i]==0)
            {
                for(j=1;j<=n;j++)
                {
                    if(j==i)
                        continue;
                    if(check[j]==1)
                        continue;
                    if(arr[i][j]!=x)
                    {
                        f=0;
                        break;
                    }
                }
                if(f==1)
                {
                    counter++;
                    v[i]=x;
                    check[i]=1;
                    break;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
        cout <<v[i]<<" ";
    cout <<"\n";
    return 0;
}

