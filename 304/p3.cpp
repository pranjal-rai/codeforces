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
    pair<string,string> mp;
    set<pair<string,string> > s;
    int flag=0,counter=0;
int check(string str1,string str2)
{
    mp=make_pair(str1,str2);
    if(s.find(mp)==s.end())
        return 1;
    flag=1;
    return 0;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k1,k2,i,var,x,y;
    char c;
    string str1="",str2="";
    cin >>n;
    cin >>k1;
    for(i=0;i<k1;i++)
    {
        cin >>var;
        if(var==10)
            c='0';
        else
            c=var+'0';
        str1=str1+c;
    }
    cin >>k2;
    for(i=0;i<k2;i++)
    {
        cin >>var;
        if(var==10)
            c='0';
        else
            c=var+'0';
        str2=str2+c;
    }
    while(check(str1,str2)&&str1.length()!=0&&str2.length()!=0)
    {
        mp=make_pair(str1,str2);
        s.insert(mp);
        if(str1[0]=='0')
            x=10;
        else
            x=str1[0]-'0';
        if(str2[0]=='0')
            y=10;
        else
            y=str2[0]-'0';
        if(x>y)
        {
                str1.erase(0,1);
                str2.erase(0,1);
            if(x==10)
            {
                str1=str1+(char)(y+'0');
                str1=str1+'0';
            }
            else
            {
                str1=str1+(char)(y+'0');
                str1=str1+(char)(x+'0');
            }
        }
        else
        {
                str1.erase(0,1);
                str2.erase(0,1);
            if(y==10)
            {
                str2=str2+(char)(x+'0');
                str2=str2+'0';
            }
            else
            {
                str2=str2+(char)(x+'0');
                str2=str2+(char)(y+'0');
            }
        }
        counter++;
    }
    if(flag==1)
        cout <<"-1\n";
    else
    {
        if(str1.length()>str2.length())
            cout <<counter<<" "<<1<<"\n";
        else
            cout <<counter<<" "<<2<<"\n";
    }
    return 0;
}
