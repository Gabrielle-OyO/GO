//
// Created by 18377 on 2021/8/23.
//习题2.5 两个有序链表序列的合并

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
List Read();
void Print(List L);
List Merge(List L1,List L2);
int main()
{
    List L1,L2,L;
    L1=Read();
    L2=Read();
    L=Merge(L1,L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1,List L2){
    List p=L1->Next;
    List q=L2->Next;
    List head=(List)malloc(sizeof(List));
    List r=head;
    r->Next=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->Data<=q->Data){
            r->Next=p;
            p=p->Next;
            r=r->Next;
        }
    }
    r->Next=NULL;
    if(p!=NULL)r->Next=p;
    if(q!=NULL)r->Next=q;
    L1->Next=NULL;
    L2->Next=NULL;
    return head;
}