#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR -1
#define MAXQSIZE 100

typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue *Q)
{
    Q->base = (int*)calloc(MAXQSIZE,sizeof(int));
    if(!Q->base) exit(EXIT_FAILURE);
    Q->front = Q->rear =0;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int EnQueue(SqQueue *Q , int e)
{
    if((Q->rear+1)%MAXQSIZE == Q->front){
        printf("队满！\n");
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXQSIZE;
    return OK;
}

int DeQueue(SqQueue *Q, int *e)
{
    if(Q->front==Q->rear){
        printf("队空！\n");
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front+1) % MAXQSIZE;
    return OK;
}

int GetHead(SqQueue Q){
    if(Q.front!=Q.rear){
        return Q.base[Q.front];
    }
    else{
        printf("队空！\n");
        return ERROR;
    }
}

int main(void){
    SqQueue Q;
    int choice, num_in, num_out ;
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