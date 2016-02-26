//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int arr[100][100]={0},maximum=1,i,n,j;
    cin >>n;
    for(i=0;i<n;i++)
    {
        arr[0][i]=1;
    }
    for(i=0;i<n;i++)
    {
        arr[i][0]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
            maximum=max(maximum,arr[i][j]);
        }
    }
    cout <<maximum<<"\n";


    return 0;
}

