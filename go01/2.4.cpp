//
// Created by 18377 on 2021/8/23.
//习题2.4 递增的整数序列链表的插入

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
List Read();//细节在此不表
void Print(List L);//细节在此不表
List Insert(List L,ElementType X);
int main()
{
    List L;
    ElementType X;
    L=Read();
    scanf("%d",&X);
    L=Insert(L,X);
    Print(L);
    return 0;
}

//重点在首位结点的插入
List Insert(List L,ElementType X)
{
    List head=L;//头节点无信息
    L=L->Next;//转到第一个结点
    List p=(List)malloc(sizeof(struct Node));
    p->Data=X;
    p->Next=NULL;
    List q=head;//初始为头节点
    if(L==NULL)//空链表
    {
        head->Next=p;
        return head;
    }
    while(L->Data<X)
    {
        q=L;
        L=L->Next;
        if(L->Next==NULL)//链表尾
            {
            L->Next=p;
            return head;
            }
    }
    p->Next=L;//插在中间
    q->Next=p;
    return head;
}