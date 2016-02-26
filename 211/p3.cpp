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
    string str;
    cin >>str;
    int l,i,counter,flag=0,s,e;
    l=str.length();
    counter=1;
    for(i=1;i<l;i++)
    {
        if(str[i]==str[i-1])
        {
            if(flag==0)
            {
                s=i-1;
                e=i;
                flag=1;
            }
            else
            e++;
        }
        else
        {
            if(flag==1)
            {
                if(e>=(s+2)){
                str.erase(str.begin()+s,str.begin()+e-1);
                i=i-(e-s-1);
                l=l-(e-s-1);
                }
            }
            flag=0;
        }
    }
    if(e==(l-1)&&e>=(s+2)&&flag==1)
    {
                str.erase(str.begin()+s,str.begin()+e-1);
                l=l-(e-s-1);
    }
    p=0;
    str1[p]=str[0];
    p++;
    for(i=1;i<l;i++)
    {
        if(str[i]==str[i-1])
        {
            if(flag==0)
            {
                flag=1;
                str1[p]=str[i];
                p++;
                j=i+2;
                while(j<l&&str[j]==str[j-1])
                {
                    str1[p]=str[j];
                    p++;



            }


    cout <<str<<"\n";
    return 0;
}

