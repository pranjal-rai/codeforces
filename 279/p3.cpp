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
    long long int l,a,b,dp[1000010],i,j,ans1=0,ans2=0,flag=0;
    cin >>str;
    l=str.length();
    cin >>a>>b;
    dp[l-1]=1;
    for(i=(l-2);i>=0;i--)
        dp[i]=((dp[i+1]%b)*(10%b))%b;
    for(i=0;i<l;i++)
        ans2=(((ans2%b)*(10%b))%b+(str[i]-'0')%b)%b;
    for(i=0;i<(l-1);i++)
    {
            ans1=(((ans1%a)*(10%a))%a+(str[i]-'0')%a)%a;
            ans2=((ans2%b-((dp[i]%b)*(str[i]-'0')%b)%b)+b)%b;
            if(str[i+1]!='0'&&ans1==0&&ans2==0)
            {
                flag=1;
                break;
            }
    }
    if(flag==0)
        cout <<"NO\n";
    else{
        cout <<"YES\n";
        for(j=0;j<=i;j++)
            cout <<str[j];
        cout <<"\n";
        for(j=i+1;j<l;j++)
            cout <<str[j];
        cout <<"\n";
    }
    return 0;
}

