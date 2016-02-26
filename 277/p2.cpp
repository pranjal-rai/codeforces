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
    int m,n,i,j,k,l,var,flag;
    vector <vector <int> > a(150),b(150);
    cin >>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >>var;
            b[i].PB(var);
            a[i].PB(-1);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i][j]==0)
            {
                for(k=0;k<n;k++)
                    a[i][k]=0;
                for(k=0;k<m;k++)
                    a[k][j]=0;
            }
        }
    }
    flag=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i][j]==1)
            {
                for(k=0;k<n;k++)
                    if(a[i][k]==-1)
                        break;
                for(l=0;l<m;l++)
                    if(a[l][j]==-1)
                        break;
                if(k==n&&l==m)
                    flag=0;
            }
        }
    }
    if(flag==0)
        cout <<"NO\n";
    else
    {
        cout <<"YES\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==-1)
                    a[i][j]=1;
                cout <<a[i][j]<<" ";
            }
            cout <<"\n";
        }
    }
    return 0;
}

