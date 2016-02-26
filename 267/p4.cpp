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
string convert(string str)
{
    int l=str.length();
    for(int i=0;i<l;i++)
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=(char)(str[i]+32);
    return str;
}

map<string,int> mp1;
vector <int> G[200010];
set <pair<int,PII> > s;
set <pair<int,PII> >::iterator it;
int dp[200010][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int m,i,n,j;
    string str,str1,str2;
    vector <string> v;
    cin >>m;
    for(i=0;i<m;i++)
    {
        cin>>str;
        str=convert(str);
        v.PB(str);
    }
    cin >>n;
    int l,z,len1,len2,count1,count2,x,y,counter=1;
    LL len;
    for(j=0;j<n;j++)
    {
        count1=0,count2=0;
        cin >>str1>>str2;
        str1=convert(str1),str2=convert(str2);
        len1=str1.length(),len2=str2.length();
        z=mp1[str1];
        if(z==0)
        {
            for(i=0;i<len1;i++)
                if(str1[i]=='r')
                    count1++;
            mp1[str1]=counter;
            x=counter;
            dp[counter][0]=count1;
            dp[counter][1]=len1;
            counter++;
            s.insert(MP(count1,MP(len1,x)));
        }
        else x=z;
        z=mp1[str2];
        if(z==0)
        {
            for(i=0;i<len2;i++)
                if(str2[i]=='r')
                    count2++;
            mp1[str2]=counter;
            y=counter;
            dp[counter][0]=count2;
            dp[counter][1]=len2;
            counter++;
            s.insert(MP(count2,MP(len2,y)));
        }
        else y=z;
        G[y].PB(x); //reverse graph
    }
    while(!(s.empty()))
    {
        it=s.begin();
        x=(it->S).S;
        s.erase(it);
        len2=G[x].size();
        for(i=0;i<len2;i++)
        {
            if(dp[G[x][i]][0]>=dp[x][0])
            {
                if(dp[G[x][i]][0]==dp[x][0]&&dp[G[x][i]][1]<=dp[x][1])
                    continue;
                s.erase(MP(dp[G[x][i]][0],MP(dp[G[x][i]][1],G[x][i])));
                dp[G[x][i]][0]=dp[x][0];
                dp[G[x][i]][1]=dp[x][1];
                s.insert(MP(dp[G[x][i]][0],MP(dp[G[x][i]][1],G[x][i])));
            }
        }
    }
    counter=0,len=0;
    for(i=0;i<m;i++)
    {
        z=mp1[v[i]];
        if(z==0)
        {
            count1=0;
            l=v[i].length();
            len+=l;
            for(j=0;j<l;j++)
                if(v[i][j]=='r')
                    count1++;
            counter+=count1;
        }
        else
        {
            counter+=dp[z][0];
            len=len+dp[z][1];
        }
    }
    cout <<counter<<" "<<len<<"\n";
    return 0;
}
