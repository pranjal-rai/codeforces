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

int team[1000];
int max1,n,i,j,var,idx;
map <int,PII> m;
map <int,PII> ::iterator it;
pair <int,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    for(i=1;i<=2*n;i++)
        team[i]=-1;
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            cin >>var;
            m[var]=MP(i,j);
        }
    }
    it=(--(m.end()));
    while(1)
    {
        mp=it->S;
        if(team[mp.S]==-1&&team[mp.F]==-1)
        {
            team[mp.S]=mp.F;
            team[mp.F]=mp.S;
        }
        if(it==m.begin())
            break;
        it--;
    }


        
    /*for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=2*n;j++)
            cout <<score[i][j]<<" ";
        cout <<"\n";
    }
    for(i=1;i<=2*n;i++)
    {
        max1=-1,idx=-1;
        for(j=1;j<=2*n;j++)
        {
            if(score[i][j]>max1)
            {
                max1=score[i][j];
                idx=j;
            }
        }
        cout <<idx<<" "<<max1<<"\n";
        team[i]=idx;
    }
    cout <<"\n";*/
    for(i=1;i<=2*n;i++)
        cout <<team[i]<<" ";
    cout <<"\n";   
    return 0;
}
