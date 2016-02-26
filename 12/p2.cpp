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
    int freq[10]={0},i,j,x;
    char mini='9';
    string n,m,str="";
    cin >>n>>m;
    if(n=="0"&&m=="0")
        cout <<"OK\n";
    else{
    x=n.length();
    for(i=0;i<x;i++){
        if(n[i]!='0'&&n[i]<mini)
            mini=n[i];
        freq[n[i]-'0']++;}
    str=str+mini;
    freq[mini-'0']--;
    for(i=0;i<=9;i++)
    {
        for(j=0;j<freq[i];j++)
        {
            str=str+(char)(i+'0');
        }
    }
    if(str==m)
        cout <<"OK\n";
    else
        cout <<"WRONG_ANSWER\n";}
    return 0;
}

