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
LL i,n,var,w,flag[1000010]={0},counter[1000010]={0},start[1000010],end[1000010],p,q,ans,ans1,l,r;
set <LL> s;
set <LL>::iterator it;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    w=0;
    for(i=0;i<n;i++)
    {
        cin >>var;
        s.insert(var);
        if(flag[var]==0)
        {
            flag[var]=1;
            start[var]=i;
        }
        counter[var]++;
        w=max(counter[var],w);
        end[var]=i;
    }
    it=s.begin();
    ans1=INT_MAX;
    ans=INT_MIN;
    while(it!=s.end())
    {
        p=*it;
        q=end[p]-start[p]+1;
        if(counter[p]>=ans)
        {
            if(counter[p]==ans&&q<=ans1)
            {
                ans1=q;
                l=start[p]+1;
                r=end[p]+1;
                ans=counter[p];
            }
            else if(counter[p]>ans)
            {
                ans1=q;
                l=start[p]+1;
                r=end[p]+1;
                ans=counter[p];
            }
            
        }
        it++;
    }
    cout <<l<<" "<<r<<"\n";
    return 0;
}
