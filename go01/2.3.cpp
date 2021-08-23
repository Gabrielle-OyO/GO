/*
 * 习题2.3 数列求和-加强版
 */

#include<stdio.h>
#define N 100001
int s[N]={0};
int main()
{
    int a,n,i,j,index,t;
    scanf("%d %d",&a,&n);
    index=n;
    if(n==0)
        printf("0");
    else
    {
        for(i=0,j=n;i<n;i++,j--)
        {
            t=s[i]+j*a;
            s[i]=t%10;
            if(t/10)
                s[i+1]=t/10;
        }
    }
    if(s[n]>0)
        index=n+1;
    for(i=index-1;i>=0;i--)
        printf("%d",s[i]);
    return 0;
}