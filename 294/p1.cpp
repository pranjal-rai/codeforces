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
    int i,j,count1=0,count2=0;
    char arr[9][9],c;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            cin >>arr[i][j];
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            c=arr[i][j];
            if(c=='Q')
                count1+=9;
            if(c=='R')
                count1+=5;
            if(c=='B')
                count1+=3;
            if(c=='N')
                count1+=3;
            if(c=='P')
                count1+=1;
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            c=arr[i][j];
            if(c=='q')
                count2+=9;
            if(c=='r')
                count2+=5;
            if(c=='b')
                count2+=3;
            if(c=='n')
                count2+=3;
            if(c=='p')
                count2+=1;
        }
    }
    if(count1==count2)
        cout <<"Draw\n";
    else
    if(count1>count2)
        cout <<"White\n";
    else
        cout <<"Black\n";
    return 0;
}

