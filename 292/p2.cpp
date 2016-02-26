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
    long long int n,m,b,g,i,var,boy[200]={0},girl[200]={0},lcm,flag=1,x,y,z;
    cin >>n>>m;
    cin >>b;
    for(i=0;i<b;i++)
    {
        cin >>var;
        boy[var]=1;
    }
    cin >>g;
    for(i=0;i<g;i++)
    {
        cin >>var;
        girl[var]=1;
    }
    lcm=(n*m)/gcd(n,m);
//    lcm=1000;
    x=0,y=0,z=0;
    while(x!=lcm)
    {
        if(boy[y]==1||girl[z]==1)
        {
            boy[y]=1;
            girl[z]=1;
        }
        if(y<(n-1))
            y=y+1;
        else
            y=0;
        if(z<(m-1))
            z=z+1;
        else
            z=0;
        x++;
    }
    for(i=0;i<n;i++)
    {
        if(boy[i]==0)
            flag=0;
    }
    for(i=0;i<m;i++)
    {
        if(girl[i]==0)
            flag=0;
    }
    if(flag==0)
        cout <<"No\n";
    else
        cout <<"Yes\n";





    return 0;
}

