#include <stdio.h>
#include <stdlib.h>

// show that stack is growing downwards and heap is growing upwards

int cnt = 0;

void recursion(int x){
    if(x == 0){
        return;
    }
    int top;
    printf("Stack Top: %p\n", &top);
    recursion(x-1);
}

int *hp = NULL;
void mallocInHeap(int x){
    hp = (int*)malloc(sizeof(int) * x);
    for(int i = 0; i < x; i++){
        printf("Heap Top: %p\n", &hp[i]);
    }
    free(hp);
}

void mallocInHeap2(int x){
    if(x == 0){
        return;
    }
    int *hp2 = (int*)malloc(sizeof(int));
    printf("Heap2 Top: %p\n", hp2);
    mallocInHeap2(x-1);
    free(hp2);
}

void stackOverflow(){
    int newVar;
    int *newMalloc = (int*)malloc(sizeof(int));
    printf("Stack Growing: %p\n", &newVar);
    printf("Heap Growing: %p\n", newMalloc);
    stackOverflow();
}

char name = 'a';

int main(){
    printf("1st global var (cnt: int): %p\n", &cnt);
    printf("2nd global var (hp2: pointer): %p\n", &hp);
    printf("3rd global var (name: char): %p\n", &name);
    recursion(3);
    mallocInHeap(3);
    mallocInHeap2(3);
    stackOverflow();
    return 0;
}