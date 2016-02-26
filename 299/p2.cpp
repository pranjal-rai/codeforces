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
    long long int l=str.length(),i,j,sum=0,counter;
    double e=0.000001;
    for(i=0;i<(l-1);i++)
        sum+=((long long int)(pow(2,i+1)+e));
    counter=1;
    for(i=l-1,j=0;i>=0;i--,j++)
    {
        if(str[i]=='7')
            counter+=((long long int)(pow(2,j)+e));
    }
    cout <<sum+counter<<"\n";
    return 0;
}

