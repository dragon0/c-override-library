#include<sys/types.h>
#include<stdio.h>
#include<dlfcn.h>

void* malloc(int size)
{
    void* (*fptr)(int);
    void* handle = (void*) -1l;
    fptr = (void * (*)())dlsym(handle, "malloc");
    if (fptr == NULL)
    {
        printf("Error in locating\n");
        return NULL;
    }
    void*ret  = (*fptr)(size);
    printf("Allocated ptr %x %d\n", ret, size);
    return ret;
}

void free(void* ptr)
{
    void (*fptr)(void*);
    void* handle = (void*) -1; //tells dlsym to locate the next symbol
    fptr = (void (*)(void*))dlsym(handle, "free");
    if (fptr == NULL)
    {
        printf("Error in locating\n");
        return;
    }
    (*fptr)(ptr);
    printf("Deallocated ptr %x\n", ptr);
    return;
}

