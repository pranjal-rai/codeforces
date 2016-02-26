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
    long long int ans,a,b,n,l,t,m,p,x,y,z,ans1,ans2;
    cin >>a>>b>>n;
    while(n--)
    {
        cin >>l>>t>>m;
/*        m=1;
        p=2*(a+(l-1)*b)-l*b;
        x=b;
        y=p+b-b*l-2*t*m;
        z=-2*t*m-p*l+p+2*l*t*m;
        ans1=(-y+(long long int)(sqrt(y*y-4*x*z)))/(2*b);
        ans2=(-y-(long long int)(sqrt(y*y-4*x*z)))/(2*b);
        cout <<ans1<< " "<<ans2<<"\n";*/
        ans=(t-(a+(l-1)*b))/b+l;
        if(ans<l)
            cout <<"-1\n";
        else{
        if((ans-l+1)>m)
            ans=l+m-1;
                cout <<ans<<"\n";
        }
    }
    return 0;
}

