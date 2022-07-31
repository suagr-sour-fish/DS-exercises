#include <stdio.h>
#include <stdlib.h>
int main(void){
	FILE *fp;
	
	if((fp=fopen("demo.txt","w+"))==NULL){
		printf("File open error!\n");
		exit(0);
	}
	
	fprintf(fp,"%ld %-15s %d\n",3200103,"tcy",100);
	//rewind(fp);
	fprintf(fp,"%ld %-15s %d\n",3200102,"hmm",101);
	
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}