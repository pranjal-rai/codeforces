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
    int i,n,k,var,count1=0,counter=0;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        counter=0;
        while(var!=0)
        {
            if(var%10==4||var%10==7)
                counter++;
            var=var/10;
        }
        if(counter<=k)
            count1++;
    }
    cout <<count1<<"\n";

    return 0;
}

