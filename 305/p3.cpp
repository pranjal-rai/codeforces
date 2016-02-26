//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
map <long long int,long long int > s1,q1;

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int n1,m1,n2,m2,m,h1,a1,x1,y1,h2,a2,x2,y2,t,x,y;
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;
    t=1LL,x=h1;
    while(s1.find(x)==s1.end())
    {
        s1[x]=t;
        x=(((x%m)*(x1%m))%m+(y1%m))%m;
        t++;
    }
    if(s1[x]==1)
        n1=0;
    else
        n1=s1[x]-1;
    n2=t-n1;
    t=1LL,x=h2;
    while(q1.find(x)==q1.end())
    {
        q1[x]=t;
        x=(((x%m)*(x2%m))%m+(y2%m))%m;
        t++;
    }
    if(q1[x]==1)
        m1=0;
    else
        m1=q1[x]-1;
    m2=t-m1;
    if(s1.find(a1)==s1.end() || q1.find(a2)==q1.end())
    { 
        cout <<"-1\n";
        return 0;
    }
    else
    {
        x=s1[a1];
        y=q1[a2];
        if(n1==0&&m1==0)
        cout <<(((x*y)/(__gcd(x,y)))-1)<<"\n";
        else
        {
            if(x>n1&&y>m1)
            {
                x=x-n1;
                x=y-m1;
                z=(n2*m2)/(__gcd(n2,m2));

//                cout <<(((x*y)/(__gcd(x,y)))-1)+<<"\n";
            }
            else if(x<n1&&y<m1)
            {
                if(x==y)
                    cout <<x<<"\n";
                else
                    cout <<-1<<"\n";
            }
            else if(x>n1&&y<m1)
            {
                x=x-n1;
                if(y%x==0)
                    cout <<y<<"\n";
            }
            else if(x<n1&&y>m1)
            {
                y=y-m1;
                if(x%y==0)
                    cout <<x<<"\n";
            }
        }

    }
    return 0;
}
