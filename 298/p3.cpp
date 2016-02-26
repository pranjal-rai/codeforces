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
    long long int n,A,i,x,sum=0;
    vector <long long int> vec(200010);
    cin >>n>>A;
    for(i=0;i<n;i++){
        cin >>vec[i];
        sum+=vec[i];
    }
    for(i=0;i<n;i++)
        cout <<(vec[i]-(min(A-(n-1),vec[i])-max(1LL,A-(sum-vec[i]))+1))<<" ";
    cout <<"\n";
    return 0;
}
