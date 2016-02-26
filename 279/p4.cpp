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
    long long int x,x1,y1,x2,y2,p1,p2,count1=0,count2=0,count3=0,count4=0,ans=0;
    cin >>x1>>y1>>x2>>y2;
    p1=x1*y1;
    p2=x2*y2;
    while(p1%2==0){
        count1++;
        p1=p1/2;}
    while(p1%3==0){count2++;
        p1=p1/3;}
    while(p2%2==0){count3++;
        p2=p2/2;}
    while(p2%3==0){count4++;
        p2=p2/3;}
    if(p1!=p2)
    {
        cout <<"-1\n";
        return 0;
    }
    if(count2<count4)
    {
        x=count4-count2;
        while(x!=0&&x2%3==0)
        {
            x2=x2/3;
            x2=x2*2;
            x--;
        }
        while(x!=0&&y2%3==0)
        {
            y2=y2/3;
            y2=y2*2;
            x--;
        }
        count3+=(count4-count2);
        ans+=(count4-count2);
        count4=count2;
    }
    else if(count2>count4)
    {
        x=count2-count4;
        while(x!=0&&x1%3==0)
        {
            x1=x1/3;
            x1=x1*2;
            x--;
        }
        while(x!=0&&y1%3==0)
        {
            y1=y1/3;
            y1=y1*2;
            x--;
        }
        count1+=(count2-count4);
        ans+=(count2-count4);
        count2=count4;
    }
    if(count1<count3)
    {
        x=count3-count1;
        while(x!=0&&x2%2==0)
        {
            x2=x2/2;
            x--;
        }
        while(x!=0&&y2%2==0)
        {
            y2=y2/2;
            x--;
        }
        ans+=(count3-count1);
        count3=count1;
    }
    else if(count1>count3)
    {
        x=count1-count3;
        while(x!=0&&x1%2==0)
        {
            x1=x1/2;
            x--;
        }
        while(x!=0&&y1%2==0)
        {
            y1=y1/2;
            x--;
        }
        ans+=(count1-count3);
        count1=count3;
    }
    cout <<ans<<"\n"<<x1<<" "<<y1<<"\n"<<x2<<" "<<y2<<"\n";
    return 0;
}
