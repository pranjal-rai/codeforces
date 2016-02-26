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
long long int arr[5000010]={0},cum[5000010]={0};

    long long int x,i,j,t,a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>t;
    cum[1]=0;
    for(i=2;i<=5000010;i++)
    {
        if(arr[i]!=0)
            continue;
        for(j=1;j*i<=5000010;j++)
        {
            x=j*i;
            while(x!=1&&x%i==0){
                arr[i*j]++;
                x=x/i;
            }
        }
    }
    for(i=2;i<=5000010;i++)
        cum[i]=cum[i-1]+arr[i];
    while(t--)
    {
        cin>>a>>b;
        cout <<cum[a]-cum[b]<<"\n";
    }
    return 0;
}
