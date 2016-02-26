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

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL i,n,l,x,y,var,flag1,flag2;
    vector <LL> vec;
    cin >>n>>l>>x>>y;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.PB(var);
    }
    flag1=0,flag2=0;
    for(i=0;i<n;i++)
    {
        if(binary_search(vec.begin(),vec.end(),vec[i]+x))
            flag1=1;
    }
    for(i=0;i<n;i++)
    {
        if(binary_search(vec.begin(),vec.end(),vec[i]+y))
            flag2=1;
    }
    if(flag1==1&&flag2==1)
    {
        cout <<0<<"\n";
        return 0;
    }
    else 
    {
        if(flag1==0&&flag2==1)
            cout <<1<<"\n"<<x<<"\n";
        else if(flag1==1&&flag2==0)
            cout <<1<<"\n"<<y<<"\n";
        else
        {
            for(i=0;i<n;i++)
            {
                if((binary_search(vec.begin(),vec.end(),vec[i]+x+y)||binary_search(vec.begin(),vec.end(),vec[i]+x-y))&&vec[i]+x<=l)
                {
                    cout <<1<<"\n"<<vec[i]+x<<"\n";
                    return 0;
                }
                if((binary_search(vec.begin(),vec.end(),vec[i]+y+x)||binary_search(vec.begin(),vec.end(),vec[i]+y-x))&&vec[i]+y<=l)
                {
                    cout <<1<<"\n"<<vec[i]+y<<"\n";
                    return 0;
                }
                if((binary_search(vec.begin(),vec.end(),vec[i]-x+y)||binary_search(vec.begin(),vec.end(),vec[i]-x-y))&&(vec[i]-x)>=0)
                {
                    cout <<1<<"\n"<<vec[i]-x<<"\n";
                    return 0;
                }
                if((binary_search(vec.begin(),vec.end(),vec[i]-y+x)||binary_search(vec.begin(),vec.end(),vec[i]-y-x))&&(vec[i]-y)>=0)
                {
                    cout <<1<<"\n"<<vec[i]-y<<"\n";
                    return 0;
                }
            }
            cout <<2<<"\n"<<vec[0]+x<<" "<<vec[0]+y<<"\n";
        }
    }
    return 0;
}
