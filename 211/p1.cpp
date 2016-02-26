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
    int l;
    string str;
    char c;
    cin >>str;
    l=str.length();
    for(int i=l-1;i>=0;i--)
    {
        c=str[i];
        if(c=='0')
        cout<<"O-|-OOOO\n";
        if(c=='1')
        cout<<"O-|O-OOO\n";
        if(c=='2')
        cout<<"O-|OO-OO\n";
        if(c=='3')
        cout<<"O-|OOO-O\n";
        if(c=='4')
        cout<<"O-|OOOO-\n";
        if(c=='5')
        cout<<"-O|-OOOO\n";
        if(c=='6')
        cout<<"-O|O-OOO\n";
        if(c=='7')
        cout<<"-O|OO-OO\n";
        if(c=='8')
        cout<<"-O|OOO-O\n";
        if(c=='9')
        cout<<"-O|OOOO-\n";
    }
    return 0;
}

