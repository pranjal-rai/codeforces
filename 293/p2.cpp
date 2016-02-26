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
    int yay=0,whoops=0,l1,l2,freql1[26]={0},freql2[26]={0},frequ1[26]={0},frequ2[26]={0},i;
    string str1,str2;
    cin >>str1>>str2;
    l1=str1.length();
    l2=str2.length();
    for(i=0;i<l1;i++)
    {
        if(str1[i]<='Z')
            freql1[str1[i]-'A']++;
        else
            frequ1[str1[i]-'a']++;
    }
    for(i=0;i<l2;i++)
    {
        if(str2[i]<='Z')
            freql2[str2[i]-'A']++;
        else
            frequ2[str2[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(freql1[i]<=freql2[i])
        {
            yay+=freql1[i];
            freql2[i]-=freql1[i];
            freql1[i]=0;
        }
        else
        {
            yay+=freql2[i];
            freql1[i]-=freql2[i];
            freql2[i]=0;
        }
    }
    for(i=0;i<26;i++)
    {
        if(frequ1[i]<=frequ2[i])
        {
            yay+=frequ1[i];
            frequ2[i]-=frequ1[i];
            frequ1[i]=0;
        }
        else
        {
            yay+=frequ2[i];
            frequ1[i]-=frequ2[i];
            frequ2[i]=0;
        }
    }

    for(i=0;i<26;i++)
    {
        if(freql1[i]<=frequ2[i])
        {
            whoops+=freql1[i];
            frequ2[i]-=freql1[i];
            freql1[i]=0;
        }
        else
        {
            whoops+=frequ2[i];
            freql1[i]-=frequ2[i];
            frequ2[i]=0;
        }
    }
    for(i=0;i<26;i++)
    {
        if(frequ1[i]<=freql2[i])
        {
            whoops+=frequ1[i];
            freql2[i]-=frequ1[i];
            frequ1[i]=0;
        }
        else
        {
            whoops+=freql2[i];
            frequ1[i]-=frequ2[i];
            freql2[i]=0;
        }
    }
    cout <<yay<<" "<<whoops<<"\n";
    return 0;
}

