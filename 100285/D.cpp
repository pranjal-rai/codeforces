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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str;
    getline(cin,str);    
    int l=str.length(),idx;
    int i,f=0;
    for(i=0;i<l;i++)
    {
        if(str[i]==',')
        {
            f=1;
            idx=i;
        }
    }
    if(!f)
    {
        string str2="",str1="";
        f=0;
        for(i=0;i<l;i++)
        {
            if(str[i]=='{')
                f=1;
            else if(str[i]=='}')
            {
                f=0;
                break;
            }
            else if(f)
            {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
                str1+=str[i];
            }
        }
        str2+=str1+' ';
        str1="";
        for(i=0;i<l;i++)
        {
            if(str[i]=='(')
                f=1;
            else if(str[i]==')')
            {
                f=0;
                break;
            }
            else if(f)
            {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
                str1+=str[i];
            }
        }
        str2+=str1+' ';
        str1="";
        for(i=0;i<l;i++)
        {
            if(str[i]=='[')
                f=1;
            else if(str[i]==']')
            {
                f=0;
                break;
            }
            else if(f)
            {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
                str1+=str[i];
            }
        }
        str2+=str1;
        if(str2[0]>='a'&&str2[0]<='z')
            str2[0]-=32;
        cout <<str2<<"\n";
        return 0;
    }
    string str2="",str1="";
    f=0;
    for(i=0;i<idx;i++)
    {
        if(str[i]=='{')
            f=1;
        else if(str[i]=='}')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1+' ';
    str1="";
    for(i=0;i<idx;i++)
    {
        if(str[i]=='(')
            f=1;
        else if(str[i]==')')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1+' ';
    str1="";
    for(i=0;i<idx;i++)
    {
        if(str[i]=='[')
            f=1;
        else if(str[i]==']')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1;
    if(str2[0]>='a'&&str2[0]<='z')
        str2[0]-=32;
    cout <<str2;
    while(str[idx]!='('&&str[idx]!='{'&&str[idx]!='[')
    {
        cout <<str[idx];
        idx++;
    }
    str2="",str1="";
    f=0;
    for(i=idx;i<l;i++)
    {
        if(str[i]=='{')
            f=1;
        else if(str[i]=='}')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1+' ';
    str1="";
    for(i=idx;i<l;i++)
    {
        if(str[i]=='(')
            f=1;
        else if(str[i]==')')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1+' ';
    str1="";
    for(i=idx;i<l;i++)
    {
        if(str[i]=='[')
            f=1;
        else if(str[i]==']')
        {
            f=0;
            break;
        }
        else if(f)
        {
                if(str[i]>='A'&&str[i]<='Z')
                    str[i]+=32;
            str1+=str[i];
        }
    }
    str2+=str1;
    cout <<str2<<"\n";
    return 0;
}
