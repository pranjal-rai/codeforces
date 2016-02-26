//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
double dp[2050][2050];
int main()
{
    long long int n,t,i,j;
    double p,sum=0.0;
    cin >>n>>p>>t;
    dp[0][0]=1.0;
    for(i=1;i<=n;i++)
        dp[0][i]=0.0;
    for(i=1;i<=t;i++)
        dp[i][0]=(1-p)*dp[i-1][0];
    for(i=1;i<=t;i++){
        for(j=1;j<=n;j++)
        {
            if(j!=n)
            dp[i][j]=dp[i-1][j]*(1-p)+dp[i-1][j-1]*p;
            else
            dp[i][j]=dp[i-1][j]*(1)+dp[i-1][j-1]*p;
        }
    }
    for(j=1;j<=n;j++)
        sum+=(dp[t][j]*j);
    printf("%.9lf\n",sum);
    return 0;
}
