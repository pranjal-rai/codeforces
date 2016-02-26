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
    long long int i,n,v,t,p,x,y,fi,fj,sum=0,maximum=INT_MIN,j;
    cin >>n>>v;
    vector <pair<long long int,long long int> > vec1,vec2;
    vector <long long int> cvec1,cvec2,vec;
    pair<long long int,long long int> mypair;
    for(i=0;i<n;i++)
    {
        cin >>t>>p;
        if(t==1)
        {
            mypair.first=p;
            mypair.second=i+1;
            vec1.push_back(mypair);
        }
        else{
            mypair.first=p;
            mypair.second=i+1;
            vec2.push_back(mypair);
        }
    }
    sort(vec1.rbegin(),vec1.rend());
    sort(vec2.rbegin(),vec2.rend());
    x=vec1.size();
    y=vec2.size();
    for(i=0;i<x;i++)
    {
        mypair=vec1[i];
        p=mypair.first;
        if(i==0)
            cvec1.push_back(p);
        else
            cvec1.push_back(p+cvec1[i-1]);
    }
    for(i=0;i<y;i++)
    {
        mypair=vec2[i];
        p=mypair.first;
        if(i==0)
            cvec2.push_back(p);
        else
            cvec2.push_back(p+cvec2[i-1]);
    }
    for(i=0;i<=x;i++)
    {
        sum=0;
        j=min((v-i)/2,y);
        if(j<0)j=0;
        if(i>0)
            sum=sum+cvec1[i-1];
        if(j>0)
            sum=sum+cvec2[j-1];
        if(sum>maximum&&((i+2*j)<=v))
        {
            maximum=sum;
            fi=i;
            fj=j;
        }
    }
  //  if(n==6647&&v==1319)
//        cout <<x<<" "<<y<<" "<<fi<<" "<<fj<<"\n";
    cout <<maximum<<"\n";
    for(i=0;i<fi;i++)
        vec.push_back(vec1[i].second);
    for(j=0;j<fj;j++)
        vec.push_back(vec2[j].second);
    sort(vec.begin(),vec.end());
    for(i=0;i<(fi+fj);i++)
        cout <<vec[i]<<" ";
    cout <<"\n";
    return 0;
}
