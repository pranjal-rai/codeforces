//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int arr[60][60]={0};
int vis[60]={0};
int n;
void dfs(int v)
{
    vis[v]=1;
    for(int i=1;i<=n;i++)
        if(vis[i]==0&&arr[v][i]==1)
            dfs(i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int m,i,j,x,y,counter=0;
    cin >>n>>m;
    long long int power[61];
    power[0]=1;
    for(i=1;i<=60;i++)
        power[i]=2*power[i-1];
    queue<int> q;
    for(i=0;i<m;i++)
    {
        cin >>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0){
            counter++;
            dfs(i);}
    }
    cout <<power[n-counter]<<"\n";
    return 0;
}
