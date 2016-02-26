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
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
LL l,dp[2010]={0},dp1[2010]={0};
bool pal[2010][2010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int i,j;
    string str;
    cin >>str;
    l=str.length();
    for(j=0;j<l;j++)
    {
        for(i=0;i<=j;i++)
        {
            if(i==j)
            {
                pal[i][j]=1;
                continue;
            }
            if(str[i]==str[j]&&((i+1>j-1)||pal[i+1][j-1]))
                pal[i][j]=1;
        }
    }
    dp[0]=1;
    for(i=1;i<l;i++)
    {
        dp[i]=0;
        for(j=0;j<=i;j++)
        {
            if(pal[j][i])
                dp[i]++;
        }
    }
    dp1[l-1]=1;
    for(i=l-2;i>=0;i--)
    {
        dp1[i]=dp1[i+1];
        for(j=i;j<l;j++)
        {
            if(pal[i][j])
                dp1[i]++;
        }
    }
    LL ans=0;
    for(i=0;i<l-1;i++)
        ans+=(dp[i]*dp1[i+1]);
    cout <<ans<<"\n";
    return 0;
}
