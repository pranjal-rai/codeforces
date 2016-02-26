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
int n,m;
char arr[100][100];
int check(int i,int j)
{
    int flag1=1,flag2=1,flag3=1,flag4=1;
    if(i<n-1&&j<m-1)
    {
        if(arr[i][j]=='f')
            flag1=0;
        if(arr[i][j+1]=='f')
            flag1=0;
        if(arr[i+1][j]=='f')
            flag1=0;
        if(arr[i+1][j+1]=='f')
            flag1=0;
        if(arr[i][j]=='a')
            flag2=0;
        if(arr[i][j+1]=='a')
            flag2=0;
        if(arr[i+1][j]=='a')
            flag2=0;
        if(arr[i+1][j+1]=='a')
            flag2=0;
        if(arr[i][j]=='c')
            flag3=0;
        if(arr[i][j+1]=='c')
            flag3=0;
        if(arr[i+1][j]=='c')
            flag3=0;
        if(arr[i+1][j+1]=='c')
            flag3=0;
        if(arr[i][j]=='e')
            flag4=0;
        if(arr[i][j+1]=='e')
            flag4=0;
        if(arr[i+1][j]=='e')
            flag4=0;
        if(arr[i+1][j+1]=='e')
            flag4=0;
    }
    if(flag1==0&&flag2==0&&flag3==0&&flag4==0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int i,j,counter=0;
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        counter+=check(i,j);
    }
    cout <<counter<<"\n";
    return 0;
}

