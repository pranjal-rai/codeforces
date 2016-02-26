//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int xi,yi,xf,yf,n,i,r,a,b,j;
map <pair<int,int>,int> m;
pair <int,int> mypair;
pair<pair<int,int>,int> mp;
queue <pair<pair<int,int>,int> > q;
int isvalid(int x,int y)
{
    if(x>=1&&x<=1000000000&&y>=1&&y<=1000000000)
        return 1;
    return 0;
}
int check(int x,int y,int d)
{
    if(isvalid(x,y)==0)
        return -1;
    int flag=-1;
    mypair.first=x,mypair.second=y;
    if(m.find(mypair)!=m.end()&&m[mypair]==0)
    {
        mp.first=mypair;
        mp.second=d+1;
        q.push(mp);
        m[mypair]=1;
        if(mypair.first==xf&&mypair.second==yf)
            flag=d+1;
    }
    return flag;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ans=-1,d,x,y;
    cin >>xi>>yi>>xf>>yf;   
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>r>>a>>b;
        mypair.first=r;
        mp.second=0;
        for(j=a;j<=b;j++)
        {
            mypair.second=j;
            mp.first=mypair;
            m.insert(mp);
        }
    }
    mypair.first=xi;
    mypair.second=yi;
    mp.first=mypair;
    mp.second=0;
    q.push(mp);
    m[mypair]=1;
    while(q.empty()==0)
    {
        mp=q.front();
        q.pop();
        x=mp.first.first;
        y=mp.first.second;
        d=mp.second;
        for(i=-1;i<=1;i++)for(j=-1;j<=1;j++){
        ans=check(x+i,y+j,d);
        if(ans!=-1){goto xyz;
            break;}
        }
    }
xyz:
    cout <<ans<<"\n";
    return 0;
}
