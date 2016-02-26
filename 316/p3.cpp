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
    LL n,m,sum=0,x,i,ans=0;
    char c,c1;
    string str;
    cin >>n>>m;
    cin >>str;
    for(i=0;i<n;i++)
    {
        if(str[i]!='.')
        {
            if(ans!=0)
                sum=sum+(ans-1);
            ans=0;
        }
        else
            ans++;
    }
    if(ans!=0)
        sum=sum+(ans-1);
    ans=sum;
    for(i=0;i<m;i++)
    {
        cin >>x>>c;
        x=x-1;
        if(str[x]==c)
            cout <<ans<<"\n";
        else
        {
            c1=str[x];
            if(c1!='.'&&c!='.')
                cout <<ans<<"\n";
            else
            {
                if(c=='.')
                {
                    if(x==0)
                    {
                        if(n!=1&&str[x+1]=='.')
                            ans=ans+1;
                    }
                    else if(x==n-1)
                    {
                        if(str[x-1]=='.')
                            ans=ans+1;
                    }
                    else
                    {
                        if(str[x-1]=='.'&&str[x+1]=='.')
                            ans=ans+2;
                        else if(str[x-1]=='.')
                            ans=ans+1;
                        else if(str[x+1]=='.')
                            ans=ans+1;
                    }
                }
                else
                {
                    if(x==0)
                    {
                        if(n!=1&&str[x+1]=='.')
                            ans=ans-1;
                    }
                    else if(x==n-1)
                    {
                        if(str[x-1]=='.')
                            ans=ans-1;
                    }
                    else
                    {
                        if(str[x-1]=='.'&&str[x+1]=='.')
                            ans=ans-2;
                        else if(str[x-1]=='.')
                            ans=ans-1;
                        else if(str[x+1]=='.')
                            ans=ans-1;
                    }
                }
                cout <<ans<<"\n";
            }
                str[x]=c;
        }
    }
    return 0;
}
