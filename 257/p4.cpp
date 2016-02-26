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

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
long long int dis[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int n,m,k,i,u,v,x,si,y,counter,w;
    pair<long long int,long long int> mp;
    cin >>n>>m>>k;
    vector <set<pair<long long int,long long int> > > vec(n+1);
    set <pair<long long int,long long int> > ::iterator it;
    set <pair<long long int,long long int> > s;
    set <pair<long long int,long long int> >::iterator it1;
    for(i=0;i<m;i++)
    {
        cin >>u>>v>>x;
        mp=make_pair(v,x);
        vec[u].insert(mp);
        mp=make_pair(u,x);
        vec[v].insert(mp);
    }
    for(i=2;i<=n;i++){
        dis[i]=LLONG_MAX;
        check[i]=1;
    }
    dis[1]=0;
    s.insert(make_pair(dis[1],1));
    while(s.empty()==0)
    {
        mp=*(s.begin());
        s.erase(s.begin());
        w=mp.first;
        v=mp.second;
        it=vec[v].begin();
        while(it!=vec[v].end())
        {
            if(dis[(*it).first]>(dis[v]+(*it).second))
            {
                it1=s.find(make_pair(dis[(*it).first],(*it).first));
                if(it1!=s.end())
                    s.erase(it1);
                dis[(*it).first]=dis[v]+(*it).second;
                s.insert(make_pair(dis[(*it).first],(*it).first));
            }
            it++;
        }
    }
    for(i=0;i<k;i++)
    {
        cin >>si>>y;
        dis[si]=min(y,dis[si]);
    }
    counter=0;
    cout <<counter<<"\n";
    return 0;
}.
