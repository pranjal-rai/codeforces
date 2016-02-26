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
    int i,var;
    string str;
    vector <int> vec,vecf;
    set <string> myset;
    set <string>::iterator it;
    multiset <string> mp;
    int n,m;
    cin >>n>>m;
    for(i=0;i<n;i++){
        cin >>var;
        vec.push_back(var);
    }
    for(i=0;i<m;i++)
    {
        cin >>str;
        myset.insert(str);
        mp.insert(str);
    }
    it=myset.begin();
    while(it!=myset.end())
    {
        vecf.push_back(mp.count(*it));
        it++;
    }
    sort(vecf.rbegin(),vecf.rend());
    sort(vec.begin(),vec.end());
    int minimum=0,maximum=0;
    int l=vecf.size();
    for(i=0;i<l;i++){
        minimum+=(vecf[i]*vec[i]);}
    sort(vec.rbegin(),vec.rend());
    for(i=0;i<l;i++)
        maximum+=(vecf[i]*vec[i]);
    cout <<minimum<<" "<<maximum<<"\n";
    return 0;
}
