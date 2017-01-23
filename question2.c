#include<stdlib.h>
#include<stdio.h>

int main(void){
char **var;
char array[15]="pratikShekhar";

var=(char **)malloc(10 * sizeof(char *));
for(int i=0;i<10;i++){
char* x=malloc(15 * sizeof(char ));
strcpy(x,array);
var[i]=x;
printf("%s\n",var[i]);

}
free(var);

return 0;
}
