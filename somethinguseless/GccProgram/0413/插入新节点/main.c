#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next; //嵌套定义
}LNode,*LinkList;

void Print__LinkList(LinkList L)
{
    //读出L链表中的数据
    LNode* p;
    p = L->next;
    while (p)
    {
        printf("%d,", p->data);
        p = p ->next;
    }
}

LNode* Get_LinkList(LinkList  L, int  i)
{
    LNode* p = L;
    int  j = 0;
    while (p->next && j<i )
    {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}


//键盘输入结点数据， 直到-1结束  头插法
LinkList Create_LinkList1()
{
    LinkList L = NULL;
    LNode* s;
    int flag = -1;
    int x;
    L = malloc(sizeof(LNode));
    L->data = flag;
    L->next = NULL;

    scanf("%d", &x);
    while(x != flag)
    {
        s = malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList Create_LinkList2()
{
    LinkList L = NULL;
    int flag = -1;
    int x;
    LNode* s = NULL;
    LNode* r = NULL;

    L = r = malloc(sizeof(LNode));      //链表的首地址给了L
    L->data = flag;
    L->next = NULL;

    //尾插法
    scanf("%d", &x);
    while(x != -1){
        s = malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    if (r != NULL){
        r->next = NULL;
    }

    return L;
}

/*在单链表L的第i个位置上插入值为x的元素*/
int  Insert_LinkList( LinkList  L, int i, int  x)
{
    LNode  * p,*s;
    p=Get_LinkList(L,i-1);   /*查找第i-1个结点*/
    if (p==NULL)
    { printf("参数i错");
        return 0;
    } /*第i-1个不存在*/
    else
    {
        s=malloc(sizeof(LNode)); /*申请结点*/
        s->data=x;
        s->next=p->next; /*新结点插入在第i-1个结点后*/
        p->next=s;
        return 1;
    }
}

int main()
{
    LNode* p;      //存放任意结点的地址
    LinkList L;   //存放链表头元素的地址 ，简称为链表地址
    //t i = 0;
    printf("头插法：");
    L = Create_LinkList1();
    Print__LinkList(L);

    /*
    printf("尾插法：");
    L = Create_LinkList2();
    Print__LinkList(L);

    printf("查找：");
    p = Get_LinkList(L,1);
    printf("%d", p->data);
    */

    printf("插入：");
    Insert_LinkList(L,2,9);
    Print__LinkList(L);
    return 0;
}
