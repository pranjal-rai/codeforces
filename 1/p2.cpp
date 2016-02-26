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
    double e=0.00000000001;
    long long int n,j,l,i,index,x,sum,type;
    string str;
    vector <long long int> vec;
    cin >>n;
    while(n--)
    {
        cin >>str;
        sum=0;
        l=str.length();
        type=2;
        i=0;
        while(str[i]>='A'&&str[i]<='Z')
            i++;
        index=i-1;
        for(;i<l;i++){
            if(str[i]>='A'&&str[i]<='Z')
            {
                type=1;
                break;
            }
        }
        if(type==1){
            while(str[i]!='C')
                i++;
        index=i;
        i++;
        for(;i<l;i++)
                sum=sum*10+(str[i]-'0');
        sum=sum-1,i=1;
        cout <<sum<<"\n";
        while((sum-(long long int)(pow(26,i)+e))>=0)
        {
            cout <<"c";
            sum=sum-(long long int)(pow(26,i)+e);
            i++;
        }
        cout <<sum<<"\n";
        j=0;
        while(j<i)
        {
            vec.push_back(sum%26);
            sum=sum/26;
            j++;
        }
        reverse(vec.begin(),vec.end());
        x=vec.size();
        for(i=0;i<x;i++)
        {
                cout <<(char)(vec[i]+65);
        }
        for(i=1;i<index;i++)
            cout <<str[i];
        cout <<"\n";
        vec.clear();
        }
        else{
            cout <<"R";
            for(i=index+1;i<l;i++)
                cout <<str[i];
            sum=0,j=0;
            cout <<"C";
            while(j<index)
                sum=sum+((long long int)(pow(26,j+1)+e)),j++;
            for(j=index;j>=0;j--)
            {
                sum=sum+((long long int)(pow(26,(index-j))+e))*(str[j]-'A');
            }
            cout <<sum+1<<"\n";
        }
            
    }
    return 0;
}

