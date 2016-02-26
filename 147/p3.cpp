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
    long long int i,j,a,b,k,l;
    vector <int> sieve(1000001,1);
    vector <int> cumsieve(1000001,0);
    sieve[0]=sieve[1]=0;
    cin >>a>>b>>k;
    for(i=2;i<=1000000;i++)
    {
        if(sieve[i]==1)
        {
            for(j=2;j*i<=1000000;j++)
            {
                sieve[j*i]=0;
            }
        }
    }
    cumsieve[0]=0;
    for(i=1;i<=1000000;i++)
    {
        cumsieve[i]=cumsieve[i-1]+sieve[i];
    }
    if((cumsieve[b]-cumsieve[a-1])<k)
        cout <<-1<<"\n";
    else
    {
        l=1;
    for(i=a;i<=b;i++)
    {
        if((cumsieve[i]-cumsieve[i-l])<k)
            l++;
    }
    cout <<l<<"\n";
    }
    return 0;
}

