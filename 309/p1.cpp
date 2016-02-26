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
    string str,str1,str2;
    int i,j,k,m,l;
    cin >>str;
    set <string> s;
    l=str.length();
    for(i=0;i<l;i++)
    {
        str1="";
        for(j=0;j<i;j++)
            str1=str1+str[j];
        for(k=0;k<26;k++)
        {
            str2=str1;
            str2=str2+(char)('a'+k);
            for(m=i;m<l;m++)
            {
                str2=str2+str[m];
            }
                s.insert(str2);
        }
    }
    for(i=0;i<26;i++){
        str1=str+(char)('a'+i);
        s.insert(str1);
    }
    cout <<25*l+26<<"\n";
    cout <<s.size()<<"\n";
    return 0;
}
