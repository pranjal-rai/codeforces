//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int cal(string str1,string str2,int i,int l)
{
    for(int j=i;j<l;j++)
    {
        if(str2[j]!='a')
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str1,str2;
    int l,i,flag=0,carry=1;
    cin >>str1>>str2;
    l=str1.length();
    for(i=l-1;i>=0;i--)
    {
        if(carry==0)
            break;
        else
        {
            if(i!=0&&str1[i]=='z')
            {
                str1[i]='a';
            }
            else
            {
                str1[i]=str1[i]+1;
                carry=0;
            }
        }
    }
    if(carry==1||str1.compare(str2)==0)
        cout <<"No such string\n";
    else
        cout <<str1<<"\n";
    return 0;
}

