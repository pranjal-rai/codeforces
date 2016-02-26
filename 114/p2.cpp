//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
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

void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//LL power(LL a, LL p){LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    FastIO(); 
    string str;
    vector <string> v;
    VI vec;
    char c;
    int i,l,j=0,n;
    while(getline(cin,str))
    {
        v.PB(str);
        l=str.length();
        c=' ';
        for(i=0;i<l;i++)
        {
            if(str[i]!=' ')
            {
                c=str[i];
                break;
            }
        }
        if(c=='#'&&l!=0)
            vec.PB(1);
        else
            vec.PB(0);
    }
    n=v.size();
    for(i=0;i<n;i++)
    {
        if(vec[i])
            cout <<v[i]<<"\n";
        else
        {
            l=v[i].size();
            for(j=0;j<l;j++)
                if(v[i][j]!=' ')
                    cout <<v[i][j];
            if(i!=(n-1)&&vec[i+1]==1)
                cout <<"\n";
        }
    }
    if(vec[n-1]==0)
        cout <<"\n";
    return 0;
}
