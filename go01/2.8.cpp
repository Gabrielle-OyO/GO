/*
 * 习题2.8 输出全排列【递归】
 */

#include<stdio.h>
#include<string.h>
#include<math.h>
int num[]={1,2,3,4,5,6,7,8,9};
int n,a[10],t[10];
void dfs(int m);
int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}
void dfs(int m)
{
    if(n==m)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",a[j]);
        }
        puts("");
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(t[i]==0)
            {
                a[m]=num[i];
                t[i]=1;
                dfs(m+1);
                t[i]=0;
            }
        }
    }
    return;
}