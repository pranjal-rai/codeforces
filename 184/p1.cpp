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
    int k,i,var;
    VI v,v1;
    cin >>k;
    for(i=0;i<k;i++)
    {
        cin >>var;
        v.PB(var);
    }
    int flag1,flag2,flag3,flag4,flag5;
    flag1=flag2=flag3=flag4=flag5=0;
    for(i=0;i<k;i++)
    {
        if(v[i]==0)
        {
            v1.PB(v[i]);
            flag1=1;
        }
        else if(v[i]==100&&flag2==0)
        {
            v1.PB(v[i]);
            flag2=1;
        }
        else if(v[i]<10)
            flag3=i+1;
        else if(v[i]>=10&&v[i]%10!=0)
            flag4=i+1;
        else if(v[i]>=10&&v[i]%10==0&&v[i]!=100)
            flag5=i+1;
    }
    if(flag3==0&&flag5==0&&flag4!=0)
        v1.PB(v[flag4-1]);
    else if(flag3!=0)
    {
        if(flag5!=0)
        {
        v1.PB(v[flag5-1]);
        v1.PB(v[flag3-1]);
        }
        else
        v1.PB(v[flag3-1]);
    }
    else if(flag5!=0)
        v1.PB(v[flag5-1]);
    cout <<v1.size()<<"\n";
    for(i=0;i<v1.size();i++)
        cout <<v1[i]<<" ";
    cout <<"\n";
    return 0;
}
