#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR -1
typedef struct{
    int *base;
    int *top;
    int stacksize;
} Sqstack;

int InitStack(Sqstack *S)
{//构造一个空栈
    S->base = (int *)calloc(MAXSIZE,sizeof(int));
    if(!S->base) exit(EXIT_FAILURE);
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return OK;
}

int Push(Sqstack *S, int e)
{//插入元素e为新的栈顶元素
    if(S->top-S->base==S->stacksize){
        printf("栈满!\n");
        return ERROR;
    }
    *(S->top++)=e;
    return OK;
}

int Pop(Sqstack *S, int *e)
{//删除栈顶元素，用e返回其值
    if(S->top==S->base){
        printf("栈为空！\n");
        return ERROR;
    }
    *e=*(--S->top);
    return OK;
}

int GetTop(Sqstack *S)
{
    if(S->top!=S->base){
        return *(S->top-1);
    }
    else
        return ERROR;
}

int StackEmpty(Sqstack *S)
{
    if(S->top==S->base) return 1;
    else return 0;
}

void conversion(int N)
{
    Sqstack stack;
    int e;
    InitStack(&stack);
    while(N)
    {
        Push(&stack,N%8);
        N=N/8;
    }
    while(!StackEmpty(&stack)){
        Pop(&stack,&e);
        printf("%d",e);
    }
}
int main(void){
    Sqstack stack;
    int N;
    printf("请输入大于0的十进制数以转换为八进制数:\n");
    scanf("%d",&N);
    conversion(N);

    /*int choice,numin,numout,top;
    int status;
    do{
        printf("1:创建空栈 2:入栈 3:出栈 4:返回栈顶元素 0:exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InitStack(&stack);
            break;
        case 2:
            if(status!=ERROR){
                printf("请输入入栈数据: ");
                scanf("%d",&numin);
                status=Push(&stack,numin);
            }
            else
                printf("栈满！\n");
            break;
        case 3:
            if(Pop(&stack,&numout)!=ERROR)
                printf("出栈数据为 %d\n",numout);
            break;
        case 4:
            top=GetTop(&stack);
            if(top==ERROR)
                printf("栈为空！\n");
            else
                printf("栈顶元素为 %d\n",top);
            break;
        case 0:
            break;
        }
    }while(choice!=0);*/

    return 0;

}
