#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR -1

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue *Q)
{//构造一个空队列
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    (*Q).front->next = NULL;
    return OK;
}

int EnQueue(LinkQueue *Q , int e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    return OK;
}

int DeQueue(LinkQueue *Q , int *e)
{//删除Q的队头元素，用e返回其值
    if((*Q).front == (*Q).rear)
    {
        printf("队空！\n");
        return ERROR;  //队列空，返回ERROR;
    }
    QueuePtr p;
    p = (*Q).front->next; //p指向队头元素
    *e = p->data;  //e保存队头元素的值
    (*Q).front->next = p->next; //修改头指针
    if((*Q).rear == p) (*Q).rear=(*Q).front;  //若最后一个元素被删，队尾指针指向头结点
    free(p); //释放原队头元素的空间;
    return OK;
}

int GetHead(LinkQueue Q)
{
    if(Q.front != Q.rear){
        return Q.front->next->data;
    }
    else{
        printf("队空！\n");
        return ERROR;
    }
}

int main(void){
    LinkQueue Q;
    int choice, num_in, num_out;
    do{
        printf("1:初始化队列 2:入队 3:出队 4:返回队头元素 0:exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InitQueue(&Q);
            break;
        case 2:
            printf("请输入入队元素:");
            scanf("%d",&num_in);
            EnQueue(&Q,num_in);
            break;
        case 3:
            if(DeQueue(&Q,&num_out)!=ERROR)
            {
                printf("出队元素为%d\n",num_out);
            }
            break;
        case 4:
            if(GetHead(Q)!=ERROR)
                printf("队头元素为%d\n",GetHead(Q));
        case 0:
            break;
        }
    }while(choice!=0);
    return 0;
}



