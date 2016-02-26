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
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    LL n,s,i,p,vol,len,flag1=0,flag2=0,counter1=0,counter2=0;
    char c;
    VPLL vec1;
    map <LL,LL> map1,map2;
    map <LL,LL>::iterator it;
    map <LL,LL>::iterator it1;
    cin >>n>>s;
    for(i=0;i<n;i++)
    {
        cin >>c>>p>>vol;
        if(c=='S')
        {
            if(p==0)
            {
                flag1=1;
                counter1+=vol;
            }
            else
            map1[p]=map1[p]+vol*p;
        }
        else
        {
            if(p==0)
            {
                flag2=1;
                counter2+=vol;
            }
            else
            map2[p]=map2[p]+vol*p;
        }
    }
    if(flag1==1)
    {
        vec1.PB(MP(0,counter1));
        i=1;
    }
    else i=0;
    it=map1.begin();
    for(;i<s&&(it!=map1.end());i++)
    {
        vec1.PB(MP(it->F,(it->S)/(it->F)));
     //   cout <<"S"<<" "<<it->F<<" "<<(it->S)/(it->F)<<"\n";
            it++;
    }
    len=vec1.size();
    for(i=len-1;i>=0;i--)
    {
        cout <<"S"<<" "<<vec1[i].F<<" "<<vec1[i].S<<"\n";
    }
    it=map2.end();
    for(i=0;i<s&&(it!=map2.begin());i++)
    {
        it1=it;
        --it1;
        //vec2.PB(MP(it1->F,(it1->S)/(it1->F)));
        cout <<"B"<<" "<<it1->F<<" "<<(it1->S)/(it1->F)<<"\n";
        it--;
    }
    if(flag2==1&&i<s)
    {
        cout <<"B"<<" "<<"0"<<" "<<counter2<<"\n";
    }
    return 0;
}
