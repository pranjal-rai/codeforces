//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
map <pair<string,string>,set<int> > mp;
set <int> s1,s2;
pair<string,string> mypair;
map <pair<string,string>,int > mp1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,d,i,t;
    string str1,str2;
    cin >>n>>d;
    for(i=0;i<n;i++)
    {
        cin >>str1>>str2>>t;
        mp[MP(str1,str2)].insert(t);
    }
    auto it=mp.begin();
    while(it!=mp.end())
    {
        s1=it->S;
        str1=mypair.F=(it->F).S;
        str2=mypair.S=(it->F).F;
        s2=mp[mypair];
        auto it1=s1.begin();
        while(it1!=s1.end())
        {
            auto it2=s2.upper_bound(*it1);
            if(it2!=s2.end()&&(*it2-*it1)<=d)
            {
                mp1[MP(min(str1,str2),max(str1,str2))]=1;
                break;
            }
            it1++;
        }
        it++;
    }
    auto it3=mp1.begin();
    cout <<mp1.size()<<"\n";
    while(it3!=mp1.end())
    {
        cout <<(it3->F).F<<" "<<(it3->F).S<<"\n";
        it3++;
    }
    return 0;
}
