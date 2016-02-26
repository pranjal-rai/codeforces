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
    int q,i,l;
    string str1,str2,str;
    map <string,string> mp,mp1;
    map <string,string>::iterator it;
    cin >>q;
    for(i=0;i<q;i++)
    {
        cin >>str1>>str2;
        if(mp1.find(str1)==mp1.end())
        {
            mp[str1]=str2;
            mp1[str2]=str1;
        }
        else
        {
            it=mp1.find(str1);
            str=mp1[(*it).first];
            mp.erase(mp.find(str));
            mp1.erase(it);
            mp[str]=str2;
            mp1[str2]=str;
        }
    }
    l=mp.size();
    cout <<l<<"\n";
    it=mp.begin();
    while(it!=mp.end())
    {
        cout <<(*it).first<<" "<<mp[(*it).first]<<"\n";
        it++;
    }
    return 0;
}
