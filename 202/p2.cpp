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
int dp[9][1000010]={0},tmp[9]={0};
vector <int> vec;
int i,var,j,k,sum1,ans,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>v;
    for(i=0;i<9;i++)
    {
        cin >>var;
        vec.PB(var);
    }
    ans=0;
    for(i=1;i<=v;i++)
    {
        j=0;
        while(j<9)
        {
            sum1=0;
            if(vec[j]<=i)
            {
                for(k=0;k<9;k++)
                {
                    tmp[k]=dp[k][i-vec[j]];
                    sum1+=tmp[k];
                }
                tmp[j]++;
                sum1+=1;
                if(sum1>ans)
                {
                    ans=sum1;
                    for(k=0;k<9;k++)
                        dp[k][i]=tmp[k];
                }
                else if(sum1==ans)
                {
                    int flag=1;
                    for(k=8;k>=0;k--)
                    {
                        if(dp[k][i]>tmp[k])
                            break;
                        else if(dp[k][i]<tmp[k])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        ans=sum1;
                        for(k=0;k<9;k++)
                            dp[k][i]=tmp[k];
                    }
                }
            }
            j++;
        }
      /*  for(k=0;k<9;k++)
        {
            cout <<dp[k][i]<<" ";
        }
        cout<<"\n";*/
    }
    int flag=0;
    for(k=8;k>=0;k--)
    {
        while(dp[k][v]!=0)
        {
            flag=1;
            cout <<k+1;
            dp[k][v]--;
        }
    }
    if(flag)
    cout <<"\n";
    else
        cout <<-1<<"\n";
    return 0;
}
