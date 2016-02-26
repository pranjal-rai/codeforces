//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
string cal(string str1,int l1,string str2,int l2)
{
    int i,j;
    if(l1>l2)
        return "-1";
    if(l2>l1)
    {
        if(str2[0]=='?')
            str2[0]='1';
        for(i=1;i<l2;i++)
            if(str2[i]=='?')
                str2[i]='0';
        return str2;
    }
    if(l1==l2)
    {
        int p=0;
        for(i=0;i<l2;i++)
        {
            if(str2[i]=='?'){p=1;
                break;}
            if(str2[i]<str1[i])
                return "-1";
            if(str2[i]>str1[i])
            {
                for(int j=i+1;j<l2;j++)
                    if(str2[j]=='?'){
                        str2[j]='0';}
                return str2;
            }
        }
        for(j=i+1;j<l2;j++)
        {
            if(str2[j]=='?'){p=1;
                continue;
            }
            if(str2[j]<str1[j])
            {
                int flag=0,k;
                for(k=j-1;k>=0;k--)
                {
                    if(str2[k]=='?'&&str1[k]!='9')
                    {
                        str2[k]=str1[k]+1;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    return "-1";
                for(int l=0;l<k;l++)
                    if(str2[l]=='?')
                        str2[l]=str1[l];
                for(int l=k+1;l<l2;l++)
                    if(str2[l]=='?')
                        str2[l]='0';
                return str2;
            }
            if(str2[j]>str1[j])
            {
                for(int k=0;k<j;k++)
                    if(str2[k]=='?')
                        str2[k]=str1[k];
                for(int k=j+1;k<l2;k++)
                    if(str2[k]=='?')
                        str2[k]='0';
                return str2;
            }   
        }
        if(p==0)
            if(str2>str1)
                return str2;
            else
                return "-1";
        p=0;
        for(i=l2-1;i>=0;i--)
            if(str2[i]=='?'&&str1[i]!='9'){
                str2[i]=str1[i]+1;
                p=1;
                break;
            }
        if(p==0)
            return "-1";
        for(j=0;j<i;j++)
            if(str2[j]=='?')
                str2[j]=str1[j];
        for(j=i;j<l2;j++)
            if(str2[j]=='?')
                str2[j]='0';
        return str2;
    }   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,l1,l2,flag=1;
    string str1,str;
    vector <string> vec;
    cin >>n;
    cin>>str1;
    l1=str1.length();
    for(i=0;i<l1;i++)
    {
        if(str1[i]=='?')
        {
            if(i!=0)
                str1[i]='0';
            else
                str1[i]='1';
        }
    }
    vec.push_back(str1);
    for(i=1;i<n;i++)
    {
        cin >>str;
        if(flag==1)
        {
            l2=str.length();
            str=cal(str1,l1,str,l2);
            if(str=="-1"){
                flag=0;
                continue;
            }
            vec.push_back(str);
            str1=str;
            l1=l2;
        }
    }
    if(flag==0)
    {
        cout <<"NO\n";
        return 0;
    }
    cout <<"YES\n";
    for(i=0;i<n;i++)
        cout <<vec[i]<<"\n";
    return 0;
}

