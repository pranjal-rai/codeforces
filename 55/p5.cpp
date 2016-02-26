//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;

//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,k,i,x,y,z,par[3010],vis[3010][3010]={0},flag=0,l,par1,d;
    VI v;
    vector <vector<int> > G;
    map <pair<int,PII>,int> mp;
    cin >>n>>m>>k;
    G.resize(n+1);
    for(i=0;i<m;i++)
    {
        cin >>x>>y;
        G[x].PB(y);
        G[y].PB(x);
    }
    for(i=0;i<k;i++)
    {
        cin >>x>>y>>z;
        mp[MP(x,MP(y,z))]++;
    }
    queue <pair<int,PII> > q;
    q.push(MP(1,MP(-1,0)));
    par[1]=-1;
    vis[1][0]=1;
    while(!(q.empty()))
    {
        x=q.front().F,par1=(q.front()).S.F,d=(q.front()).S.S;
        if(x==n)
        {
            flag=1;
            break;
        }
        q.pop();
        l=G[x].size();
        for(i=0;i<l;i++)
        {
            if(vis[G[x][i]]==0&&mp[MP(par1,MP(x,G[x][i]))]==0)
            {
                par[G[x][i]]=x;
                vis[G[x][i]]=1;
                q.push(MP(G[x][i],MP(x,d+1)));
            }
        }
    }
    if(flag==0)
    {
        cout <<"-1\n";
        return 0;
    }
    cout <<d<<"\n";
    x=n;
    while(x!=-1)
    {
        v.PB(x);
        x=par[x];
    }
    l=v.size();
    for(i=l-1;i>=0;i--)
        cout <<v[i]<<" ";
    cout <<"\n";
    return 0;
}
