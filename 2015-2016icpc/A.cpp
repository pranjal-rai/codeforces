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
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
string getdomain(string str)
{
    int l=str.length();
    int i=0;
    while(str[i]!='@')
        i++;
    i++;
    string str1="";
    for(;i<l;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str1+=((char)(str[i]+32));
        else 
            str1+=str[i];
    }
    return str1;
}
string getlogin(string str,string str1)
{
    int l=str.length();
    string str2="";
    for(int i=0;str[i]!='@';i++)
    {
        if(str[i]=='.'&&str1=="bmail.com")
            continue;
        if(str[i]=='+'&&str1=="bmail.com")
            break;
        if(str[i]>='A'&&str[i]<='Z')
            str2+=((char)(str[i]+32));
        else 
            str2+=str[i];
    }
    return str2;
}   
map <pair<string,string>,VI> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int counter=0,n,i,j,l;
    VI vis;
    string str,str1,str2;
    vector <string> v;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>str;
        v.PB(str);
        str1=getdomain(str);
        str2=getlogin(str,str1);
        mp[MP(str2,str1)].PB(i);
    }
    VI v1;
    vis.resize(n,0);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            counter++;
            str=v[i];
            str1=getdomain(str);
            str2=getlogin(str,str1);
            v1=mp[MP(str2,str1)];
            l=v1.size();
            for(j=0;j<l;j++)
                vis[v1[j]]=1;
        }
    }   
    cout <<counter<<"\n";
    vis.assign(n,0);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            str=v[i];
            str1=getdomain(str);
            str2=getlogin(str,str1);
            v1=mp[MP(str2,str1)];
            l=v1.size();
            cout <<l;
            for(j=0;j<l;j++)
            {
                vis[v1[j]]=1;
                cout <<" "<<v[v1[j]];
            }
            cout <<"\n";
        }
    }   
    return 0;
}
