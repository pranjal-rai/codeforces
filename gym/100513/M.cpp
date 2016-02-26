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

//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,j,l;
    char c;
    string str;
    vector <string> v;
    cin >>n;
    getline(cin,str);
    for(i=0;i<n;i++)
    {
       getline(cin,str);
       v.PB(str);
    }
    stack <pair<pair<char,int>,pair<int,int> > > s,s_copy;
    pair<pair<char,int>,pair<int,int> > mp;
    int scope=0,currscope;
    for(i=0;i<n;i++)
    {
        str=v[i];
        l=v[i].size();
        for(j=0;j<l;j++)
        {
            c=v[i][j];
            if(c!=' ')
            {
                if(c>='a'&&c<='z')
                {
                    s_copy=s;
                    while(!(s_copy.empty()))
                    {
                        mp=s_copy.top();
                        if(mp.F.F==c)
                        {
                            cout <<i+1<<":"<<j+1<<": warning: shadowed declaration of "<<c<<", the shadowed position is "<<mp.S.F<<":"<<mp.S.S<<"\n";
                            break;
                        }
                        s_copy.pop();
                    }
                    s.push(MP(MP(c,scope),MP(i+1,j+1)));
                }
                else if(c=='{')
                    scope++;
                else
                {
                    s_copy=s;
                    while(!(s_copy.empty()))
                    {
                        mp=s_copy.top();
                        currscope=mp.F.S;
                        if(currscope==scope)
                        {
                            s_copy.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    s=s_copy;
                    scope--;
                }
            }
        }
    }
    return 0;
}
