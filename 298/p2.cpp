//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int d;
int issafe(int val,int z,int fin)
{
    if(fin>=val)
    {
        if((z*d+val)<fin)
            return  0;
        return 1;
    }
    else
    {
        if(val-(z*d)>fin)
            return 0;
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int v1,v2,t,sum,curr,fin,x,i;
    cin >>v1>>v2>>t>>d;
    sum=v1+v2;
    curr=v1,fin=v2;
    for(i=1;i<=t-2;i++)
    {
        x=d;
        while(x>=-d)
        {
            if(issafe(curr+x,t-i-1,fin)==1)
            {
                sum+=(curr+x);
                curr+=x;
                break;
            }
            x--;
        }
    }
    cout <<sum<<"\n";
    return 0;
}

