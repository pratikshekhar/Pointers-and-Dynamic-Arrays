#include<stdlib.h>
#include<stdio.h>


void sort(int* a, int size);

int main(void){
int size=6;
int* a=(int *)malloc(size * sizeof(int));

if(a==NULL){
printf("error\n");
exit(1);
}

srand((unsigned int)time(NULL));

printf("%d RANDOM numbers are\n",size);
for(int i=0;i<size;i++){
*(a+i)=rand()% 10;
printf("%d\n", *(a+i));

}
printf("After sorting, the numbers are in ascending order\n");
sort(a, size);

for(int k=0;k<size;k++){
printf("%d\n",*(a+k));

}

free(a);
return 0;
}

void sort(int* a, int size){
int temp;

for(int i=0; i< (size-1);i++){
	for(int j=0;j<(size-i-1);j++){	
	if(*(a+j)>*(a+(j+1))){
		temp = *(a+j);
		*(a+j)=*(a+(j+1));
		*(a+(j+1))=temp;		
			}
		}
	}
}
