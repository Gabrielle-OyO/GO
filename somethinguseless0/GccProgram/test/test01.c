//
// Created by 18377 on 2021/4/4.
//

#define MAXSIZE 10
int Score_Avg(int y[], int n)
{
    int i,sum = 0;
    for(i = 0; i < n; i++)
        sum = sum + y[i];
    return 	sum/n;
}

void Score_max(int y[], int n,int* pmax, int* pmin)
{
    int i;
    *pmax = y[0];
    *pmin = y[0];

    for(i = 1; i < n; i++){
        if(y[i] > *pmax){
            *pmax = y[i];
        }
    }//max

    for(i = 1; i < n; i++){
        if(y[i] < *pmin){
            *pmin = y[i];
        }
    }
}

int Score_Insert(int y[], int* n, int i, int data)
//y数组长度为n，把data 插入到第i个位置
{
    if(*n == MAXSIZE)
    {
        printf("overflow");
        return -1;
    }
    //插入位置i是否合法？
    if(i < 1 || i > n + 1)
    {
        printf("i error");
        return 0;
    }

    //插入数据

}

int main()
{
    int x[MAXSIZE],i,avg = 0,max, min;
    for(i = 0; i < 3; i++)
        scanf("%d",&x[i]);

    avg = Score_Avg(x,3);
    Score_max(x,3,&max,&min);

    printf("avg：%d,", avg);
    printf("max：%d,", max);
    printf("min：%d", min);
    return 0;
}
