//
// Created by 18377 on 2021/4/6.
//

//
// Created by 18377 on 2021/4/6.
//

#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* next;  //嵌套定义
}LNode,*Linkerlist;

//typedef struct node LNode;        //LNode结构体
//typedef struct node* Linkerlist;  //LNode结构体指针



//键盘输入节点数据，直到-1结束；
LinkerList Create_LinkerList1()      //创建链表
{
    LinkerLIst L=NULL;              //赋予空的空间

    LNOde* s;                   //用于记录任意节点

    int flag=-1;    //头节点无用，故存放-1作为结束标志flag-----若无结束符号，程序进入无限循环
    int x;
    scanf_s("%d",x);
    while(x!=flag)
    {
        s=malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
    }

    L=malloc(sizeof(LNode));
    L->data=1;
    L->next=NULL;

    retrun L;
}

int main()
{
    LNode* P;       //存放任意节点的地址  等价于[node* next]【不可与链表名称L相同,故更改为P】
    Linkerlist L;   //存放链表的头元素的首地址or链表头【定义一条L链表】



    L=malloc(sizeof(LNode));        //创建空间
    L->data=1;                      //头节点赋值
    L->next=NULL;                   //下一节点赋空值NULL

    L=Create_LinkerList1()           //调用初始化函数

    return 0;

}
