//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int c1,c2,c3,c4,c5,sum;
    cin >>c1>>c2>>c3>>c4>>c5;
    sum=c1+c2+c3+c4+c5;
    if(sum!=0&&(sum)%5==0)
        cout <<sum/5<<"\n";
    else
        cout <<"-1\n";

    return 0;
}

