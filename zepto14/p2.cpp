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
    int n,m,k,counter,i,j;
    char arr[2050][2050];
    cin >>n>>m>>k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin >>arr[i][j];
    }
    for(i=0;i<m;i++)
    {
        counter=0;
        for(j=1;j<n;j++)
        {
            if(j%2==0&&arr[j][i]=='U')
                counter++;
        }
        for(j=1;j<n;j++)
        {
            if((i-j)>=0&&arr[j][i-j]=='R')
                counter++;
            if((i+j)<m&&arr[j][i+j]=='L')
                counter++;
        }
        cout <<counter<<" ";
    }
    cout <<"\n";
    return 0;
}
