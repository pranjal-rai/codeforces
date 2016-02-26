
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
int n,m,k,len[1010];
vector <int> vis(1010);
vector <vector<int> > G(1010);
long long int counter=0;
string str;
pair <int,pair<int,int> > mp;
vector <vector<string> > vec;
vector <pair<int,pair<int,int> > > v;
int diff(int x,int y)
{
    int i,j;
    counter=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(vec[x][i][j]!=vec[y][i][j])
                counter++;
        }
    }
    return counter;
}
int dfs(int x,int parent,int *vis_status)
{
    int flag=1,i,l;
    vis_status[x]=2;
    l=len[x];
    for(i=0;i<l;i++)
    {
        if(G[x][i]!=parent&&vis_status[G[x][i]]==2)
            return 0;
        else if(vis_status[G[x][i]]==0)
            flag = flag & (dfs(G[x][i],x,vis_status));
    }
    vis_status[x]=1;
    return flag;
}
int checkcycle(int x)
{
    int i;
    int vis_status[1010]={0};
    if(dfs(x,-1,vis_status)==0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int w,i,j,l,x,y;
    cin >>n>>m>>k>>w;
    for(i=0;i<k;i++)
    {
        vector <string> v1;
        for(j=0;j<n;j++)
        {
            cin >>str;
            v1.push_back(str);
        }
        vec.push_back(v1);
    }
    for(j=1;j<=k;j++)
    {
            mp=make_pair(n*m,make_pair(j,0));
            v.push_back(mp);
    }
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            if(i!=j){
                mp=make_pair(diff(i-1,j-1)*w,make_pair(i,j));
                v.push_back(mp);
            }
        }
    }
    sort(v.begin(),v.end());
    l=v.size();
    counter=0;
    for(i=0;i<l;i++)
    {
        x=v[i].second.first;
        y=v[i].second.second;
        G[x].push_back(y);
        G[y].push_back(x);
        len[x]++;
        len[y]++;
        if(checkcycle(x)==1)
        {
            len[x]--;
            len[y]--;
            G[x].erase(G[x].begin()+len[x]);
            G[y].erase(G[y].begin()+len[y]);
        }
        else
            counter=counter+(v[i].first);
    }
    cout <<counter<<"\n";
    queue <int> q;
    for(i=0;i<=k;i++)
        vis[i]=0;
    q.push(0);
    vis[0]=1;
    while(q.empty()==0)
    {
        x=q.front();
        q.pop();
        l=len[x];
        for(i=0;i<l;i++)
        {
            if(vis[G[x][i]]==0)
            {
                q.push(G[x][i]);
                vis[G[x][i]]=1;
                cout <<G[x][i]<<" "<<x<<"\n";
            }
        }
    }
    return 0;
}
