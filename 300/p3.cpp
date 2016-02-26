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
LL p=1e8;
LL cal(LL d1,LL h1,LL d2,LL h2)
{
    if(h2>h1&&(d2-d1)<(h2-h1))
        return -1;
    if(h2<h1&&(d2-d1)<(h1-h2))
        return -1;
    if(h2>=h1)
        return ((d2-d1)-(h2-h1))/2+h2;
    else
        return h1+((d2-d1)-(h1-h2))/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    VPLL v;
    LL n,m,i,d,h,maxheight,x;
    cin >>n>>m;
    for(i=0;i<m;i++)
    {
        cin >>d>>h;
        v.PB(MP(d,h));
    }
    maxheight=max(v[0].F+v[0].S-1,n-v[m-1].F+v[m-1].S);
    for(i=1;i<m;i++)
    {
        x=cal(v[i-1].F,v[i-1].S,v[i].F,v[i].S);
        if(x==-1)
        {
            cout <<"IMPOSSIBLE\n";
            return 0;
        }
        maxheight=max(maxheight,x);
    }
    cout <<maxheight<<"\n";
    return 0;
}
