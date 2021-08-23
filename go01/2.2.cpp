/*
 * 习题2.2 数组循环左移
 */

#include<stdio.h>
int main()
{
    int m,n;
    int arr[100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<m;i++)
    {
        int temp=arr[0];
        for(int j=1;j<n;j++)
        {
            arr[j-1]=arr[j];
        }
        arr[n-1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%d",arr[i]);
        }
        else
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}

