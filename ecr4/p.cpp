#include <bits/stdc++.h>
using namespace   std;


      
#define mod 1000000007
#define si 100001
#define f first
#define s second
#define rep(i,n) for(i=1;i<=n;i++)
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rep2(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define v2(x) vector< vector <int> > x
#define pi(x) printf("%d ",x)
#define pll(x) printf("%lld ",x)
#define pie(x) printf("%d\n",x)
#define plle(x) printf("%lld\n",x)



int main() {
 
  int n,n1,n2,i,j,c=0;
  bool dp[101]={0};
  dp[0]=1;

  string x;
  cin>>n>>n1>>n2>>x;

  rep(i,n)
    {
     
      if(n1<=i)dp[i]=dp[i-n1];
      if(n2<=i)dp[i]|=dp[i-n2];
    }

  if(!dp[n])
    {
      pie(-1); return 0;
    }

  bool ans[102]={0};
 ans[n]=1;

  j=n;

  while(j>0)
    {
      if(dp[j-n1]&&j-n1>-1)
    {
      ans[j-n1]=1;
      j=j-n1;
      c++;
    }

      else if(dp[j-n2]&&j-n2>-1)
    {
      ans[j-n2]=1;
      j=j-n2;
      c++;
    }
    }
  if(!c)c++;
  pie(c);
  rep0(i,n)
    {
      cout<<x[i];
      if(ans[i+1])cout<<endl;
    }

 
 

}