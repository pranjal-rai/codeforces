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
    long long int n,i,x,d,flag=0,minimum=INT_MAX,l,sum;
    cin >>n;
    for(i=1;i<=99;i++)
    {
        d=i*i+4*n;
        x=(long long int)(sqrt(d));
        if(x*x==d&&(x-i)/2>0&&(x-i)%2==0)
        { 
            l=(x-i)/2;
            sum=0;
            while(l!=0)
            {
                sum+=l%10;
                l=l/10;
            }
            if(sum==i){
            flag=1;
            minimum=min(minimum,(x-i)/2);}
        }
    }
    if(flag==0)
        cout <<"-1\n";
    else
        cout <<minimum<<"\n";
    return 0;
}

