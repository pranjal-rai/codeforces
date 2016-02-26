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
    vector <int> freq(4,0);
    long long int n,i,counter=1;
    string str;
    cin >>n;
    cin >>str;
    for(i=0;i<n;i++)
    {
        if(str[i]=='A')
            freq[0]++;
        if(str[i]=='C')
            freq[1]++;
        if(str[i]=='G')
            freq[2]++;
        if(str[i]=='T')
            freq[3]++;
    }
    sort(freq.begin(),freq.end());
    for(i=3;i>0;i--)
        if(freq[i]==freq[i-1])
            counter++;
        else
            break;

    cout <<fastpow(counter,n,1000000007)<<"\n";
    return 0;
}

