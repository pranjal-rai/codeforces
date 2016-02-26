#include <bits/stdc++.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,a[n+1],c,d;
    c=-1;
    d=100000;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>c)
        {
            c=a[i];
        }
        if(a[i]<d)
        {
            d=a[i];
        }
    }
    printf("the largest number is %d\n",c);
    printf("the smallest numbe is %d\n",d);
    return 0;
}
