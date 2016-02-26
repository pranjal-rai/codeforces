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
LL n,k;
vector <LL> v(300010),v1(300010),v2(300010);
LL var,count1=0,count2=0,count3=0,i,sum=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>k;
    for(i=1;i<=n;i++)
    {
        cin >>var;
        v[i]=var;
    }
    for(i=1;i<=(n-k);i++)
    {
        v1[i]=1;
        v2[i+k]=1;
    }
    for(i=1;i<=n;i++)
        cout <<v1[i]<<" ";
    cout <<"\n";
    for(i=1;i<=n;i++)
        cout <<v2[i]<<" ";
    cout <<"\n";
    for(i=1;i<=n;i++)
    {
        if(v1[i]==1&&v2[i]==0)
            count1++;
        else if(v1[i]==1&&v2[i]==1)
            count2++;
        else if(v1[i]==0&&v2[i]==1)
            count3++;
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(i=1;i<=count1;i++)
    {
        sum+=v[i];
    }
    for(i=n;count3!=0;i--)
    {
        count3--;
        sum+=v[i];
    }
    cout <<sum<<"\n";
    return 0;
}
