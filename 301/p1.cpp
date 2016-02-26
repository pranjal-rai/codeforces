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
    int n,x,y,i,counter=0;
    string str1,str;
    cin >>n;

    cin >>str>>str1;
    for(i=0;i<n;i++)
    {
        x=str[i]-'0';
        y=str1[i]-'0';
        if(x<y)
            counter+=min(y-x,x-y+10);
        else
            counter+=min(x-y,y-x+10);
    }
    cout<<counter<<"\n";
    return 0;
}

