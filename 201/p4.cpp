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

void computeLPSArray(string pat,LL M,LL *lps)
{
    LL len = 0,i;
    lps[0] = 0; 
    i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

LL KMPSearch(string pat,string txt)
{
    LL M =pat.length();
    LL N =txt.length();
    LL *lps = (LL *)malloc(sizeof(LL)*M);
    LL j  = 0,flag=0;
    computeLPSArray(pat, M, lps);
    LL i = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            flag=1;
            j = lps[j-1];
            break;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return flag;
}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s1,s2,virus;
    LL l1,l2,i,j,ans=0;
    cin >>s1>>s2>>virus;
    l1=s1.length();
    l2=s2.length();
    for(i=l1;i>0;i--)
    {
        for(j=0;j+i<=l1;j++)
        {
            if(KMPSearch(s1.substr(j,i),s2)==1&&KMPSearch(virus,s1.substr(j,i))==0)
            {
                ans=i;
                break;
            }
        }
        if(ans!=0)
            break;
    }
    cout <<ans<<"\n";
    return 0;
}
