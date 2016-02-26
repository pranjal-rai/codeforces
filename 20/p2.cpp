//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    long long int a,b,c;
    double f1,f2;
    cin >>a>>b>>c;
    if(a==0&&b==0&&c==0)
        cout <<-1<<"\n";
    else if(a==0)
    {
        if(b!=0)
            printf("1\n%.7lf\n",(((double)(-c))/b));
        else if(b==0)
            printf("0\n");
    }
    else
    {
        if(b*b==4*a*c)
        {
            printf("1\n%.7lf\n",(-b/((double)(2*a))));
        }
        else
        {
            if(b*b<4*a*c){
                printf("0\n");
                return 0;
            }
            f1=((-b-sqrt((double)(b*b-4*a*c)))/((double)(2*a)));
            f2=((-b+sqrt((double)(b*b-4*a*c)))/((double)(2*a)));
            printf("2\n%.7lf\n",min(f1,f2));
            printf("%.7lf\n",max(f1,f2));
        }
    }
    return 0;
}

