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
    string str;
    
    
    int i,l,freq[26]={0},flag=1;
    cin >>l;
    cin >>str;
    for(i=0;i<l;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            freq[str[i]-'A']++;
        if(str[i]>='a'&&str[i]<='z')
            freq[str[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(freq[i]==0)
            flag=0;
    }
    if(flag==0)
        cout <<"NO\n";
    else
        cout <<"YES\n";
    return 0;
}

