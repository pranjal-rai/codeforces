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
vector <LL> f(26,0);
vector <vector<LL> > M(400010,f);
string str;
LL n,q;
void build(LL node,LL a,LL b)
{
    if(a==b)
    {
        M[node][str[a]-'a']=1;
        return;
    }
    LL p=node*2,mid=(a+b)/2;
    build(p,a,mid);
    build(p+1,mid+1,b);
    for(int i=0;i<26;i++)
        M[node][i]=M[p][i]+M[p+1][i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>q;
    cin >>str;
    build(1,0,n-1);
    for(i=0;i<q;i++)
    {


            
    return 0;
}
