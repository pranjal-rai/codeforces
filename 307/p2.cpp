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
    string a,b,c;
    long long int la,lb,lc,i,freqa[26]={0},freqb[26]={0},freqc[26]={0},mini1,mini2,j,p,q,maxi;
    cin >>a>>b>>c;
    la=a.length();
    lb=b.length();
    lc=c.length();
    for(i=0;i<la;i++)
        freqa[a[i]-'a']++;
    for(i=0;i<lb;i++)
        freqb[b[i]-'a']++;
    for(i=0;i<lc;i++)
        freqc[c[i]-'a']++;
    mini1=INT_MAX;
    for(i=0;i<26;i++)
    {
        if(freqb[i]!=0)
            mini1=min(mini1,freqa[i]/freqb[i]);
    }
    maxi=INT_MIN;
    for(i=0;i<=mini1;i++)
    {
        mini2=INT_MAX;
        for(j=0;j<26;j++)
        {
            if(freqc[j]!=0)
            mini2=min(mini2,(freqa[j]-i*freqb[j])/freqc[j]); 
        }
        if(mini2+i>maxi){
            p=i;
            q=mini2;
            maxi=mini2+i;}
    }
    for(i=0;i<p;i++)
        cout <<b;
    for(i=0;i<q;i++)
        cout <<c;
    for(i=0;i<26;i++)
    {
        freqa[i]-=(p*freqb[i]+q*freqc[i]);
        for(j=0;j<freqa[i];j++)
            cout <<(char)('a'+i);
    }
    cout <<"\n";
    return 0;
}
