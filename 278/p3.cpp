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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int max1=-1;
int game(int a,int b,int c,int p,int q,int r)
{
    if(q<=c)
        return 0;
    if(r>=b&&q>c)
        return 1;
    while(1)
    {
        a=a-max(0,q-c);
        p=p-max(0,b-r);
        if(a<=0&&p>0)
            return 1;
        if(p<=0)
            return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int  i,j,k,a,b,c,p,q,r,d,e,f;
    cin >>p>>q>>r;
    cin >>a>>b>>c;
    cin >>d>>e>>f;
    int mincost=INT_MAX,cost;
    for(i=0;i<=210;i++)
    {
        for(j=0;j<=210;j++)
        {
            int it=0;
            int mid,k,start=0,end=210,flag=0;
            while(it<20)
            {
                mid=(start+end)/2;
                if(game(a,b,c,p+i,q+j,r+mid))
                    end=mid;
                else
                    start=mid+1;
                it++;
            }
            for(k=start;k<=end;k++)
                if(game(a,b,c,p+i,q+j,r+k))
                {
                    flag=1;
                    break;
                }
            if(flag)
            {
                cost=i*d+j*e+k*f;
                if(cost<mincost)
                    mincost=cost;
            }
        }
    }
    cout <<mincost<<"\n";
    return 0;
}
