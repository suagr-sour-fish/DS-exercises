#include <stdio.h>
int MaxSeqSum(int a[],int N);
int main(void){
    int K,i;
    int Ni[100000];
    scanf("%d",&K);
    for(i=0;i<K;i++){
        scanf("%d",&Ni[i]);
    }
    printf("%d",MaxSeqSum(Ni,K));
    return 0;
}

int MaxSeqSum(int a[],int N){
    int MaxSum,ThisSum;
    int i;
    MaxSum=ThisSum=0;
    for(i=0;i<N;i++){
        ThisSum+=a[i];
        if(ThisSum>MaxSum){
            MaxSum=ThisSum;
        }
        else if(ThisSum<0){
            ThisSum=0;
        }
    }
    return MaxSum;
}