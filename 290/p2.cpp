//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,i,j;
    cin >>n>>m;
    char arr[51][51];
    int visited[51][51];
  //  vector< vector <vector <pair<int,int> > > > vec;
  //  vector < pair<int,int> > myvec;
   // pair <int,int> mypair;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(visited[i][j]==0)
            {
                mypair.first=i;
                mypair.second=j;
                myqueue.push(mypair);
                while(myqueue.empty()==0)
                {
                    mypair=myqueue.front();
                    x=mypair.first;
                    y=mypair.second;
                    if(arr[x][y]==


   /* for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i>0&&arr[i][j]==arr[i-1][j])
            {
                mypair.first=i-1;
                mypair.second=j;
                myvec.push_back(mypair);
            }
            if(j>0&&arr[i][j]==arr[i][j-1])
            {
                mypair.first=i;
                mypair.second=j-1;
                myvec.push_back(mypair);
            }
            if(j<(m-1)&&arr[i][j]==arr[i][j+1])
            {
                mypair.first=i;
                mypair.second=j+1;
                myvec.push_back(mypair);
            }
            if(i<(n-1)&&arr[i][j]==arr[i+1][j])
            {
                mypair.first=i+1;
                mypair.second=j;
                myvec.push_back(mypair);
            }
        }
        vec[i][j].push_back(myvec);
        myvec.erase(myvec.begin(),myvec.end());
    }*/


    return 0;
}

