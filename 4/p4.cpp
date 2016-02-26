//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int j,maximum,n,w,h,i,wx,hx,n1=0,maxw,maxh,l,index,maxele,maxind;
    pair <long long int,long long int> mypair;
    vector  <long long int> vecf(6000,0),dp(6000,0),vecq;
    pair < pair <long long int,long long int>,long long int> mp;
    vector < pair < pair <long long int,long long int>,long long int> > vec;
    cin >>n>>w>>h;
    for(i=0;i<n;i++)
    {
        cin >>wx>>hx;
        if(wx>w&&hx>h)
        {
            n1++;
            mypair.first=wx;
            mypair.second=hx;
            mp.first=mypair;
            mp.second=i+1;
            vec.push_back(mp);
        }
    }
    n=n1;
    if(n==0)
        cout<<0<<"\n";
    else{
    sort(vec.begin(),vec.end());
    maxw=w,maxh=h;
    maxele=INT_MIN;
    for(i=0;i<n;i++)
    {
        maximum=INT_MIN;
        for(j=0;j<i;j++)
        {
            if(vec[j].first.first<vec[i].first.first&&vec[j].first.second<vec[i].first.second)
            {
                if(dp[j]>maximum)
                {
                    maximum=dp[j];
                    index=j;
                }
            }
        }
        if(maximum==INT_MIN)
        { dp[i]=1;
            vecf[i]=-1;}
        else{
        dp[i]=dp[index]+1;
        vecf[i]=index;
        }
        if(dp[i]>maxele){
            maxele=dp[i];
            maxind=i;
        }
    }
    cout<<dp[maxind]<<"\n";
    int l=dp[maxind];
    while(1)
    {
        vecq.push_back(vec[maxind].second);
        maxind=vecf[maxind];
        if(maxind==-1)
            break;
    }
    reverse(vecq.begin(),vecq.end());
    for(i=0;i<l;i++)
        cout <<vecq[i]<<" ";
    cout <<"\n";

            }
            
}

