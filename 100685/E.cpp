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
    int index,n,l1,l2,l3,i,flag=0,flag1=0;
    double var;
    vector <double> ans,v1,v2,v3;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        if(var>=1.00)
        {
            flag=1;
            if(var==1.00)
            {
                index1=i+1;
                flag1=1;
                continue;
            }
            ans.PB(i+1);
        }
        else if(var<=-1.00)
        {
            if(var==-1.00)
                counter++;
            else
                v1.PB(MP(var,i+1));  
        }
        else if(var<0.00)
            v2.PB(MP(var,i+1));
        else
            v3.PB(MP(var,i+1));
    }
    l=ans.size();
    l1=v1.size();
    l2=v2.size();
    l3=v3.size();
    sort(all(v1));
    sort(all(v2));
    sort(all(v3));
    if(flag==1)
    {
        x=0;
        while(x<(l1-1))
        {





            


    return 0;
}
