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
    long long int m,i,var,freq[5001]={0},l,maximum=INT_MIN;;
    vector <long long int> vec;
    cin >>m;
    for(i=0;i<m;i++)
    {
        cin >>var;
        maximum=max(maximum,var);
        freq[var]++;
    }
    freq[maximum]=1;
    for(i=1;i<=5000;i++)
    {
        if(freq[i]!=0)
        {
            vec.push_back(i);
            freq[i]--;
        }
    }
    for(i=5000;i>0;i--)
    {
        if(freq[i]!=0)
        {
            vec.push_back(i);
            freq[i]--;
        }
    }
    l=vec.size();
    cout <<l<<"\n";
    for(i=0;i<l;i++)
        cout <<vec[i]<<" ";
    cout <<"\n";
    return 0;
}

