//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
long long int var,i,n,x,y,count1,count2,ans[2000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>x>>y;
    count1=1,count2=1;
    ans[0]=2;
    for(i=1;i<(x+y);i++)
    {
        if(count1*y==count2*x)
        {
            ans[i]=2;
            i=i+1;
            ans[i]=2;
            count1++;
            count2++;
        }
        else if(count1*y<count2*x)
        {
            ans[i]=0;
            count1++;
        }
        else if(count1*y>count2*x)
        {
            ans[i]=1;
            count2++;
        }
    }
    while(n--)
    {
        cin>>var;
        var=var%(x+y);
        if(ans[var]==0)
            cout <<"Vanya\n";
        else if(ans[var]==1)
            cout <<"Vova\n";
        else cout <<"Both\n";
    }
    return 0;
}
