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
int n,i,j,k,flagx,l1,l2,flag[150]={0},counter=0,ans=0;
string str,str1;
vector<string> vec;
vector <vector<int> > v(150);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    str1="";
    for(i=0;i<n;i++)
        str1=str1+'1';
    for(i=0;i<n;i++)
    {
        cin >>str;
        if(str==str1)
            ans++;
        vec.PB(str);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(vec[i][j]=='0')
            v[i].PB(j);
        }
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            counter=0;
                l1=v[i].size();
            for(j=i;j<n;j++)
            {
                l2=v[j].size();
                if(l1==l2)
                {
                    flagx=1;
                    for(k=0;k<l1;k++)
                    {
                        if(v[i][k]!=v[j][k])
                        {
                            flagx=0;
                            break;
                        }
                    }
                if(flagx==1){
                    counter++;
                    flag[j]=1;
                }
                }
            }
            flag[i]=1;
            ans=max(ans,counter);
        }
    }
    cout <<ans<<"\n";
    return 0;
}
