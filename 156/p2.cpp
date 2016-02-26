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
    string str;
    cin >>str;
    int l=str.length(),count1=0,count2=0,flag=0,i,index1;
    for(i=0;i<l;i++)
    {
        if(flag==0&&str[i]=='y')
        {
            index1=i;
            flag=1;
        }
        if(flag==1&&str[i]=='x')
        {
            swap(str[index1],str[i]);
            index1+=1;
        }
    }
//    cout <<str<<"\n";
    for(i=0;i<l;i++)
    {
        if(str[i]=='x')
            count1++;
        if(str[i]=='y')
            count2++;
    }
    for(i=0;i<(count1-count2);i++)
        cout <<"x";
    for(i=0;i<(count2-count1);i++)
        cout <<"y";
    cout <<"\n";
    return 0;
}

