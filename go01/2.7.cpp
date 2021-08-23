//
// Created by 18377 on 2021/8/23.
//习题2.7 弹球距离

#include<stdio.h>
#define TOL 1E-2
double dist(double h,double p);
int main()
{
    double h,p,d;
    scanf("%lf %lf",&h,&p);
    d=dist(h,p);
    printf("%.6f\n",d);
    return 0;
}


double dist(double h,double p)
{
    double high=h;
    double time=p;
    double mix=time *h;
    while (mix>TOL)
    {
        high=high+2*mix;
        mix=p*mix;
    }
    return high;
}