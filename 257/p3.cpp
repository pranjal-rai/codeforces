//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int n,m,k,n1,m1,x,i,ans=INT_MIN;
    cin >>n>>m>>k;
    if(k>(n+m-2)){
        cout <<-1<<"\n";
        return 0;
    }
    n1=max(n,m);
    m1=min(n,m);
    n=n1,m=m1;
    x=(long long int)(sqrt(n));
    for(i=1;i<=x;i++){
        if((k-i+1)<0)
       ans=max((n/i)*(m/(1)),ans);
        else
        if(/*(i-1)<=k&&*/m>(k-i+1))
       ans=max((n/i)*(m/(k-i+2)),ans);
        if((k-n/i+1)<0)
        ans=max((n/(n/i))*(m/(1)),ans);
        else
        if(/*(n/i-1)<=k&&*/m>(k-(n/i)+1))
        ans=max((n/(n/i))*(m/(k-(n/i)+2)),ans);
    }
    cout <<ans<<"\n";
    return 0;
}
