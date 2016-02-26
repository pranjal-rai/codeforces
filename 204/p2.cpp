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
    int n,var,i,l,flag,d,j;
    vector <VI> v(100010);
    VPII vec;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v[var].PB(i);
    }
    for(i=1;i<=100000;i++)
    {
        l=v[i].size();
        if(l==0)
            continue;
        if(l==1)
        {
            vec.PB(MP(i,0));
            continue;
        }
        if(l==2)
        {
            vec.PB(MP(i,v[i][1]-v[i][0]));
            continue;
        }
        flag=1;
        d=v[i][1]-v[i][0];
        for(j=2;j<l;j++)
        {
            if(v[i][j]-v[i][j-1]!=d)
                flag=0;
        }
        if(flag==0)
            continue;
        else
            vec.PB(MP(i,d));
    }
    l=vec.size();
    cout <<l<<"\n";
    for(i=0;i<l;i++)
        cout <<vec[i].F<<" "<<vec[i].S<<"\n";
    return 0;
}
