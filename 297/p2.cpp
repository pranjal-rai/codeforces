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
    vector <long long int> vec(3000000,0);
    string str;
    long long int l,i,m,var;
    cin >>str;
    l=str.length();
    cin >>m;
    for(i=0;i<m;i++)
    {
        cin >>var;
        vec[var-1]++;
    }
    for(i=1;i<l/2;i++)
    {
        vec[i]+=vec[i-1];
    }
    for(i=0;i<l/2;i++)
        vec[l-i-1]=vec[i];
    for(i=0;i<l/2;i++)
    {
        if(vec[i]%2==0)
        {
            cout <<str[i];
        }
        else
            cout <<str[l-i-1];
    }
    if(l%2==0)
        i=l/2-1;
    else
        i=l/2;
    for(;i>=0;i--)
    {
        if(vec[i]%2!=0)
        {
            cout <<str[i];
        }
        else
            cout <<str[l-i-1];
    }
    cout <<"\n";
    return 0;
}

