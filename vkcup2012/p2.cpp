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
    int n,i,var,one=0,two=0,three=0,four=0,counter=0;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        if(var==1)
            one++;
        if(var==2)
            two++;
        if(var==3)
            three++;
        if(var==4)
            four++;
    }
    counter+=four;
    counter+=three;
    if(three>=one)
        one=0;
    else
        one=one-three;
    counter+=(two/2);
    if(two%2==1)
    {
        counter++;
        one=max(0,one-2);
    }
    counter+=(one/4);
    one=one%4;
    if(one!=0)
        counter++;
    cout <<counter<<"\n";
    return 0;
}

