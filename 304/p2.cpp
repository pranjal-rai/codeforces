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
    int n,i,var,counter=0;
    multiset <int> s,s1;
    multiset <int>::iterator it;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        s.insert(var);
    }
    for(i=1;i<=(10000);i++)
    {
        if(s.find(i)==s.end())
            s1.insert(i);
    }
    for(i=1;i<=n;i++)
    {
        while(s.count(i)>1)
        {
            s.erase(s.find(i));
            it=s1.lower_bound(i);
            counter+=((*it)-i);
            s1.erase(it);
            s.insert(*it);
        }
    }
    cout <<counter<<"\n";
    return 0;
}
