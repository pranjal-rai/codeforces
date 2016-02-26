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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#define INF 100000000

int n, m, dp[30][30][30][30],vis[30][30][30][30];
string a[30];


bool valid(int x,int y,int i, int j)
{
    if(x==n&&y==m)
        return 1;
    return (i<n && j<m && j>=0 && i>=0 && (a[i][j]=='.' || a[i][j]=='P' || a[i][j]=='A') && (!vis[x][y][i][j]) && !(x==i&&y==j));
} 


int solve(int w,int x,int y,int z)
{
    vis[w][x][y][z]=1;
    if(dp[w][x][y][z]!=-1)
        return dp[w][x][y][z];
    if(w == y && x == z) return INF;
    if(a[w][x] == 'P') return 0;
    int ret = INF;
    if(valid(n,m,w,x+1))
    {
        bool f = 0;
        if(x+1 < z) 
        {
            if(valid(w,x+1,y,z-1)) 
            {
                ret = min(ret,solve(w, x+1, y, z-1)); f = 1;}
        }
        if(x+1 > z) 
        {
            if(valid(w,x+1,y,z+1)) 
            {ret = min(ret, solve(w, x+1, y, z+1)); f = 1;}
        }
        if(!f)
        {
            if(w < y) 
            {
                if(valid(w,x+1,y-1,z)) 
                {
                    trace4(w,x,y,z);
                    ret = min(ret,solve(w, x+1, y-1, z)); f = 1;}
            }
            if(w > y) 
            {
                if(valid(w,x+1,y,z+1)) 
                {ret = min(ret, solve(w, x+1, y+1, z)); f = 1;}
            }
        }
    }

    if(valid(n,m,w, x-1))
    {
        bool f = 0;
        if(x-1 < z) 
        {
            if(valid(w,x-1,y,z-1)) {ret = min(ret,solve(w, x-1, y, z-1)); f = 1;}
        }
        if(x-1 > z) 
        {
            if(valid(w,x-1,y,z+1)) {ret = min(ret, solve(w, x-1, y, z+1)); f = 1;}
        }
        if(!f)
        {
            if(w < y) 
            {
                if(valid(w,x-1,y-1,z)) {ret = min(ret,solve(w, x-1, y-1, z)); f = 1;}
            }
            if(w > y) 
            {
                if(valid(w,x-1,y,z+1)) {ret = min(ret, solve(w, x-1, y+1, z)); f = 1;}
            }
        }
    }

    if(valid(n,m,w+1, x))
    {
        bool f = 0;
        if(x < z) 
        {
            if(valid(w+1,x,y,z-1)) {ret = min(ret,solve(w+1, x, y, z-1)); f = 1;}
        }
        if(x > z) 
        {
            if(valid(w+1,x,y,z+1)) {ret = min(ret, solve(w+1, x, y, z+1)); f = 1;}
        }
        if(!f)
        {
            if(w+1 < y) 
            {
                if(valid(w+1,x,y-1,z)) {ret = min(ret,solve(w+1, x, y-1, z)); f = 1;}
            }
            if(w+1 > y) 
            {
                if(valid(w+1,x,y,z+1)) {ret = min(ret, solve(w+1, x, y+1, z)); f = 1;}
            }
        }
    }
    
    if(valid(n,m,w-1, x))
    {
        bool f = 0;
        if(x < z) 
        {
            if(valid(w-1,x,y,z-1)) {ret = min(ret,solve(w-1, x, y, z-1)); f = 1;}
        }
        if(x > z) 
        {
            if(valid(w-1,x,y,z+1)) {ret = min(ret, solve(w-1, x, y, z+1)); f = 1;}
        }
        if(!f)
        {
            if(w+1 < y) 
            {
                if(valid(w-1,x,y-1,z)) {ret = min(ret,solve(w-1, x, y-1, z)); f = 1;}
            }
            if(w+1 > y) 
            {
                if(valid(w-1,x,y,z+1)) {ret = min(ret, solve(w-1, x, y+1, z)); f = 1;}
            }
        }
    }
    if(ret!=INF) ret++;
    dp[w][x][y][z]=ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int ss, ff, gg, tt;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {if(a[i][j] == 'A') ff = i, ss = j; if(a[i][j] == 'G') gg = i, tt = j;}

    int ans = solve(ff, ss, gg, tt);
    if(ans == INF) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}

