#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    int *array;
    int data;
    int size;
} Array;

void printArray(Array* a){
	for(int i = 0 ; i < a-> data; i++) {
        	printf("%d\n",a->array[i]);
    }
}

void initArray(Array *a, int size){
    a->array =  (int*)malloc(size * sizeof(int));
    a->size = size;
    a->data = 0;
}

void insertion1(Array *a,int element){
	if (a->data == a->size){
        a->size = a->size++;
        a->array = (int*) realloc (a->array, a->size * sizeof(int));
    }
    	else
        a->data++;
   	a->array[a->data] = element;
}

void insertion2(Array *a,int element){
    	if (a->data == a->size){
              a->size *= 2;
        a->array = (int*) realloc (a->array, (a->size*2) * sizeof(int));
    }
    	else
        a->data++;
    	a->array[a->data] = element;
}

void add(Array *a, int value, int element){
	if(value <= a->size){
        a->size += 1;
        a->array = (int*) realloc (a->array, a->size * sizeof(int));
              for(int i = value; i < a->size; i++){
            a->array[i+1] = a -> array[i + 2];
        }
        a->array[value] = element;
    }
    else
        printf("Index is out of bound");
}

void removeElement(Array *a, int value){
    if(value <= a->size){
               for(int i = value; i < a->size; i++){
            a->array[i] = a -> array[i + 1];
        }
        a->size -= 1;
    }
    else
        printf("Index is out of bound");
}

int get(Array *a,int value){
    if(value <= a->size){
        return a->array[value];
    }
    else
        printf("Error 404 not found");
}

int main(void)
{

Array a;
Array b;
srand(time(NULL));
clock_t t1;
clock_t t2;

printf("\n Entering 100000 elements into the array with initial size of 5: \n ");
       int n = 100000;
       t1 = clock();
       initArray(&a,5);
       for (int i = 0; i < n; i++){
            int r = rand()%10;
            insertion1(&a, i);
        }
        t1 = clock() - t1;
printf ("\n It takes %f seconds when array increases in size by a factor of 1.\n",((float)t1)/CLOCKS_PER_SEC);

        t2 = clock();
        initArray(&b,5);
        for (int i = 0; i < n; i++){
            insertion2(&b, i);
        }
        t2= clock() - t2;
printf ("\n It takes %f seconds when array increases in size by a factor of 2 times.\n",((float)t2)/CLOCKS_PER_SEC);

        printf("\n Array of 10 has been created \n");

        initArray(&a,10);
        for (int i = 0; i < 10; i++){
            int r = rand()% 10;
            insertion1(&a, r);
        }
       printArray(&a);
       printf("\n Value at 0th position is %d \n",get(&a,0));
       printArray(&a);
       printf("\n Inserting element 2 at 0th position \n");
       add(&a,0,2);
       printf("\n Value at 0th position is %d \n",get(&a,0));
       printArray(&a);

       printf("\n Removing element at 0th position \n");
       removeElement(&a,0);
       printf("\n Value at 0th position is %d \n",get(&a,0));
       printArray(&a);

       free(&a);
       free(&b);
	
return 0;
}

