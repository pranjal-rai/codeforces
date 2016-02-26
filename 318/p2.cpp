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
LL n,m,i,a,b,j,k,l,ans,tmp;
int arr[4010][4010]={0};
vector <vector<int> > v(4010);
int len[4010]={0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    ans=INT_MAX;
    for(i=0;i<m;i++)
    {
        cin >>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
        v[a].PB(b);
        v[b].PB(a);
    }
    for(i=1;i<=n;i++)
        len[i]=v[i].size();
    for(i=1;i<=n;i++)
    {
        l=len[i];
        for(j=0;j<l;j++)
        {
            for(k=j+1;k<l;k++)
            {
                if(arr[v[i][j]][v[i][k]])
                {
                    tmp=len[i]+len[v[i][j]]+len[v[i][k]]-6;
                    if(tmp<ans)
                    {
                        ans=tmp;
                    }
                }
            }
        }
    }
    if(ans!=INT_MAX)
    cout <<ans<<"\n";
    else
        cout <<-1<<"\n";
    return 0;
}
