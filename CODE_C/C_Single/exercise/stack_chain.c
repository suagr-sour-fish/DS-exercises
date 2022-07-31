#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR -1

typedef struct StackNode
{
    int num;
    struct StackNode *next;
}StackNode, *LinkStack;

int InitStack(LinkStack *S)
{//构造一个空栈S，栈顶指针置空
    *S=NULL;
    return OK;
}

int Push(LinkStack *S, int e)
{//在栈顶插入元素e
    LinkStack p;
    p=(LinkStack)malloc(sizeof(StackNode));
    if(!p) exit(EXIT_FAILURE);
    p->num = e;
    p->next = *S;
    *S = p;
    return OK;
}

int Pop(LinkStack *S, int *e)
{//删除S的栈顶元素，用e返回其值
    if(*S==NULL)
    {
        printf("栈空！\n");
        return ERROR;
    }
    LinkStack p;
    *e=(*S)->num;
    p=*S;
    *S = (*S)->next;
    free(p);
    return OK;
}

int GetTop(LinkStack S)
{//返回S的栈顶元素，不修改栈顶指针
    if(S!=NULL)
        return S->num;
    else
    {
        printf("栈空！\n");
        return ERROR;
    }
    
}

int main(void)
{
    StackNode *stack;
    int choice,numin,numout,top;
    do{
        printf("1:创建空栈 2:入栈 3:出栈 4:返回栈顶元素 0:exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InitStack(&stack);
            break;
        case 2:
            printf("请输入入栈数据: ");
            scanf("%d",&numin);
            Push(&stack,numin);
            break;
        case 3:
            if(Pop(&stack,&numout)!=ERROR)
                printf("出栈数据为 %d\n",numout);
            break;
        case 4:
            top=GetTop(stack);
            if(top==ERROR)
                printf("栈为空！\n");
            else
                printf("栈顶元素为 %d\n",top);
            break;
        case 0:
            break;
        }
    }while(choice!=0);

    return 0;
}