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
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,var,rank[300010],k,x,y,z,j,vis[300010]={0},vis1[300010]={0},vec[100010][3];
    VPII v;
    cin >>n;
    for(i=1;i<=3*n;i++)
    {
        cin >>var;
        rank[var]=i;
    }
    for(i=0;i<n;i++)
        cin >>vec[i][0]>>vec[i][1]>>vec[i][2];
    cin >>k;
    for(i=0;i<n;i++)
    {
        x=vec[i][0],y=vec[i][1],z=vec[i][2];
        v.PB(MP(rank[x],x));
        v.PB(MP(rank[y],y));
        v.PB(MP(rank[z],z));
        sort(all(v));
        x=v[0].S,y=v[1].S,z=v[2].S;
        if(k==y||k==z)
        {
            for(j=1;j<=3*n;j++)
            {
                if(j==k)
                    continue;
                cout <<j<<" ";
            }
            cout <<"\n";
            return 0;
        }
        else if(k==x)
        {
            if(y>z)
                swap(y,z);
            for(j=1;j<y;j++)
            {
                if(vis[j])
                {
                    vis1[j]=1;
                    cout <<j<<" ";
                }
            }
            cout <<y<<" ";
            vis1[y]=1;
            for(j=y+1;j<z;j++)
            {
                if(vis[j])
                {
                    vis1[j]=1;
                    cout <<j<<" ";
                }
            }
            cout <<z<<" ";
            vis1[z]=1;
            for(j=1;j<=3*n;j++)
            {
                if(vis1[j]==0&&j!=x)
                    cout <<j<<" ";
            }
            cout <<"\n";
            return 0;
        }
        vis[x]=1,vis[y]=1,vis[z]=1;
        v.clear();
    }
    return 0;
}
