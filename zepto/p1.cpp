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
    int n,flag=0,i,l,d,j;
    vector <int> vec;
    string str;
    cin >>n>>str;
    for(i=0;i<n;i++)
    {
        if(str[i]=='*')
            vec.push_back(i);
    }
    l=vec.size();
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            d=vec[j]-vec[i];
            if(((4*d)+vec[i])>=n)
                continue;
            if(str[vec[i]]=='*'&&str[vec[i]+d]=='*'&&str[vec[i]+2*d]=='*'&&str[vec[i]+3*d]=='*'&&str[vec[i]+4*d]=='*')
                flag=1;
        }
    }
    if(flag==1)
        cout <<"yes\n";
    else
        cout <<"no\n";
    return 0;
}

