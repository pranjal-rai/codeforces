//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >>n>>m;
    int flag=1,flag1=0,i,j;
    for(i=0;i<n;i++)
    {
        int k=1;
        for(j=0;j<m;j++)
        {
            if(flag==1)
            {
                cout <<"#";
            }
            else if(flag==0)
            {
                if(flag1==0)
                {
                    if(j==(m-1)&&k==1){
                    cout <<"#";
                    flag1=1;
                    k=0;
                    }
                    else
                    {
                        cout <<".";
                    }
                }
                else
                {
                    if(j==0&&k==1)
                    {
                        cout <<"#";
                        flag1=0;
                        k=0;
                    }
                    else
                    {
                        cout <<".";
                    }
                }
            }
        }
        if(flag==1)
            flag=0;
        else
            flag=1;
        cout <<"\n";
    }
    return 0;
}

