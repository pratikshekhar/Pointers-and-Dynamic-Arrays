#include<stdio.h>
#include<stdlib.h>

int main(void){

int* var;

var = (int *)malloc(10 * sizeof(int));
if(var == NULL){
printf("malloc");
exit(-1);
}

for(int i=0;i<10;i++){
var[i]=i;

printf("%d\n",var[i]);

}
free(var);


return 0;
}

