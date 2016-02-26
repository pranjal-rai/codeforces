//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    int x,arr[1000][1000][2],dp[1000][1000];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >>arr[i][j][0];
            x=arr[i][j][0];
            if(x!=0){
                counter=0;
            while(x!=0)
            {
                if(x%10==0)
                    counter++;
                else{
                    break;
                }
                x=x/10;
            }
            arr[i][j][0]=x%10;
            arr[i][j][1]=counter;
            }
            else{
                arr[i][j][0]=0;
                arr[i][j][1]=0;
            }
        }
    }
    dp[0][0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0&&j==0)
                continue;
            if(i==0)
            {
                dp[x][y]=dp[x][y-1];




    return 0;
}

