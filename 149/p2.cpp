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
    int n,x,y,minx=INT_MAX,maxy=INT_MIN,i;
    map <pair<int,int>,int> m;
    pair<int,int> mp;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>x>>y;
        minx=min(minx,x);
        maxy=max(maxy,y);
        mp=make_pair(x,y);
        m[mp]=i+1;
    }
    mp=make_pair(minx,maxy);
    if(m.find(mp)!=m.end())
        cout <<m[mp]<<"\n";
    else
        cout <<-1<<"\n";
    return 0;
}
