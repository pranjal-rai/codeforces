//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
char check[10000010]={'\0'};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k,i,var,q,x,j,l,minimum;
    check[0]='1';
    vector <int> vec;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
        check[var]='1';
    }
    cin >>q;
    while(q--)
    {
        cin >>x;
        minimum=INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=1;j<=k;j++)
            {
                if((j*vec[i])>x)break;
                if((j*vec[i])==x){minimum=min(minimum,j);continue;}
                for(l=1;l<=(k-j);l++)
                {
                    if((((x-(j*vec[i]))%l)==0)&&(((x-(j*vec[i]))/l)<=10000000)&&((check[(x-(j*vec[i]))/l]=='1')))
                    {
                        minimum=min(minimum,j+l);
                    }
                }
            }
        }
        if(minimum==INT_MAX)
            minimum=-1;
        cout <<minimum<<"\n";
    }
    return 0;
}
