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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

    LL ans1,ans2,n,k,i,var,cum[200010]={0},ans=-1,dp[200010]={0},dp1[200010]={0},dp3[200010],dp4[200010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    VLL v;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
    }
    cum[0]=v[0];
    for(i=1;i<n;i++)
        cum[i]=cum[i-1]+v[i];
    for(i=0;i<n-k+1;i++)
    {
        if(i!=0)
            dp[i]=cum[i+k-1]-cum[i-1];
        else
            dp[i]=cum[i+k-1];
    }
    for(i=0;i<n-k+1;i++)
        dp3[i]=dp[i];
    for(i=1;i<n-k+1;i++)
        dp[i]=max(dp[i-1],dp[i]);
    for(i=n-k;i>=0;i--)
    {
        if(i!=0)
            dp1[i]=cum[i+k-1]-cum[i-1];
        else
            dp1[i]=cum[i+k-1];
    }
    for(i=n-k;i>=0;i--)
        dp4[i]=dp1[i];
    for(i=n-k-1;i>=0;i--)
        dp1[i]=max(dp1[i],dp1[i+1]);
    LL s,e;
    for(i=0;i<n-2*k+1;i++)
    {
        if((dp[i]+dp1[i+k])>ans)
        {
            ans=dp[i]+dp1[i+k];
            ans1=dp[i],ans2=dp1[i+k];
        }
    }
    for(i=0;i<n-k+1;i++)
        if(dp3[i]==ans1){
            s=i+1;
            break;}
    for(i=n-k;i>=s+k-1;i--)
        if(dp4[i]==ans2)
            e=i+1;
    cout <<s<<" "<<e<<"\n";
    return 0;
}
