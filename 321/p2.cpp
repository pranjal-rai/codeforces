//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;

//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
LL n,d,i,m,s,max1,sum,dp[100010];
VLL v1;
VLL ::iterator it;
vector <pair<LL,LL> > v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL index;
    cin >>n>>d; 
    max1=0;
    for(i=0;i<n;i++)
    {
        cin >>m>>s;
        v.PB(MP(m,s));
    }
    sort(all(v));
    for(i=0;i<n;i++)
        v1.PB(v[i].F);
    dp[0]=v[0].S;
    for(i=1;i<n;i++)
        dp[i]=dp[i-1]+v[i].S;
    for(i=0;i<n;i++)
    {
        it=lower_bound(v1.begin()+i,v1.end(),v1[i]+d);
        index=i;
        if(it!=v1.begin())
        {
            index=it-v1.begin()-1;
        }
        if(i!=0)
        sum=dp[index]-dp[i-1];
        else
            sum=dp[index];
        if(sum>max1)
            max1=sum;
    }
    cout <<max1<<"\n";
    return 0;
}
