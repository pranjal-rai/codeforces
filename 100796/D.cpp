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
int arr1[]={-1,0,0,1};
int arr2[]={0,-1,1,0};
int n,m;
char arr[510][510];
set <pair<int,PII> > s;
set <pair<int,PII> > ::iterator it;
int vis[510][510],dis[510][510];
int isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return 0;
    return 1;
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    s.insert(MP(dis[x][y],MP(x,y)));
    int i,p,q;
    for(i=0;i<4;i++)
    {
        p=x+arr1[i];
        q=y+arr2[i];
        if(isvalid(p,q)&&arr[p][q]!='#'&&!vis[p][q])
        {
            if(arr[x][y]=='t')
                arr[p][q]='w';
            else
                arr[p][q]='t';
            dfs(p,q);
        }
    }
}
    
int main()
{
    FastIO(); 
    int a,b,i,j,k,p,q,c,d,x,y;
    cin >>n>>m>>a>>b;
    swap(n,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>arr[i][j];
            dis[i][j]=INF;
        }
    }
    arr[0][0]='t';
    dis[0][0]=0;
    dfs(0,0);
    if(!vis[n-1][m-1])
    {
        cout <<"IMPOSSIBLE\n";
        return 0;
    }
    while(!s.empty())
    {
        it=s.begin();
        d=it->F;
        x=(it->S).F;
        y=(it->S).S;
        s.erase(it);
        if(arr[x][y]=='t')
            c=b;
        else c=a;
        for(i=0;i<4;i++)
        {
            p=x+arr1[i];
            q=y+arr2[i];
            if(!isvalid(p,q)||arr[p][q]=='#')
                continue;
            if(d+c<dis[p][q])
            {
                s.erase(MP(dis[p][q],MP(p,q)));
                s.insert(MP(d+c,MP(p,q)));
                dis[p][q]=d+c;
            }
        }
    }
    cout <<dis[n-1][m-1]<<"\n";
    return 0;
}
