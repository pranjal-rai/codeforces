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
    int w,h,i,j,x,y,vis[20][20]={0};
    char arr[20][20];
    char c;
    cin >>w>>h;
    for(i=0;i<w;i++)
    {
        for(j=0;j<h;j++)
        {
            cin >>arr[i][j];
            if(arr[i][j]!='.'&&arr[i][j]!='*')
            {
                x=i,y=j;
            }
        }
    }
    c=arr[x][y];
    i=x,j=y;
    if(c=='U')
        x=0;
    else if(c=='R')
        x=1;
    else if(c=='D')
        x=2;
    else if(c=='L')
        x=3;
    int counter=0;
    arr[i][j]='.';
    int it=0;
    while(it<100000)
    {
        it++;
        if(!vis[i][j])
        {
            counter++;
            vis[i][j]=1;
        }
        int v[4]={0},f=0;
        while(!f)
        {
            if(v[0]==1&&v[1]==1&&v[2]==1&&v[3]==1)
                break;
            if(x==0)
            {
                v[x]=1;
                if(i>0&&arr[i-1][j]=='.')
                {
                    i=i-1;
                    f=1;
                }
                else 
                    x=(x+1)%4;
            }
            if(x==1)
            {
                v[x]=1;
                if(j<h-1&&arr[i][j+1]=='.')
                {
                    f=1;
                    j=j+1;
                }
                else 
                    x=(x+1)%4;
            }
            if(x==2)
            {
                v[x]=1;
                if(i<w-1&&arr[i+1][j]=='.')
                {
                    f=1;
                    i=i+1;
                }
                else 
                    x=(x+1)%4;
            }
            if(x==3)
            {
                v[x]=1;
                if(j>0&&arr[i][j-1]=='.')
                {
                    f=1;
                    j=j-1;
                }
                else 
                    x=(x+1)%4;
            }
        }
    }
    cout <<counter<<"\n";
    return 0;
}
