//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int dp[9][9]={0},vis[9][9]={0};
int val(int x,int y)
{
    if(x>=1&&x<=8&&y>=1&&y<=8)
        return 1;
    return 0;
}
void cal(int x,int y,int v)
{
    if(val(x,y)==0)
        return;
    if(v==0)
        return;
    if(val(x-1,y-1)&&dp[x-1][y-1]==(v-1))
    {
        cout <<"LU\n";
        cal(x-1,y-1,v-1);
        return;
    }
    if(val(x-1,y)&&dp[x-1][y]==(v-1))
    {
        cout <<"U\n";
        cal(x-1,y,v-1);
        return;
    }
    if(val(x-1,y+1)&&dp[x-1][y+1]==(v-1))
    {
        cout <<"RU\n";
        cal(x-1,y+1,v-1);
        return;
    }
    if(val(x,y-1)&&dp[x][y-1]==(v-1))
    {
        cout <<"L\n";
        cal(x,y-1,v-1);
        return;
    }
    if(val(x,y+1)&&dp[x][y+1]==(v-1))
    {
        cout <<"R\n";
        cal(x,y+1,v-1);
        return;
    }
    if(val(x+1,y-1)&&dp[x+1][y-1]==(v-1))
    {
        cout <<"LD\n";
        cal(x+1,y-1,v-1);
        return;
    }
    if(val(x+1,y)&&dp[x+1][y]==(v-1))
    {
        cout <<"D\n";
        cal(x+1,y,v-1);
        return;
    }
    if(val(x+1,y+1)&&dp[x+1][y+1]==(v-1))
    {
        cout <<"RD\n";
        cal(x+1,y+1,v-1);
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str1,str2;
    cin >>str1>>str2;
    queue <pair <int,int> > myqueue;
    pair <int,int> mypair;
    int w,x,y,z,i,j;
    x=(str1[0]-'a')+1;
    w=9-(str1[1]-'0');
    z=(str2[0]-'a')+1;
    y=9-(str2[1]-'0');
    mypair.first=y;
    mypair.second=z;
    myqueue.push(mypair);
    vis[y][z]=1;
    dp[y][z]=0;
    while(myqueue.empty()==0)
    {
        mypair=myqueue.front();
        i=mypair.first;
        j=mypair.second;
        if(val(i-1,j-1)&&vis[i-1][j-1]==0)
        {
            mypair.first=i-1;
            mypair.second=j-1;
            myqueue.push(mypair);
            vis[i-1][j-1]=1;
            dp[i-1][j-1]=dp[i][j]+1;
        }
        if(val(i-1,j)&&vis[i-1][j]==0)
        {
            mypair.first=i-1;
            mypair.second=j;
            myqueue.push(mypair);
            vis[i-1][j]=1;
            dp[i-1][j]=dp[i][j]+1;
        }
        if(val(i,j-1)&&vis[i][j-1]==0)
        {
            mypair.first=i;
            mypair.second=j-1;
            myqueue.push(mypair);
            vis[i][j-1]=1;
            dp[i][j-1]=dp[i][j]+1;
        }
        if(val(i+1,j+1)&&vis[i+1][j+1]==0)
        {
            mypair.first=i+1;
            mypair.second=j+1;
            myqueue.push(mypair);
            vis[i+1][j+1]=1;
            dp[i+1][j+1]=dp[i][j]+1;
        }
        if(val(i+1,j)&&vis[i+1][j]==0)
        {
            mypair.first=i+1;
            mypair.second=j;
            myqueue.push(mypair);
            vis[i+1][j]=1;
            dp[i+1][j]=dp[i][j]+1;
        }
        if(val(i,j+1)&&vis[i][j+1]==0)
        {
            mypair.first=i;
            mypair.second=j+1;
            myqueue.push(mypair);
            vis[i][j+1]=1;
            dp[i][j+1]=dp[i][j]+1;
        }
        if(val(i+1,j-1)&&vis[i+1][j-1]==0)
        {
            mypair.first=i+1;
            mypair.second=j-1;
            myqueue.push(mypair);
            vis[i+1][j-1]=1;
            dp[i+1][j-1]=dp[i][j]+1;
        }
        if(val(i-1,j+1)&&vis[i-1][j+1]==0)
        {
            mypair.first=i-1;
            mypair.second=j+1;
            myqueue.push(mypair);
            vis[i-1][j+1]=1;
            dp[i-1][j+1]=dp[i][j]+1;
        }
        myqueue.pop();
    }
    cout <<dp[w][x]<<"\n";
    cal(w,x,dp[w][x]);
    return 0;
}

