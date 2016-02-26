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


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
LL n,m,i,l,r,x;
vector <pair<LL,LL> > vec;
multiset <pair<LL,LL> > s;
multiset <pair<LL,LL> >::iterator it;
vector <pair<pair<LL,LL>,LL> > v;
LL ans[1000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        cin >>l>>r;
        vec.PB(make_pair(l,r));
    }
    for(i=0;i<m;i++)
    {
        cin >>x;
        s.insert(make_pair(x,i+1));
    }
    for(i=0;i<(n-1);i++)
        v.PB(make_pair(make_pair(vec[i+1].S-vec[i].F,vec[i+1].F-vec[i].S),i));
    sort(v.begin(),v.end());
    for(i=0;i<(n-1);i++)
    {
        it=s.lower_bound(make_pair(v[i].F.S,LLONG_MIN));
        if(it==s.end()||((*it).F)>v[i].F.F)
        {
            cout <<"No\n";
            return 0;
        }
        else
        {
            ans[v[i].S]=(*it).S;
            s.erase(it);
        }
    }   
    cout <<"Yes\n";
    for(i=0;i<(n-1);i++)
        cout <<ans[i]<<" ";
    cout <<"\n";
    return 0;
}
