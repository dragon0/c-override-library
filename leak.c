#include<stdio.h>
int main()
{
    void *ptr1 = malloc(10);
    void* ptr2 = malloc(50);
    void* ptr3 = malloc(70);
    void* ptr4 = malloc(123);
    //do something
    free(ptr3);
    free(ptr1);
    return 0;
}
