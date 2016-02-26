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
int n,counter=0;
string str;
int check(char a,char b)
{
    if(a<b)
        swap(a,b);
    return min(a-b,('z'-a)+(b-'a')+1);
}

void left(int x,int y)
{
    for(int i=x;i>=y;i--)
    {
        counter++;
        if(str[i]!=str[n-i-1])
        { 
            counter=counter+check(str[i],str[n-i-1]);
            str[i]=str[n-i-1];
        }
    }
}

void right(int k,int e)
{
    for(int i=k;i<=e;i++)
    {
        counter++;
        if(str[i]!=str[n-i-1])
        {
            counter=counter+check(str[i],str[n-i-1]);
            str[i]=str[n-i-1];
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int k,l,flag,i,s,e;
    string str1="";
    cin >>n>>k;
    cin >>str;
    flag=1;
    for(i=0;i<n/2;i++)
        if(str[i]!=str[n-i-1])
            flag=0;
    if(flag==1)
    {
        cout <<0<<"\n";
        return 0;
    }
    if(n%2!=0)
    {
        for(i=0;i<n;i++)
        {
            if(i!=n/2)
                str1=str1+str[i];
        }
        str=str1;
        n=n-1;
        if(k>=n/2)
            k--;
    }
    if(k>n/2)
        k=n-k+1;
    flag=0,s=-1;
    counter=counter+check(str[k-1],str[n-k]);
    str[k-1]=str[n-k];
    for(i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-i-1])
        {
            if(flag==0)
            {
                flag=1;
                s=i;
            }
            e=i;
        }
    }
    if(s==-1)
    {
        cout <<counter<<"\n";
        return 0;
    }
    if(s<(k-1)&&e>(k-1))
    {
        if((e-(k-1))>=((k-1)-s))
        {
            left(k-2,s);
            right(s,e);
        }
        else
        {
            right(k,e);
            left(e-1,s);
        }
    }
    else if(s<(k-1)&&e<(k-1))
    {
        left(k-2,s);
    }
    else if(s>(k-1)&&e>(k-1))
    {
        right(k,e);
    }
    cout <<counter<<"\n";
    return 0;
}
