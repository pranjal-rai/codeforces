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
    string s,p="",t;
    int l,counter=0,counter1=0,i;
    vector <int> vec;
    cin >>s>>t;
    p=s;
    l=s.length();
    for(i=0;i<l;i++)
    {
        if(s[i]!=t[i]){
            vec.push_back(i);
            counter++;
        }
    }
    if(counter%2!=0)
        cout <<"impossible\n";
    else
    {
        counter1=0;
        for(i=0;i<counter/2;i++)
        {
            p[vec[i]]=s[vec[i]];
        }
        for(i=counter/2;i<counter;i++)
        {
            p[vec[i]]=t[vec[i]];
        }/*
        for(i=0;i<l;i++)
        {
            if(s[i]==t[i])
            {
                p=p+s[i];
            }
            else
            {
                counter1++;
                if(s[i]=='0')
                    p[i]='1';
                else
                    p[i]='0';
            }
        }
        i=i-1,counter1=0;
        for(;i<l&&counter1<counter/2;i++)
        {
            if(s[i]==t[i])
            {
                p=p+s[i];
            }
            else
            {
                counter1++;
                if(t[i]=='0')
                    p[i]='1';
                else
                    p[i]='0';
            }
        }*/
        cout <<p<<"\n";
    }
    return 0;
}

