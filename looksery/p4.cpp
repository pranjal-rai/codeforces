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
char A[150][150],B[150][150];
void __swap(int x,int y)
{
    int i,j;
    for(i=0;i<=x;i++)
    {
        for(j=0;j<=y;j++)
        {
            if(B[i][j]=='B')
                B[i][j]='W';
            else
                B[i][j]='B';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,j,k,counter=0;
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>A[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            B[i][j]=A[n-1][m-1];
    }
    counter=1;
    while(i>=0&&j>=0)
    {
        if(B[i][j]!=A[i][j])
        {
            counter++;
            __swap(i,j);
        }
        for(k=j-1;k>=0;k--)
        {
            if(B[i][k]!=A[i][k])
            {
                counter++;
                __swap(i,k);
            }
        }
        for(k=i-1;k>=0;k--)
        {
            if(B[k][j]!=A[k][j])
            {
                counter++;
                __swap(k,j);
            }
        }
        i--,j--;
    }
    cout <<counter<<"\n";
    return 0;
}

