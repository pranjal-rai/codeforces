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
    double eps=0.0000001;
    long long int n,var,i,s,e,counter=0,x;
    cin >>n;
    vector <long long int> vec;
    vec.push_back(0);
    vec.push_back(0);
    x=((long long int)(pow(2,n+1)+eps))-2;
    for(i=1;i<=x;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    while(n!=0)
    {
        s=(long long int)(pow(2,n)+eps);
        e=((long long int)(pow(2,n+1)+eps))-1;
        for(i=s;i<=e;i=i+2)
        {
            counter+=(max(vec[i],vec[i+1])-min(vec[i],vec[i+1]));
            vec[i/2]+=max(vec[i],vec[i+1]);
        }
        n--;
    }
    cout <<counter<<"\n";
    return 0;
}
