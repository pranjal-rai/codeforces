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
LL val,n,m,a,l,l1,l2,i,k,j;
VLL v;
LL cum[200010],cum0[200010],cum1[200010];
VPLL one,zero;
int check(LL x)
{
    LL val;
    if(x!=n)
    val=cum[n-1]-cum[n-x-1];
    else
    val=cum[n-1];
    if(val>=m)
        return 1;
    return 0;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        cin >>a>>l;
        v.PB(a);
        if(l==0)
            zero.PB(MP(a,i));
        else
            one.PB(MP(a,i));
    }
    sort(all(v));
    sort(all(zero));
    sort(all(one));
    l1=zero.size();
    l2=one.size();
    for(i=0;i<n;i++)
    {
        if(i!=0)
            cum[i]=cum[i-1]+v[i];
        else
            cum[i]=v[i];
    }
    for(i=0;i<l1;i++)
    {
        if(i!=0)
            cum0[i]=cum0[i-1]+zero[i].F;
        else
            cum0[i]=zero[i].F;
    }
    for(i=0;i<l2;i++)
    {
        if(i!=0)
            cum1[i]=cum1[i-1]+one[i].F;
        else
            cum1[i]=one[i].F;
    }
    LL it=0,r=n,mid,ans;
    l=1;
    while(it!=50)
    {
        mid=(l+r)/2;
        if(check(mid)==1)
            r=mid;
        else
            l=mid+1;
        it++;
    }
    for(i=l;i<=r;i++)
    {
        if(check(i)==1)
            break;
    }
    ans=i;
    for(i=ans;i>=0;i--)
    {
        if(i<=l2)
        {
            if(l2!=i)
            val=cum1[l2-1]-cum1[l2-i-1];
            else
            val=cum1[l2-1];
            j=ans-i;
            if(j<=l1)
            {
                if(l1!=j)
                    val=val+cum0[l1-1]-cum0[l1-j-1];
                else
                    val=val+cum0[l1-1];
                if(val>=m)
                {
                    cout <<ans<<" "<<i<<"\n";
                    for(k=l2-1;k>=l2-i;k--)
                        cout <<one[k].S+1<<" ";
                    for(k=l1-1;k>=l1-j;k--)
                        cout <<zero[k].S+1<<" ";
                    cout <<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
