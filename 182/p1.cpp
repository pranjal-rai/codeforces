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
    int x,n,m,i,l,r,neg=0,pos=0;
    vector <int> vec(200001,0);
    cin >>n>>m;
    for(i=0;i<n;i++)
     {
         cin >>vec[i];
         if(vec[i]==-1)
             neg++;
         else
             pos++;
     }
    for(i=0;i<m;i++)
    {
        cin >>l>>r;
        l=l-1;
        r=r-1;
        x=r-l+1;
        if(x%2!=0)
            cout <<0<<"\n";
        else
        {
            if(neg>=x/2&&pos>=x/2)
                cout <<1<<"\n";
            else
                cout<<0<<"\n";
        }
    }
    return 0;
}

