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
long long int fastpow(long long int a, long long int b){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) ;b = b >> 1;a = (a * a) ;}return r;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
LL dp[200010],dp1[200010];
LL n,k,x,var,i,j,tmp,ans,idx;
VLL v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>k>>x;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
    }
    dp[0]=v[0];
    for(i=1;i<n;i++)
        dp[i]=dp[i-1]|v[i];
    dp1[n-1]=v[n-1];
    for(i=n-2;i>=0;i--)
        dp1[i]=dp1[i+1]|v[i];
 //   for(i=1;i<=k;i++)
   // {
     //   ans=dp[n-1];
        for(j=0;j<n;j++)
        {
            if(n==1)
                tmp=v[j]*fastpow(x,k);
            else if(j!=0&&j!=n-1)
            tmp=dp[j-1]|dp1[j+1]|(v[j]*fastpow(x,k));
            else if(j==0)
            tmp=(v[j]*fastpow(x,k))|dp1[j+1];
            else if(j==(n-1))
            tmp=(v[j]*fastpow(x,k))|dp[j-1];
            if(tmp>ans)
            {
                ans=tmp;
                idx=j;
            }
        }
        v[idx]=v[idx]*fastpow(x,k);
        dp[0]=v[0];
        dp1[n-1]=v[n-1];
    for(j=1;j<n;j++)
        dp[j]=dp[j-1]|v[j];
    for(j=n-2;j>=0;j--)
        dp1[j]=dp1[j+1]|v[j];
    
    cout <<dp[n-1]<<"\n";
    return 0;
}
