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
    int n,i,l,counter=0,freq[26]={0};
    vector <int> vec;
    string str;
    cin >>n;
    cin >>str;
    l=str.length();
    for(i=0;i<l;i++)
    {
        if(freq[str[i]-'a']==0)
        {
            counter++;
            freq[str[i]-'a']++;
            vec.push_back(i);
        }
    }
    if(counter<n)
        cout <<"NO\n";
    else
    {
        cout <<"YES\n";
        for(i=0;i<n;i++)
        {
            if(i!=n-1)
                cout <<str.substr(vec[i],vec[i+1]-vec[i])<<"\n";
            else
                cout <<str.substr(vec[i],l-vec[i])<<"\n";
        }
    }
    return 0;
}
