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
    string str;
    cin >>str;
    long long int l=str.length();
    long long int i,pt1=0,pt2=l-1,dp[1000100]={0};
    for(i=0;i<l;i++)
    {
        if(str[i]=='l')
        {
            dp[pt2]=i+1;
            pt2--;
        }
        else
        {
            dp[pt1]=i+1;
            pt1++;
        }
    }
    for(i=0;i<l;i++)
    {
        cout <<dp[i]<<"\n";
    }
    return 0;
}

