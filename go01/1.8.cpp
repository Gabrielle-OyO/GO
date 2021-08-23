//
// Created by 18377 on 2021/8/22.
//  习题1.8 二分查找

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;//保存线性表中最后一个元素的位置
};

List ReadInput();//裁判实现，细节不表。元素从下标1开始储存
Position BinarySearch(List L,ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;
    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L,ElementType X)
{
    if(L){
        Position left=1,right=L->Last,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(X==L->Data[mid])
                return mid;
            else if(X<L->Data[mid])
                right=mid-1;
            else if(X>L->Data[mid])
                left=mid+1;
        }
        return NotFound;
    }
    return NotFound;
}
