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
LL dp[1000010][2]={0};
int check(LL i)
{
    while(i!=0)
    {
        if((i%10)!=0&&(i%10)!=1)
            return 0;
        i=i/10;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL i,j,n;
    VLL v;
    cin >>n;
    for(i=1;i<=1000000;i++)
    {
        if(check(i))
        {
            v.PB(i);
        }
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=i;
        dp[i][1]=1;
        for(j=0;v[j]<=i;j++)
        {
            if(dp[i-v[j]][0]+1<dp[i][0])
            {
                dp[i][0]=dp[i-v[j]][0]+1;
                dp[i][1]=v[j];
            }
        }
    }
    cout <<dp[n][0]<<"\n";
    LL x=n;
    while(x!=0)
    {
        cout <<dp[x][1]<<" ";
        x=x-dp[x][1];
    }
    cout <<"\n";
    return 0;
}
