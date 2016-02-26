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
    long long int n,i,sum=0,sereja=0,left=0,right,flag=0;
    vector <int> vec(1200,0);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>vec[i];
        sum+=vec[i];
    }
    right=n-1;
    while(left<=right)
    {
        if(left==right&&flag==0)
        {
            sereja+=vec[left];
            left++;
            flag=1;
        }

        if(vec[left]>vec[right])
        {
            if(flag==0)
            {
            sereja+=vec[left];
            left++;
            flag=1;
            }
            else
            {
            left++;
            flag=0;
            }

        }
        else
        {
            if(flag==0){
            sereja+=vec[right];
            right--;flag=1;
            }
            else
            {
            right--;
            flag=0;
            }
        }
    }
    cout <<sereja<<" ";
    cout <<sum-sereja<<"\n";
    return 0;
}
