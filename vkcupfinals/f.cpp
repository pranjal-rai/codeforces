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
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL j,n,i,var,x,maxv,val;
    VLL v,freq(1000010,0),ans(1000010,0);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
        freq[var]++;
    }
    for(i=n-1;i>=0;i--)
    {
        x=v[i];
        maxv=0,val=-1;
        for(j=2;j*x<=1000000;j++)
        {
            if(freq[j*x]==1)
            {
                if(ans[j*x]>=maxv)
                {
                    maxv=ans[j*x];
                    val=j*x;
                }
            }
        }
        if(val!=-1)
            ans[x]=ans[val]+1;
    }
    val=1;
    for(i=1;i<=1000000;i++)
    {
        if((ans[i]+1)>val)
            val=ans[i]+1;
    }
    cout <<val<<"\n";
    return 0;
}
