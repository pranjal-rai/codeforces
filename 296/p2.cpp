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
    long long int n,i,flag=0,q[26]={0},fre[26]={0},inversion=0,j;
    vector <long long int> vec;
    cin >>n;
    int freq[26][26]={0},index[26][26]={0};
    string s,t;
    cin >>s>>t;
    for(i=0;i<n;i++){
        if(s[i]!=t[i])
        {
            freq[s[i]-'a'][t[i]-'a']++;
            index[s[i]-'a'][t[i]-'a']=i+1;
            inversion++;
            vec.push_back(i);
            fre[s[i]-'a']=1;
            q[s[i]-'a']=i+1;
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(freq[i][j]>0&&freq[j][i]>0)
            {
                flag=1;
                cout <<inversion-2<<"\n";
                cout <<index[i][j]<<" "<<index[j][i]<<"\n";
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==0)
    {
        for(i=0;i<inversion;i++)
        {
            if(fre[t[vec[i]]-'a']==1)
            {
                cout <<inversion-1<<"\n";
                cout <<vec[i]+1<<" "<<q[t[vec[i]]-'a']<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout <<inversion<<"\n";
            cout <<"-1 -1\n";
        }
    }




    return 0;
}

