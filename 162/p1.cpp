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
    string str1,str2;
    int l1,l2,i,j;
    cin >>str1>>str2;
    l1=str1.length();
    l2=str2.length();
    j=0;
    for(i=0;i<l2;i++)
    {
        if(str2[i]==str1[j]&&j!=(l1-1))
        {
            j+=1;
        }
    }
    cout <<j+1<<"\n";
    return 0;
}

