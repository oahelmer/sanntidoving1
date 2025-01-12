// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;
const int count = 1000000;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for (size_t j = 0; j < count; j++)
    {
        i += 1;
    }
    
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (size_t j = 0; j < count; j++)
    {
        i -= 1;
    }
    
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t incrementingThreadFunction_thread;
    pthread_t decrementingThreadFunction_thread;
    pthread_create(&incrementingThreadFunction_thread, NULL, &incrementingThreadFunction, NULL);
    pthread_create(&decrementingThreadFunction_thread, NULL, &decrementingThreadFunction, NULL);


    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    
    pthread_join(incrementingThreadFunction_thread, NULL);
    pthread_join(decrementingThreadFunction_thread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
