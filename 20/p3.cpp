//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int q,n,m,i,x,y,w,vertex,vertex1,d[100010],l;
    pair<long long int,long long int> mp;
    cin >>n>>m;
    vector <vector<pair<long long int,long long int> > > v(n+1);
    for(i=0;i<m;i++)
    {
        cin >>x>>y>>w;
        if(x==y)
            continue;
        mp=make_pair(y,w);
        v[x].push_back(mp);
        mp=make_pair(x,w);
        v[y].push_back(mp);
    }
    set <pair<long long int,long long int> >s;
    vector <int> parent(100010,-1),v1;
    d[1]=0;
    mp=make_pair(0,1);
    s.insert(mp);
    for(i=2;i<=n;i++){
        d[i]=LLONG_MAX;
    }
    while(s.empty()==0)
    {
        vertex=(*(s.begin())).second;
        s.erase(s.begin());
        l=v[vertex].size(),i=0;
        while(i<l)
        {
            vertex1=v[vertex][i].first;
            if(d[vertex1]>d[vertex]+v[vertex][i].second)
            {
                    mp=make_pair(d[vertex1],vertex1);
                if(s.find(mp)!=s.end())
                    s.erase(s.find(mp));
            
                 d[vertex1]=d[vertex]+v[vertex][i].second;
                 mp=make_pair(d[vertex1],vertex1);
                 s.insert(mp);
                 parent[vertex1]=vertex;
            }
            i++;
        }
    }
    if(parent[n]==-1)
        cout <<-1<<"\n";
    else
    {
            x=n;
            v1.push_back(n);
        while(parent[x]!=-1)
        {
            v1.push_back(parent[x]);
            x=parent[x];
        }
            l=v1.size();
            while(l--)
                cout <<v1[l]<<" ";
            cout <<"\n";
    }
    return 0;
}
