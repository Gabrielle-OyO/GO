/*
 * 习题2.1 简单计算器
 */

#include<stdio.h>
int main()
{
    int m,n;
    int result=0;
    char c,d;
    scanf("%d",&m);
    while(c!='=')
    {
        scanf("%c",&c);
        switch(c){
            case '+':
                scanf("%d",&n);
                result=m+n;
                d=c;
                break;
            case '-':
                scanf("%d",&n);
                result=m-n;
                d=c;
                break;
            case '*':
                scanf("%d",&n);
                result=m*n;
                d=c;
                break;
            case '/':
                scanf("%d",&n);
                if(n==0){
                    printf("ERROR");
                    return 0;
                }else{
                    result=m/n;
                    d=c;
                    break;
                }
            case '=':
                printf("%d%c%d%c%d",m,d,n,'=',result);
                return 0;
            default:
                printf("ERROR");
                return 0;
        }
    }
    return 0;
}