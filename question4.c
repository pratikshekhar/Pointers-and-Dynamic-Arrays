#include<stdlib.h>
#include<stdio.h>

struct node{

int data;
struct node *next;

};

void freeList(struct node *start);
void sort(struct node *start);

int main(void){

struct node *start=NULL;
start=(struct node *)malloc(sizeof(*start));
if (start == NULL) {
  printf("no memory!\n");
  exit(1);
}
int size=6;
start->data=rand()%10;
srand((unsigned int)time(NULL));
struct node *previous;
previous=start;
for(int i=1;i<size;i++){
struct node *n=(struct node *)malloc(sizeof(struct node));
n->data=rand()%10;
n->next=NULL;
previous->next=n;
previous=n;
}

printf("%d RANDOM numbers are\n",size);
struct node* tempPtr;
tempPtr = start;
while(tempPtr != NULL) {
printf("%d\n", tempPtr->data);
tempPtr = tempPtr->next;
}

printf("After sorting, the numbers are in ascending order\n");

sort(start);
tempPtr = start;
while(tempPtr != NULL) {
printf("%d\n", tempPtr->data);
tempPtr = tempPtr->next;
}
freeList(start);

return 0;
}
void freeList(struct node* start)
{
   struct node* temp;

   while (start != NULL)
    {
       temp = start;
       start = start->next;
       free(temp);
    }

}

void sort(struct node *start){
int temp;

struct node *tempPtr;
struct node *tempNext;
struct node *copyPtr;

for(tempPtr =start; tempPtr!= NULL; tempPtr = tempPtr->next)
	{
	copyPtr=tempPtr;
    
      for(tempNext = tempPtr->next; tempNext != NULL; tempNext = tempNext->next)
        if(tempNext->data < copyPtr->data)
		copyPtr=tempNext;
	if(copyPtr != tempPtr){

		temp=tempPtr->data;
		tempPtr->data=copyPtr->data;
		copyPtr->data=temp;
	}
}
}
