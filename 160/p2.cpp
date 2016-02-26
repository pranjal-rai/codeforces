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
    long long int n,k,var,i,sum=0;
    vector < pair < long long int,long long int > > vec;
    pair < long long int,long long int > mypair;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        if(var<0)
        {
            mypair.first=(-1*var);
            mypair.second=1;
        }
        else{
            mypair.first=var;
            mypair.second=0;
        }
        vec.push_back(mypair);
    }
    sort(vec.begin(),vec.end());
    for(i=(n-1);i>=0;i--)
    {
        if(vec[i].second==1&&k>0)
        {
            vec[i].second=0;
            k--;
        }
    }
    if(k%2!=0)
    {
        if(vec[0].second==0)
            vec[0].second=1;
        else
            vec[0].second=0;
    }
    for(i=0;i<n;i++)
    {
        if(vec[i].second==0)
            sum+=vec[i].first;
        else
            sum-=vec[i].first;
    }
    cout <<sum<<"\n";
    return 0;
}

