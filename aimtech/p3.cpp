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
    int n,m,i,u,v,f,j;
    int G[510][510]={0};
    cin >>n>>m;
    for(i=0;i<m;i++)
    {
        cin >>u>>v;
        G[u-1][v-1]=1;
        G[v-1][u-1]=1;
    }
    string str="";
    str.resize(n,'d');
    for(i=0;i<n;i++)
    {
        f=1;
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(G[i][j]!=1)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            str[i]='b';
            for(j=0;j<n;j++)
                G[j][i]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i]!='b')
        {
            str[i]='a';
            for(j=0;j<n;j++)
            {
                if(G[i][j]==1)
                    str[j]='a';
            }
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            for(j=0;j<n;j++)
            {
                if(G[i][j]==1&&str[j]!='a')
                {
                    cout<<"No\n";
                    return 0;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i]!='b'&&str[i]!='a')
        {
            str[i]='c';
            for(j=0;j<n;j++)
            {
                if(G[i][j]==1)
                {
                    if(str[j]=='a')
                    {
                        cout <<"No\n";
                        return 0;
                    }
                    str[j]='c';
                }
            }
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i]=='c')
        {
            for(j=0;j<n;j++)
            {
                if(G[i][j]==1&&str[j]!='c')
                {
                    cout<<"No\n";
                    return 0;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i]=='d')
        {
            cout <<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    cout <<str<<"\n";
    return 0;
}
