//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int n,m,ex,ey,sx,sy,vis[1000][1000]={0};
char arr[1000][1000];
int in(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return 0;
    if(arr[x][y]=='.')
        return 1;
    return 0;
}
int dfs(int x,int y)
{
    if(x==ex&&y==ey)
        return 1;
    if(vis[x][y]==1)
        return 0;
    vis[x][y]=1;
    if(x>0&&arr[x-1][y]=='.'&&dfs(x-1,y))
        return 1;
    if(y>0&&arr[x][y-1]=='.'&&dfs(x,y-1))
        return 1;
    if(x<(n-1)&&arr[x+1][y]=='.'&&dfs(x+1,y))
        return 1;
    if(y<(m-1)&&arr[x][y+1]=='.'&&dfs(x,y+1))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int i,j,counter=0;
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>arr[i][j];
            vis[i][j]=0;
        }
    }
    cin >>sx>>sy;
    cin >>ex>>ey;
    sx--,sy--,ex--,ey--;
    if(sx==ex&&sy==ey)
    {
        if(in(sx,sy-1)||in(sx-1,sy)||in(sx+1,sy)||in(sx,sy+1))
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    else
    {
        arr[sx][sy]='.';
        int flag=1;
        if(arr[ex][ey]=='.')
            flag=0;
        arr[ex][ey]='.';
        if(dfs(sx,sy)==1)
        {
            if(ex>0&&arr[ex-1][ey]=='.')
                counter++;
            if(ey>0&&arr[ex][ey-1]=='.')
                counter++;
            if(ex<(n-1)&&arr[ex+1][ey]=='.')
                    counter++;
            if(ey<(m-1)&&arr[ex][ey+1]=='.')
                counter++;
            if(flag==0&&counter>1)
                cout <<"YES\n";
            else if(flag==1&&counter>0)
                cout <<"YES\n";
            else
                cout <<"NO\n";
        }
        else
            cout <<"NO\n";
    }
    return 0;
}
