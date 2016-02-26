//pranjalr34
#include<bits/stdc++.h>
using namespace std;
unsigned long long int gcd(unsigned long long int m,unsigned long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    unsigned long long int n,fact;
    cin >>n;
    if(n==1)
        cout <<1<<"\n";
    else if(n==2)
        cout <<"2\n";
    else if(n%2==1)
        cout <<n*(n-1)*(n-2)<<"\n";
    else {
        if(n%3==0)
            fact=3;
        else
            fact=1;
        cout <<max(max((n-1)*(n-2)*(n-3),(n*(n-1)*(n-3))/fact),(((n*(n-1))/(gcd(n,n-1)))*(n-2))/gcd((n*(n-1))/gcd(n,n-1),n-2))<<"\n";
    }
    return 0;
}

