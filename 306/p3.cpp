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
    string str;
   // int freq1[20]={0},arr[3],l,i,freq[20]={0},j,x,counter=0,flag=0;
    int x,i,j,k,l,freq[20]={0};
    cin >>str;
    l=str.length();
    for(i=0;i<l;i++)
    {
        freq[str[i]-'0']++;
    }
    if(freq[0]!=0)
    {
        cout <<"YES\n0\n";
        return 0;
    }
    /*for(i=1;i<10;i++)
    {
        if(freq[i]>=8)
        {
                cout <<"YES\n";
                for(j=0;j<8;j++)
                    cout <<i;
                cout <<"\n";
                return 0;
        }
    }*/
    /*for(i=1;(i*8)<1000;i++)
    {
        x=i*8;
        counter=3;
        for(j=0;j<10;j++)
            freq1[j]=0;
        while(counter!=0)
        {
            arr[counter-1]=x%10;
            freq1[x%10]++;
            x=x/10;
            counter--;
        }
        if(arr[0]==0&&arr[1]==0)
            freq1[0]=freq1[0]-2;
        if(arr[0]==0&&arr[1]!=0)
            freq1[0]--;
        flag=1;
        for(j=0;j<10;j++)
        {
            if(freq[j]<freq1[j])
            {  
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout <<"YES"<<"\n"<<i*8<<"\n";
            return 0;
        }
    }*/
    /*if(l==1)
    {
        x=(str[0]-'0');
        if(x%8==0){
                    cout <<"YES\n"<<x<<"\n";
                    return 0;
                }
    }
    if(l==2)
    {
        x=(str[1]-'0')+(str[0]-'0')*10;
        if(x%8==0){
                    cout <<"YES\n"<<x<<"\n";
                    return 0;
                }
    }*/
    for(i=0;i<l;i++)
    {
                x=(str[i]-'0');
                if(x%8==0){
                    cout <<"YES\n"<<x<<"\n";
                    return 0;
                }
    }
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
                x=(str[i]-'0')*10+(str[j]-'0')*1;
                if(x%8==0){
                    cout <<"YES\n"<<x<<"\n";
                    return 0;
                }
        }
    }
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            for(k=j+1;k<l;k++)
            {
                x=(str[i]-'0')*100+(str[j]-'0')*10+(str[k]-'0');
                if(x%8==0){
                    cout <<"YES\n"<<x<<"\n";
                    return 0;
                }
            }
        }
    }
        cout <<"NO\n";
    return 0;
}
