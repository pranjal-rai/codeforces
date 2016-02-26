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
    long long int n,a,b,x,y,i;
    cin >>n>>a>>b;
    if((a*b)>=(6*n))
        cout <<(a*b)<<"\n"<<a<<" "<<b<<"\n";
    else
    {
        x=6*n;
        while(1)
        {
            y=sqrt(x);
            for(i=1;i<=y;i++)
            {
                if(x%i==0)
                {
                    if(i>=a&&(x/i)>=b)
                        goto xyz;
                    else 
                    if(i>=b&&(x/i)>=a)
                        goto xyz;
                }
            }
            x++;
        }
        xyz:
                    if(i>=a&&(x/i)>=b)
                        cout <<x<<"\n"<<i<<" "<<x/i<<"\n";
                    else
                        cout <<x<<"\n"<<x/i<<" "<<i<<"\n";
    }
    return 0;
}
