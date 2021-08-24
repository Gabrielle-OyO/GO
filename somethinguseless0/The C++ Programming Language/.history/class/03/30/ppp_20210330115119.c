#define MAXSIZE 1024
typedef int DataType;
typedef struct
{
    DataType data[MAXSIZE]; //int data[1024];
    int last;               // 最后一个元素的下标
} SeqList;                  //定义了顺序表的数据结构

SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->last = -1;
    return L;
}

void Print_SeqList(SeqList *L)
{
    int i;
    for (i = 0; i <= L->last; i++)
        printf("%d; ", L->data[i]);
}

int Insert_SeqList(SeqList *L, int i, DataType data)
{
    int k;
    if (L->last + 1 == MAXSIZE)
    {
        printf("overflow");
        return -1;
    }
    //插入位置i是否合法？
    if (i < 1 || i > L->last + 2)
    {
        printf("i error");
        return 0;
    }

    //插入数据
    for (k = L->last + 1; k >= i; k--)
        L->data[k] = L->data[k - 1];
    L->data[i - 1] = data;

    L->last = L->last + 1;
    return 1;
}

int Delete_SeqList(SeqList *L, int i)
{
    int k;
    if (L->data == 0)
    {
        printf("no data");
        return -1;
    }

    if (i > *n + 1 || i < 1)
    {
        printf("i error");
        return 0;
    }

    for (k = i; k <= *n - 1; k++)
    {
        y[k - 1] = y[k];
    }
    *n = *n - 1;
    return 1;
}

int main()
{
    int i;
    //SeqList List, *L;  //空
    //L = &List;
    SeqList *L = Init_SeqList();

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &L->data[i]);
        L->last++;
    }

    Print_SeqList(L);

    Insert_SeqList(L, 1, 9);
    Print_SeqList(L);

    return 0;
}
