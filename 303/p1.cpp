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
    int counter=0,i,j,n,arr[200][200];
    cin >>n;
    vector <int> good(200,1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >>arr[i][j];
            if(arr[i][j]==-1)
                continue;
            else if(arr[i][j]==0)
                continue;
            else if(arr[i][j]==1)
                good[i]=0;
            else if(arr[i][j]==2)
                good[j]=0;
            else if(arr[i][j]==3)
                good[j]=0,good[i]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(good[i]==1)
            counter++;
    }
    cout <<counter<<"\n";
    if(counter==0)
        return 0;
    for(i=0;i<n;i++)
    {
        if(good[i]==1)
            cout <<i+1<<" ";
    }
    cout <<"\n";

    return 0;
}

