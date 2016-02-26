//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int dp[100010];
int isvowel(char c)
{
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
            return 1;
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str;
    cin >>str;
    int l=str.length();
    str=" "+str;
    dp[0]=0;
    for(i=1;i<=l;i++)
    {
        if(isvowel(str[i]))
                dp[i]=dp[i-1]+1;
        else
                dp[i]=dp[i-1];
    }
    s=1,e=l,factor=1;
    for(i=1;i<=l;i++)
    {
        if(s<=e){
        counter=(dp[e]-dp[s]+isvowel(str[s])==1?1:0)*factor;
        factor++;
        }


        




    return 0;
}

