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

vector <pair<int,PII> > v;
int n,k;
int isvalid(int x,int y)
{
    if(x>=0&&x<=2&&y>=0&&y<n)
        return 1;
    return 0;
}
int issafe(int x,int y,int d)
{
    for(int i=0;i<k;i++)
    {
        if(v[i].F==x&&y>=(v[i].S.F-2*d)&&y<=(v[i].S.S-2*d))
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int d,t,i,j,s1,s2,p1,p2,e1,e2,flag,l;
    string str;
    cin >>t;
    while(t--)
    {
        cin >>n>>k;
        for(i=0;i<3;i++)
        {
            cin >>str;
            flag=0;
            for(j=0;j<n;j++)
            {
                if(str[j]=='s')
                {
                    s1=i,s2=j;
                }
                else if(flag==0&&str[j]!='.')
                {
                    flag=1;
                    p1=i,p2=j;
                }
                else if(flag==1&&str[j]=='.')
                {
                    flag=0;
                    e1=i,e2=j-1;
                    v.PB(MP(i,MP(p2,e2)));
                }
            }
            if(flag==1)
            {
                flag=0;
                v.PB(MP(i,MP(p2,n-1)));
            }
        }
        k=v.size();
        int f=0;
        int vis[110][3][110]={0};
        queue <pair<PII,int> > q;
        q.push(MP(MP(s1,s2),0));
        while(!(q.empty()))
        {
            s1=q.front().F.F;
            s2=q.front().F.S;
            d=q.front().S;
            if(s2==(n-1))
            {
                f=1;
                break;
            }
            q.pop();
            if(!issafe(s1,s2,d))
                continue;
            if(isvalid(s1,s2+1)&&issafe(s1,s2+1,d))
            {
                if(isvalid(s1-1,s2+1)&&!vis[d+1][s1-1][s2+1]&&issafe(s1-1,s2+1,d))
                {
                    q.push(MP(MP(s1-1,s2+1),d+1));
                    vis[d+1][s1-1][s2+1]=1;
                }
                if(isvalid(s1+1,s2+1)&&!vis[d+1][s1+1][s2+1]&&issafe(s1+1,s2+1,d))
                {
                    q.push(MP(MP(s1+1,s2+1),d+1));
                    vis[d+1][s1+1][s2+1]=1;
                }
                if(!vis[d+1][s1][s2+1])
                {
                    q.push(MP(MP(s1,s2+1),d+1));
                    vis[d+1][s1][s2+1]=1;
                }
            }
        }
        if(f)
            cout <<"YES\n";
        else
            cout <<"NO\n";
        v.clear();
    }
    return 0;
}
