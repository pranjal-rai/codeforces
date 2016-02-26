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
    int n;
    string arr1[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string arr2[]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string arr3[]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    cin >>n;
    if(n<10)
        cout <<arr1[n]<<"\n";
    else if(n%10==0)
        cout <<arr2[n/10-1]<<"\n";
    else if(n<20)
        cout <<arr3[n-11]<<"\n";
    else
    {
        cout <<arr2[n/10-1]<<"-"<<arr1[n%10]<<"\n";
    }
    return 0;
}

