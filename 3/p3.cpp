//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
char arr[4][4];
int check(char c)
{
    int flag=0;
    if(arr[0][0]==c&&arr[0][1]==c&&arr[0][2]==c)
        flag++;
    if(arr[1][0]==c&&arr[1][1]==c&&arr[1][2]==c)
        flag++;
    if(arr[2][0]==c&&arr[2][1]==c&&arr[2][2]==c)
        flag++;
    if(arr[0][0]==c&&arr[1][0]==c&&arr[2][0]==c)
        flag++;
    if(arr[0][1]==c&&arr[1][1]==c&&arr[2][1]==c)
        flag++;
    if(arr[0][2]==c&&arr[1][2]==c&&arr[2][2]==c)
        flag++;
    if(arr[0][0]==c&&arr[1][1]==c&&arr[2][2]==c)
        flag++;
    if(arr[0][2]==c&&arr[1][1]==c&&arr[2][0]==c)
        flag++;
    if(flag>=1)
    return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    char c;
    int i,j,x=0,y=0,z=0,flag1,flag2;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >>arr[i][j];
            c=arr[i][j];
            if(c=='.')z++;
            if(c=='X')x++;
            if(c=='0')y++;
        }
    }
        flag1=check('X');
        flag2=check('0');
    if(x>(y+1)||y>x||flag1>1||flag2>1||(flag1==1&&flag2==1))
        cout <<"illegal\n";
    else
    {
        if(flag1==0&&flag2==0&&z==0)
            cout <<"draw\n";
        else if(flag1==1){
            if(x==(y+1))
            cout <<"the first player won\n";
            else
                cout <<"illegal\n";
        }
        else if(flag2==1){
            if(x==y)
            cout <<"the second player won\n";
            else
                cout <<"illegal\n";
        }
        else{
            if(x==y)
                cout <<"first\n";
            else
                cout <<"second\n";
        }
    }
    return 0;
}

