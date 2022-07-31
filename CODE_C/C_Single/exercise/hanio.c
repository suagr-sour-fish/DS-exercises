#include <stdio.h>
void move(char pos1,char pos2)
{
    printf("%c->%c\n",pos1,pos2);
    return;
}
void Hanio(int n,char pos1,char pos2,char pos3)
{
    if(n==1) move(pos1,pos3);
    else
    {
        Hanio(n-1,pos1,pos3,pos2);
        move(pos1,pos3);
        Hanio(n-1,pos2,pos1,pos3);
    }
    return;
}
int main(void){
    Hanio(3,'A','B','C');
    return 0;
}