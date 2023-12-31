#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void recursion(int x){
    if(x == 0){
        return;
    }
    int top;
    printf("Stack Top: %p\n", &top);
    recursion(x-1);
}

int *ptr;

void mallocInHeap(int x){
    if(x == 0){
        return;
    }
    int *hp = (int*)malloc(sizeof(int));
    printf("Heap Top: %p\n", hp);
    mallocInHeap(x-1);
    free(hp);
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
    printf("2nd global var (ptr: pointer): %p\n", &ptr);
    printf("3rd global var (name: char): %p\n", &name);
    recursion(3);
    mallocInHeap(3);
    stackOverflow();
    return 0;
}