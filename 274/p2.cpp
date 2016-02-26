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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL n,k,i,var,l;
    vector <pair<LL,LL> > vec;
    pair <LL,LL> p1,p2;
    multiset <pair<LL,LL> > s;
    multiset <pair<LL,LL> >::iterator it1,it2;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        s.insert(make_pair(var,i+1)); 
    }
    for(i=1;i<=k;i++)
    {
        it1=s.begin();
        it2=s.end();
        it2--;
        if(((*it1).F)==0||(((*it2).F)==((*it1).F))||(((*it2).F)==((*it1).F)+1))
            break;
        p1=*it1;
        p2=*it2;
        s.erase(it1);
        s.erase(it2);
        vec.PB(make_pair(p2.S,p1.S));
        s.insert(make_pair(p1.F+1,p1.S));
        s.insert(make_pair(p2.F-1,p2.S));
        it1=s.begin();
        it2=s.end();
        it2--;
    }
    it1=s.begin();
    it2=s.end();
    it2--;
    l=vec.size();
    cout <<((*it2).F)-((*it1).F)<<" "<<l<<"\n";
    for(i=0;i<l;i++)
        cout <<vec[i].F<<" "<<vec[i].S<<"\n";
    return 0;
}
