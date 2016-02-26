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
    long long int n,m,k,j,scr,i,var,counter=0,tmp,tmp1,tmp2,tmpx1,tmpx2;
    long long int screennumber[100010]={0},pos[100010],position[100010]={0};
    cin >>n>>m>>k;
    j=0,scr=0;
    for(i=0;i<n;i++)
    {
        cin >>var;
        screennumber[var]=scr;
        pos[var]=j;
        position[i]=var;
        if(j==(k-1)){
            j=0;
            scr++;
        }
        else
            j++;
    }
    for(i=0;i<m;i++)
    {
        cin >>var;
        counter+=(screennumber[var]+1);
        tmp=screennumber[var]*k+pos[var];
        if(tmp==0)
            continue;
        else
        {
            tmp1=screennumber[var];
            tmp2=pos[var];
            tmpx1=screennumber[position[tmp-1]];
            tmpx2=pos[position[tmp-1]];
            screennumber[var]=tmpx1;
            pos[var]=tmpx2;
            screennumber[position[tmp-1]]=tmp1;
            pos[position[tmp-1]]=tmp2;
            swap(position[tmp],position[tmp-1]);
        }
    }
           cout <<counter<<"\n"; 

            

    return 0;
}

