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
int ispalin(int x)
{
    int num=0,y=x;
    while(x!=0)
    {
        num=num*10+(x%10);
        x=x/10;
    }
    if(y==num)
        return 1;
    else
        return 0;
}
vector <LL> prime(2000010,1),palin(2000010,0),pie(2000010,0),rub(2000010,0);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL i,j,ans,p,q;
    prime[1]=0;
    palin[1]=1;
    for(i=2;i<=2000000;i++)
    {
        if(ispalin(i))
            palin[i]=1;
        if(prime[i]==1)
        {
            for(j=2;j*i<=2000000;j++)
            {
                prime[i*j]=0;
            }
        }
    }
    pie[0]=0,rub[0]=0;
    for(i=1;i<=2000000;i++)
    {
        if(palin[i]==1)
            rub[i]=rub[i-1]+1;
        else
            rub[i]=rub[i-1];
        if(prime[i]==1)
            pie[i]=pie[i-1]+1;
        else
            pie[i]=pie[i-1];
    }
    cin >>p>>q;
    LL a=1,b=2000000,m;
    ans=-1;
    for(i=a;i<=b;i++)
    {
        if(q*pie[i]<=p*rub[i])
            ans=i;
    }
    if(ans==-1)
        cout <<"Palindromic tree is better than splay tree\n";
    else
        cout <<ans<<"\n";
    return 0;
}   
