//
// Created by 18377 on 2021/8/23.
//习题2.6 递归求简单交错幂级数的部分和

#include<stdio.h>
double fn(double x,int n);
int main()
{
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    printf("%.2f\n",fn(x,n));
    return 0;
}

double fn(double x,int n)
{
    if(n==1)
        return x;
    else
        return x+(-x)*fn(x,n-1);
}