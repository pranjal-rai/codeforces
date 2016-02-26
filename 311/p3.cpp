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
LL n,i,j,l,d,cost,cost1,maxx,x,y,counter,ans,p;
LL freq[100010]={0},dp[100010]={0},sum[100010]={0},len[201]={0};
vector <LL> v;
set <LL> s;
set <LL>::iterator it;
vector <vector <LL> > vec(201);
vector <LL>::iterator it1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>l;
        v.PB(l);
        s.insert(l);
        freq[l]++;
    }
    for(i=1;i<=100000;i++)
        dp[i]=dp[i-1]+freq[i];
    for(i=0;i<n;i++)
    {
        cin >>d;
        vec[d].PB(v[i]);
        sum[v[i]]=sum[v[i]]+d;
    }
    for(i=1;i<=200;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        len[i]=vec[i].size();
    }
    it=s.end();
    l=s.size();
    if(l!=0)
        it--;
    cost=0,cost1=0,ans=LLONG_MAX;
    while(1)
    {
        maxx=*it;
        x=freq[maxx];
        y=dp[maxx];
        counter=x*2-1;
        cost=cost1;
        if(y<=counter)
            ans=min(cost,ans);
        else
        {
            counter=y-counter;
            for(i=1;i<=200&&counter!=0;i++)
            {
                it1=lower_bound(vec[i].begin(),vec[i].end(),maxx);
                if(it1!=vec[i].end()||(len[i]!=0&&(*(--(vec[i].end())))<maxx))
                {
                    p=it1-vec[i].begin();
                    if(p<=counter)
                    {
                        counter=counter-p;
                        cost=cost+i*p;
                    }
                    else
                    {
                        cost=cost+counter*i;
                        counter=0;
                    }
                }
            }
        }
        ans=min(cost,ans);
        cost1=cost1+sum[maxx];
        if(l>1)
        {
            it--;
            l--;
        }
        else
            break;
    }
    cout <<ans<<"\n";
    return 0;
}
