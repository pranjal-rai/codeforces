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
    int i,n;
    cin >>n;
    if(n==1)
        cout <<1<<"\n"<<1<<"\n";
    else if(n==2)
        cout <<1<<"\n"<<1<<"\n";
    else if(n==3)
        cout <<2<<"\n"<<"1 3\n";
    else if(n==4)
        cout <<4<<"\n"<<"2 4 1 3\n";
    else
    {
        cout <<n<<"\n";
        cout <<"1";
        for(i=3;i<=n;i=i+2)
        {
            cout <<" "<<i;
        }
        for(i=2;i<=n;i=i+2)
        {
            cout <<" "<<i;
        }
        cout <<"\n";
    }

    return 0;
}

