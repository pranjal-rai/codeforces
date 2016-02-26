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
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
LL wr,lr,M=INT_MAX;
LL cal(LL wt,LL lt)
{
//    cout <<lr<<" "<<lt<<" "<<wr<<" "<<wt<<"a\n";
    LL x,y,counter1=0,a,b,z,count=0,count1=0;
    x=lr/lt;
    y=wr/wt;
    if((x==0||y==0)&&(lr/wt!=0&&wr/lt!=0))
        return M;
    counter1=(x*y);
    a=lr%lt;
    b=wr%wt;
    if(a!=0)
    {   
        z=y;
        if(b!=0)
            z++;
        count=0;
        while(z!=0)
        {
            if((z-lt/a)>=0)
                z=z-lt/a;
            else 
                z=0;
            count++;
        }
    }
    if(b!=0)
    {
        z=x;
        while(z!=0)
        {
            if((z-wt/b)>=0)
                z=z-wt/b;
            else 
                z=0;
            count++;
        }
    }
    if(a!=0)
    {   
        z=y;
        count1=0;
        while(z!=0)
        {
            if((z-lt/a)>=0)
                z=z-lt/a;
            else 
                z=0;
            count1++;
        }
    }
    if(b!=0)
    {
        z=x;
        if(a!=0)
            z++;
        while(z!=0)
        {
            if((z-wt/b)>=0)
                z=z-wt/b;
            else 
                z=0;
            count1++;
        }
    }
    //cout <<count<<" "<<count1<<"\n";
    counter1+=min(count,count1);
    //cout <<counter1<<"\n";
    return counter1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL wt,lt;
    cin >>wr>>lr;//road
    cin >>wt>>lt;//tile
    cout <<min(cal(wt,lt),cal(lt,wt))<<"\n";
    return 0;
}
