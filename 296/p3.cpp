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
    long long int pr;
    int w,h,n,i,val,p,q;
    char c;
    cin >>w>>h>>n;
    set <int> s1,s2;
    set <int>::iterator it1,it2;
    multiset <int> ms1,ms2;
    s1.insert(0);
    s1.insert(h);
    s2.insert(0);
    s2.insert(w);
    ms1.insert(h);
    ms2.insert(w);
    for(i=0;i<n;i++)
    {
        cin >>c>>val;
        if(c=='H')
        {
            it1=s1.upper_bound(val);
            q=(*it1);
            p=*(--it1);
            ms1.erase(ms1.find(q-p));    
            ms1.insert(q-val);
            ms1.insert(val-p);
            s1.insert(val);
        }
        if(c=='V')
        {
            it2=s2.upper_bound(val);
            q=(*it2);
            p=*(--it2);
            ms2.erase(ms2.find(q-p));    
            ms2.insert(q-val);
            ms2.insert(val-p);
            s2.insert(val);
        }
        pr=(((long long int)(*(--(ms1.end()))))*((long long int)(*(--(ms2.end())))));
        cout <<pr<<"\n";
    }
    return 0;
}
