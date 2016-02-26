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
    LL n,i,v,si,y,x,l,degree[1000000],xorv[1000000];
    vector <pair<LL,LL> > vec;
    set <pair<LL,LL> > s;
    set <pair<LL,LL> >::iterator it;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>v>>si;
        degree[i]=v;
        xorv[i]=si;
        s.insert(make_pair(v,i));
    }
    while(1)
    {
        it=s.begin();
        if(it==s.end())
            break;
        if((*it).F==0)
        {
            s.erase(it);
            it++;
            continue;
        }
        x=(*it).S;
        y=xorv[(*it).S];
        vec.PB(MP(x,y));
        degree[y]--;
        xorv[y]=xorv[y]^x;
        s.insert(MP(degree[y],y));
        s.erase(s.find(MP(degree[y]+1,y)));
        s.erase(it);
    }
    l=vec.size();
    cout <<l<<"\n";
    for(i=0;i<l;i++)
        cout <<vec[i].F<<" "<<vec[i].S<<"\n";
    return 0;
}
