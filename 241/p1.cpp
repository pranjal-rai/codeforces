//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,x,i,lower_limit,upper_limit,flag=1;
    char c;
    string str;
    cin >>n;
    lower_limit=INT_MIN;
    upper_limit=INT_MAX;
    for(i=0;i<n;i++)
    {
        cin >>str;
        cin >>x;
        cin >>c;
        if(c=='Y')
        {
            if(str==">=")
                lower_limit=max(lower_limit,x);
            if(str=="<=")
                upper_limit=min(upper_limit,x);
            if(str==">")
                lower_limit=max(lower_limit,x+1);
            if(str=="<")
                upper_limit=min(upper_limit,x-1);
            if(lower_limit>upper_limit)
                flag=0;
        }
        if(c=='N')
        {
            if(str==">=")
                upper_limit=min(upper_limit,x-1);
            if(str=="<=")
                lower_limit=max(lower_limit,x+1);
            if(str==">")
                upper_limit=min(upper_limit,x);
            if(str=="<")
                lower_limit=max(lower_limit,x);
            if(lower_limit>upper_limit)
                flag=0;
        }
    }
    if(lower_limit>2000000000||upper_limit<-2000000000)
        flag=0;
    if(flag==1)
    {
        if(lower_limit<=-2000000000)
        cout <<-2000000000<<"\n";
        else
            cout <<lower_limit<<"\n";
    }

    else
        cout <<"Impossible\n";
    return 0;
}
