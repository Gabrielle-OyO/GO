//
// Created by 18377 on 2021/8/22.
//习题1.9 有序数组的插入
//首尾情况不用分开考虑，在一个for循环就能完成
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;//保存线性表中最后一个元素的位置
};

List ReadInput();//裁判实现，细节不表。元素从下标0开始储存
void PrintList(List L);//裁判实现，细节不表
bool Insert(List L,ElementType X);

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if (Insert(L,X)==false)
        printf("Insertion failed.\n");
    PrintList(L);
    return 0;
}



bool Insert(List L,ElementType X)
{
    int i,j;
    if(L->Last==MAXSIZE-1)
        return false;
    for (i=0;i<=L->Last;i++)
    {
        if(L->Data[i]==X)
        {
            return false;
        }else if(L->Data[i]<X)
        {
            for(j=L->Last;j>=i;j--)
            {
                L->Data[j+1]=L->Data[j];
            }
            L->Data[i]=X;
            L->Last=L->Last+1;//不要忘记长度加一
            return true;
        }
        else if(i==L->Last&&L->Last>X)
        {
            L->Data[L->Last+1]=X;
            L->Last=L->Last+1;//不要忘了长度加一
            return true;
        }
    }
}
