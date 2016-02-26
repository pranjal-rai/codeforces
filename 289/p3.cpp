//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int cal(char *str,int s,int sum,int sumi)
{
        int p,i;
    if(sum>sumi)
    {
        p=sum-sumi;
        i=400;
        while(p!=0&&i>=s)
        {
            if(str[i]!='9')
            {
                if(p>=('9'-str[i]))
                {
                    p=p-('9'-str[i]);
                    str[i]='9';
                }
                else
                {
                    str[i]=(str[i]-'0')+(p+'0');
                    p=0;
                }
            }
            i--;
        }
        if(p==0)
            return s;
        else
        {
            p=sum;
            i=400;
            while(p>=9)
            {
                str[i]='9';
                i--;
                p=p-9;
            }
            if(p!=0)
            {
                str[i]=p+'0';
                p=0;
            }
        }
        return i;
    }
    else if(sum<sumi)
    {
            p=sum;
            i=400;
            str[s-1]='1';
            p=p-1;
            while(i>=s)
            {
                if(p>=9){
                str[i]='9';
                p=p-9;
                }
                else{
                    str[i]=p+'0';
                    p=0;
                }
                i--;
            }
            return s-1;
    }
    else if(sum==sumi)
    {
        int j,flag=0,x=400;
        for(j=400;j>=s;j--)
        {
            if(str[j]!='0')
                break;
        }
        x=j;
        str[j]=str[j]-1;
        for(int k=j-1;k>=s;k--)
        {
            if(str[k]!='9')
            {
                flag=1;
                str[k]=str[k]+1;
                break;
            }
            else{
                str[k]='0';
            }
        }
        if(flag==1)
            return s;
        else
        {
            p=sum;
            i=400;
            str[s-1]='1';
            p=p-1;
            while(i>=s)
            {
                if(p>=9){
                str[i]='9';
                p=p-9;
                }
                else{
                    str[i]=p+'0';
                    p=0;
                }
                i--;
            }
            return s-1;
        }


    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,var,p,l=400;
   vector <int> vec;
    cin >>n;
        vec.push_back(0);
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    char str[500];
    p=vec[1];
    l=400;
    while(p!=0)
    {
        if(p>9)
        {
            p=p-9;
            str[l]='9';
            l--;
        }
        else
        {
            str[l]=p+'0';
            l--;
            p=0;
        }
    }
    for(i=l+1;i<=400;i++)
        cout <<str[i];
    cout <<"\n";
    int j=l+1;
    for(i=2;i<=n;i++)
    {
        j=cal(str,j,vec[i],vec[i-1]);//calculate number greater than x and sum of digit vec[i]
        for(int k=j;k<=400;k++)
        cout <<str[k];
        cout <<"\n";
    }
    return 0;
}

