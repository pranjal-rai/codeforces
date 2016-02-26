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
LL n,i,var,vol,steps;
vector <LL> v;
queue <pair<LL,LL> > q;
LL vis[100010]={0},cnt[100010]={0},ans[100010]={0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
    }
    for(i=0;i<n;i++)
    {
        q.push(MP(v[i],0));
        vis[v[i]]=i+1;
        while(q.empty()==0)
        {
            vol=(q.front()).F;
            steps=(q.front()).S;
            if(vol*2<=100000&&vis[vol*2]!=(i+1))
            {
                vis[vol*2]=i+1;
                q.push(MP(vol*2,steps+1));
            }
            if(vol/2>0&&vis[vol/2]!=(i+1))
            {
                vis[vol/2]=i+1;
                q.push(MP(vol/2,steps+1));
            }
            ans[vol]+=steps;
            cnt[vol]++;
            q.pop();
        }
    }
    LL ans1=INT_MAX;
    for(i=1;i<=100000;i++)
    {
        if(cnt[i]==n)
            ans1=min(ans1,ans[i]);
    }
    cout <<ans1<<"\n";
    return 0;
}
