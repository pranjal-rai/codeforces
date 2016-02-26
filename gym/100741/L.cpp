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
LL d,n,m,i,var,x,j,y,val,ans=0,countx;
VLL r,b;
map <LL,LL> mp1,mp2;
map <LL,LL>::iterator it;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        cin >>var;
        r.PB(var);
    }
    for(i=0;i<m;i++)
    {
        cin >>var;
        b.PB(var);
    }
    x=1<<n;
    for(i=0;i<x;i++)
    {
        j=0,y=i,val=0;
        while(j<n)
        {
            d=y%2;
            val=val+d*r[j];
            y=y/2;
            j++;
        }
        if(val!=0)
        mp1[val]++;
    }
    x=1<<m;
    for(i=0;i<x;i++)
    {
        j=0,y=i,val=0;
        while(j<m)
        {
            d=y%2;
            val=val+d*b[j];
            y=y/2;
            j++;
        }
        if(val!=0)
        mp2[val]++;
    }
    it=mp1.begin();
    while(it!=mp1.end())
    {
        x=it->F;
        countx=it->S;
        ans=ans+countx*mp2[x];
        it++;
    }
    cout <<ans<<"\n";
    return 0;
}
