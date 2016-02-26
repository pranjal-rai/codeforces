//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int n,m,kmin,kmax;
    cin >>n>>m;
    kmax=((n-(m-1))*(n-(m-1)-1))/2;
    if(n%m==0)
    {
        kmin=(((n/m)*(n/m-1))/2)*m;
    }
    else
    {
        kmin=(m-(n%m))*(((n/m)*(n/m-1))/2)+(n%m)*(((n/m+(1))*(n/m))/2);
    }
    cout <<kmin<<" "<<kmax<<"\n";
    return 0;
}

