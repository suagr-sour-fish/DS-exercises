#include <stdio.h>
typedef int *pint;
int main(void){
    pint a;
    int b;
    b=1;
    a=&b;
    printf("a=%d, b=%d",*a,b);
    return 0;
}