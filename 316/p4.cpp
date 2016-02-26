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
LL timer=0;
VPLL timex(500100);
vector <VLL> v(500100),vec(500100);
vector <string> strdata(500100);
vector <vector <pair<PLL,LL> > > vec_sorted(500100);
vector <LL> samp(26,0);
vector <vector<LL> > freq(500100,samp);
void dfs(LL x,LL depth)
{
    timer++;
    LL start_time=timer,end_time,i,l;
    vec[depth].PB(x);
    l=v[x].size();
    for(i=0;i<l;i++)
    {
        dfs(v[x][i],depth+1);
    }
    end_time=timer;
    timex[x]=MP(start_time,end_time);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL n,m,i,var,l,j;
    string str,str1;
    cin >>n>>m;
    for(i=2;i<=n;i++)
    {
        cin >>var;
        v[var].PB(i);
    }
    dfs(1,1);
    cin >>str;
    for(i=1;i<=n;i++)
    {
        l=vec[i].size();
        for(j=0;j<l;j++)
        {
            vec_sorted[i].PB(MP(timex[vec[i][j]],vec[i][j]));
        }
        sort(all(vec_sorted[i]));
        str1="";
        for(j=0;j<l;j++)
        {
            str1+=str[vec_sorted[i][j].S-1];
            freq[i][str1-'a']++;
        }

        strdata[i]=str1;
        
    }
    return 0;
}
