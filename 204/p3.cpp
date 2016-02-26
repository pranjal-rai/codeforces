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
    int n,i,j,var1,ans;
    vector <double> v;
    vector <pair<double,int> > v1,v2;
    int vis[2010]={0};
    double d,var,ans1=0;
    cin >>n;
    for(i=0;i<2*n;i++)
    {
        cin >>var;
        ans1+=var;
        v.PB(var);
        var1=var;
        d=var-var1;
        if(d<0.00001)
        {
            v1.PB(MP(0,i));
            v2.PB(MP(0,i));
        }
        else
        {
            v1.PB(MP(d,i));
            v2.PB(MP((double)(var1+(1.0-var)),i));
        }
    }
    sort(all(v1));
    sort(all(v2));
    ans=0;
    for(i=0;i<2*n;i++)
    {
        if(vis[v1[i].S]==0)
        {
            vis[v1[i].S]=1;
            ans+=v[v1[i].S];
            for(j=0;j<(2*n);j++)
            {
                if(vis[v2[j].S]==0)
                {
                    var=v[v2[j].S];
                    var1=var;
                    d=var-var1;
                    if(d<0.0001)
                        ans+=var1;
                    else
                        ans+=(var1+1);
                    vis[v2[j].S]=2;
                    break;
                }
            }
        }       
    }
    printf("%.3lf\n",fabs(ans-ans1));
    return 0;
}
