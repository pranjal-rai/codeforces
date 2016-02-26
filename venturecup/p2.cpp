//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define SZ(a) (int)(a.size())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define n_p next_permutation
#define b_s binary_search
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)
#define gcd __gcd
#define INF INT_MAX
#define init(a,b) memset(a,b,sizeof(a))
#define INFL LLONG_MAX
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;
typedef set<int> SI;
typedef set<LL> SLL;

void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
//LL modpow(LL a,LL b,LL m){LL r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//LL power(LL a, LL p){LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    FastIO(); 
    int n,c1=0,c2=0,c3=0,i;
    string str;
    cin >>n;
    cin >>str;
    for(i=0;i<n;i++)
    {
        if(str[i]=='R')
            c3++;
        if(str[i]=='G')
            c2++;
        if(str[i]=='B')
            c1++;
    }
    if(c1!=0&&c2!=0&&c3!=0)
    {
        cout <<"BGR"<<"\n";
        return 0;
    }
    if(c2==0&&c3==0)
    {
        cout <<"B"<<"\n";
        return 0;
    }
    if(c1==0&&c3==0)
    {
        cout <<"G"<<"\n";
        return 0;
    }
    if(c1==0&&c2==0)
    {
        cout <<"R"<<"\n";
        return 0;
    }
    if(c1==0)
    {
        if(c2==1&&c3==1)
        cout <<"B"<<"\n";
        else if(c2>=2&&c3>=2)
            cout <<"BGR"<<"\n";
        else
        {
            if(c2>1)
                cout <<"BR"<<"\n";
            else
                cout <<"BG"<<"\n";
        }
        return 0;
    }
    if(c2==0)
    {
        if(c1==1&&c3==1)
        cout <<"G"<<"\n";
        else if(c1>=2&&c3>=2)
            cout <<"BGR"<<"\n";
        else
        {
            if(c1>1)
                cout <<"GR"<<"\n";
            else
                cout <<"BG"<<"\n";
        }
        return 0;
    }
    if(c3==0)
    {
        if(c2==1&&c1==1)
        cout <<"R"<<"\n";
        else if(c2>=2&&c1>=2)
            cout <<"BGR"<<"\n";
        else
        {
            if(c2>1)
                cout <<"BR"<<"\n";
            else
                cout <<"GR"<<"\n";
        }
        return 0;
    }
    return 0;
}
