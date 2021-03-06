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
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector <vector<LL> > G;
VI v,v1;
//VI vis(100010,0); 
set <LL> s;
LL counter=0,m;
void dfs(LL node,LL p)
{
    LL l,i;
    l=G[node].size();
    for(i=0;i<l;i++)
    {
        if(G[node][i]==p)
            continue;
        if(v[G[node][i]]==1)
            v[G[node][i]]=v[node]+1;
        else 
            v[G[node][i]]=0;
        v1[G[node][i]]=max(v1[node],v[G[node][i]]);
        dfs(G[node][i],node);
    }
    if(l==1&&node!=1)
    {
        if(v1[node]<=m)
            counter++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL n,i,var,x,y;
    cin >>n>>m;
    G.resize(n+1);
    v.resize(n+1);
    v1.resize(n+1);
    for(i=1;i<=n;i++)
    {
        s.insert(i);
        cin >>var;
        v[i]=var;
    }
    for(i=0;i<n-1;i++)
    {
        cin >>x>>y;
        s.erase(x);
        G[x].PB(y);
        G[y].PB(x);
    }
    for(i=1;i<=n;i++)
        v1[i]=0;
    v1[1]=v[1];
    dfs(1,-1);
    cout <<counter<<"\n";
    return 0;
}
