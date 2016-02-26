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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL n,i,l,v,d,p,vis[4010]={0},vec[4010][3],j;
    VLL ans;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>v>>d>>p;
        vis[i]=0;
        vec[i][0]=v;
        vec[i][1]=d;
        vec[i][2]=p;
    }
    i=0;
    while(1)
    {
        if(i>=n)
            break;
        if(vis[i]==-1)
        {
            i++;
            continue;
        }
        ans.PB(i+1);
        v=vec[i][0];
        for(j=i+1;j<n;j++)
        {
            if(vis[j]!=-1)
                vec[j][2]-=v;
            v--;
            if(v==0)
                break;
        }
        LL factor=0;
        for(j=i+1;j<n;j++)
        {
            if(vis[j]!=-1)
            {
                vec[j][2]-=factor;
                if(vec[j][2]<0)
                {
                    factor=factor+vec[j][1];
                    vis[j]=-1;
                }
            }
        }
        i++;
    }
    cout <<ans.size()<<"\n";
    l=ans.size();
    for(i=0;i<l;i++)
        cout <<ans[i]<<" ";
    cout <<"\n";
    return 0;
}
