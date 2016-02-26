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
    long long int n,m,x,i,c,t;
    vector < pair<long long int,long long int> > vec;
    pair<long long int,long long int> mypair;
    vector < pair < long long int,long long int> >::iterator low;
    cin >>n>>m;
    x=0;
    for(i=0;i<n;i++)
    {
        cin >>c>>t;
        mypair.first=x+c*t;
        mypair.second=i;
        vec.push_back(mypair);
        x=mypair.first;
    }
    for(i=0;i<m;i++)
    {
        cin >>x;
        mypair.first=x;
        mypair.second=0;
        low=lower_bound(vec.begin(),vec.end(),mypair);
       // cout <<(*low).first<<"\n";
     //   if((*low).first==x)
            cout <<((*low).second)+1<<"\n";
      /*  else
        {
            if((low+1)!=vec.end())
            cout <<((*(low+1)).second)+1<<"\n";
        }*/
    }
    return 0;

}

