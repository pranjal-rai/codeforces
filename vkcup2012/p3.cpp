//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,l,i,x,y;
    string str,str1,path;
    cin >>n;
    path="/";
    while(n--)
    {
        cin >>str;
        if(str=="pwd")
        {
            cout <<path<<"\n";
            continue;
        }
        cin >>str1;
        i=0;
        if(str1[0]=='/')
        {
            i++;
            path='/';
           /* if(path[path.length()-1]!='/')
                path=path+'/';
            continue;*/
        }
        l=str1.length();
        for(;i<l;)
        {
            while(str1[i]!='.'&&i<l)
            {
                path=path+str1[i];
                i++;
            }
            if(i>=l)
                break;
            i=i+3;
            x=path.length(),y=1;
            x=x-2;
            while(path[x]!='/')
                x--,y++;
            path.erase(x+1,y);
            if(path[path.length()-1]!='/')
                path=path+'/';
        }
            if(path[path.length()-1]!='/')
                path=path+'/';
        
    }
    return 0;
}
