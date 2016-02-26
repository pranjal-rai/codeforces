//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,s,i,var,flag=1;
    vector <int> vec1,vec2;
    vector < pair <int,int> > vec;
    pair <int,int> mypair;
    cin >>s>>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec1.push_back(var);
        cin >>var;
        vec2.push_back(var);
    }
    for(i=0;i<n;i++)
    {
        mypair.first=vec1[i];
        mypair.second=vec2[i];
        vec.push_back(mypair);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<n;i++)
    {
        if(vec[i].first>=s)
        {
            flag=0;
            break;
        }
        else
        {
            s=s+vec[i].second;
        }
    }
    if(flag==0)
        cout <<"NO\n";
    else
        cout <<"YES\n";
    return 0;
}

