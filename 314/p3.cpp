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
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL ans=0,n,k,var,i,x,y,a,b,p,q;
    VLL v2,v;
    VPLL ::iterator it1,it2;
    VLL ::iterator it3;
    VPLL v1;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
        v1.PB(MP(var,i));
    }
    sort(all(v1));
    for(i=0;i<n;i++)
        v2.PB(v1[i].S);
    for(i=0;i<n;i++)
    {
        if(v[i]%k==0)
        {
            x=v[i]/k;
            y=v[i]*k;
            it1=lower_bound(v1.begin(),v1.end(),MP(x,-1LL));
            it2=lower_bound(v1.begin(),v1.end(),MP(x+1,-1LL));
            if(it1==v1.end()||(*it1).F!=x)
                continue;
            else
            {
                a=it1-v1.begin();
                b=(--it2)-v1.begin();
                it3=lower_bound(v2.begin()+a,v2.begin()+b+1,i);
                if(it3==(v2.begin()+a))
                    continue;
                else
                    p=it3-(v2.begin()+a);
            }
            it1=lower_bound(all(v1),MP(y,-1LL));
            it2=lower_bound(all(v1),MP(y+1,-1LL));
            if(it1==v1.end()||(*it1).F!=y)
                continue;
            else
            {
                a=it1-v1.begin();
                b=(--it2)-v1.begin();
                it3=upper_bound(v2.begin()+a,v2.begin()+b+1,i);
                if(it3==(v2.begin()+b+1))
                    continue;
                else
                    q=v2.begin()+b-(--it3);
            }
            ans=ans+p*q;
        }
    }
    cout <<ans<<"\n";
    return 0;
}
