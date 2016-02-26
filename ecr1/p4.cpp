
//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
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

void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//LL power(LL a, LL p){LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int vis[1010][1010];
char arr[1010][1010];
int ans[1010][1010];
int n,m;
int isvalid(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)
        return 0;
    return 1;
}
int main()
{
    FastIO(); 
    int k,i,j,x,y,counter,answer=0;
    cin >>n>>m>>k;
    init(ans,-1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>arr[i][j];
            if(arr[i][j]=='*')
                ans[i][j]=0;
        }
    }
    init(vis,0);
    queue <PII> q,r;
    counter=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            answer=0;
            if(ans[i][j]==-1)
            {
                q.push(MP(i,j));
                r.push(MP(i,j));
                vis[i][j]=1;
                while(!q.empty())
                {
                    x=q.front().F;
                    y=q.front().S;
                    q.pop();
                    if(isvalid(x-1,y))
                    {
                        if(arr[x-1][y]=='.'&&vis[x-1][y]==0)
                        {
                            q.push(MP(x-1,y));
                            r.push(MP(x-1,y));
                            vis[x-1][y]=1;
                        }
                        else if(arr[x-1][y]=='*')
                            answer++;
                    }
                    if(isvalid(x+1,y))
                    {
                        if(arr[x+1][y]=='.'&&vis[x+1][y]==0)
                        {
                            q.push(MP(x+1,y));
                            r.push(MP(x+1,y));
                            vis[x+1][y]=1;
                        }
                        else if(arr[x+1][y]=='*')
                            answer++;
                    }
                    if(isvalid(x,y-1))
                    {
                        if(arr[x][y-1]=='.'&&vis[x][y-1]==0)
                        {
                            q.push(MP(x,y-1));
                            r.push(MP(x,y-1));
                            vis[x][y-1]=1;
                        }
                        else if(arr[x][y-1]=='*')
                            answer++;
                    }
                    if(isvalid(x,y+1))
                    {
                        if(arr[x][y+1]=='.'&&vis[x][y+1]==0)
                        {
                            q.push(MP(x,y+1));
                            r.push(MP(x,y+1));
                            vis[x][y+1]=1;
                        }
                        else if(arr[x][y+1]=='*')
                            answer++;
                    }
                }
                counter++;
                while(!r.empty())
                {
                    x=r.front().F;
                    y=r.front().S;
                    r.pop();
                    ans[x][y]=answer;
                }
            }
        }
    }
    while(k--)
    {
        cin>>x>>y;
        x--,y--;
        cout <<ans[x][y]<<"\n";
    }
    return 0;
}
