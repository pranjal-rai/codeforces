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
set<int> s;
set<int>::iterator it;
int val[1000010]={0};
int arr[8010][8010]={0};
VPII vec,vec1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int l,w,n,a,b,x1,y1,x2,y2,x3,y3,i,j,k,counter1,counter2,counter3,counter;
    LL ans=-1,ans1;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>a>>b;
        s.insert(a);
        s.insert(b);
        vec.PB(MP(a,b));
        vec1.PB(MP(min(a,b),max(a,b)));
    }
    it=s.begin();
    counter=1;
    while(it!=s.end())
    {
        val[*it]=counter;
        counter++;
        it++;
    }
    for(i=0;i<n;i++)
    {
        a=val[vec1[i].F];
        b=val[vec1[i].S];
        arr[a][b]++;
    }
    for(i=counter;i>=1;i--)
        for(j=counter;j>=1;j--)
            arr[i][j]=arr[i][j]+arr[i][j+1]+arr[i+1][j]-arr[i+1][j+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x1=min(vec[i].F,vec[j].S);
            y1=max(vec[i].F,vec[j].S);
            counter1=arr[val[x1]][val[y1]];
            if(i!=j)
            {
                x2=min(vec[i].F,vec[j].F);
                y2=max(vec[i].F,vec[j].F);
                counter2=arr[val[x2]][val[y2]];
                x3=min(vec[i].S,vec[j].S);
                y3=max(vec[i].S,vec[j].S);
                counter3=arr[val[x3]][val[y3]];
            }
            /*counter1=0,counter2=0,counter3=0;
            for(k=0;k<n;k++)
            {
                a=min(vec[k].F,vec[k].S);
                b=max(vec[k].F,vec[k].S);
                if(b>=y1&&a>=x1)
                    counter1++;
                if(i!=j)
                {
                    if(b>=y2&&a>=x2)
                        counter2++;
                    if(b>=y3&&a>=x3)
                        counter3++;
                }
            }*/
            ans1=1LL*x1*y1*counter1;
            if(ans<ans1)
            {
                ans=ans1;
                l=x1,w=y1;
            }
            if(i!=j)
            {
                ans1=1LL*x2*y2*counter2;
                if(ans<ans1)
                {
                    ans=ans1;
                    l=x2,w=y2;
                }
                ans1=1LL*x3*y3*counter3;
                if(ans<ans1)
                {
                    ans=ans1;
                    l=x3,w=y3;
                }
            }
        }
    }
    cout <<ans<<"\n";
    cout <<l<<" "<<w<<"\n";
    return 0;
}
