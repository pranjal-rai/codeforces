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
    long long int n,i,ans=0,j;
    double x,y,a,b,c;
    map <pair<double,double>,long long int> mp;
    pair <double,double> p1,p2;
    map <pair<double,double>,long long int>::iterator it;
    vector <pair<double,double> > vec;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>x>>y;
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(i==j)continue;
            p1=vec[i];
            p2=vec[j];
            a=p1.S-p2.S;
            b=p1.F-p2.F;
            c=-a*(p1.F)+b*(p1.S);
            if(b<0.0000001&&b>-0.000001){
                mp[make_pair(-INT_MAX*1.0,(p1.F)*1.0)]++;}
            else{
                mp[make_pair(a/b,c/b)]++;
            }
        }
    }
    it=mp.begin();
    ans=(n*(n-1)*(n-2))/6;
    while(it!=mp.end())
    {
        x=(long long int)(mp[(*it).F]);
        x=(-1+(long long int)(sqrt(1+8*x)))/2;
//        cout <<(*it).F.F<<" "<<mp[(*it).F]<<"\n";
        ans=ans-((x+1)*x*(x-1))/6;
        it++;
    }
    cout <<ans<<"\n";
    return 0;
}
