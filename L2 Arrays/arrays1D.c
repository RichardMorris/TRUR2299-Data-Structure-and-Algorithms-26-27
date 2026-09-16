// standard input and output
#include <stdio.h>
// definitions of interger types with different sizes
#include <stdint.h>
// time functions
#include <time.h>
// standard library functions, including memory allocation
#include <stdlib.h>
// define clock ticks per millisecond
#define CLOCKS_PER_MILLI (CLOCKS_PER_SEC / 1000)

// declare a global array of 500,000 32-bit integers
// 
int32_t global[500000];

int64_t sum_array(int32_t *array, int size)
{
    int64_t sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main()
{
    // declare an array on the stack
    int32_t stack[500000];

    // declare array on the heap using malloc
    int32_t *heap = (int32_t*)malloc(500000 * sizeof(int32_t));

    // declare array initialised to zero
    int32_t *zero = (int32_t*)calloc(500000, sizeof(int32_t));

    printf("sizeof char:\t%zu\n", sizeof(char));
    printf("sizeof int16_t:\t%zu\n", sizeof(int16_t));
    printf("sizeof int32_t:\t%zu\n", sizeof(int32_t));
    printf("sizeof int64_t:\t%zu\n", sizeof(int64_t));
    printf("sizeof int:\t%zu\n", sizeof(int));

    printf("Size of global:\t\t%zu\n", sizeof(global));
    printf("Address of global:\t%p\n", (void*)global);

    printf("Size of stack:\t\t%zu\n", sizeof(stack));
    printf("Address of stack:\t%p\n", (void*)stack);

    printf("Size of heap:\t\t%zu\n", sizeof(heap));
    printf("Address of heap:\t%p\n", (void*)heap);

    printf("Size of zero:\t\t%zu\n", sizeof(zero));
    printf("Address of zero:\t%p\n", (void*)zero);

    // initialise arrays
    for (int i = 0; i < 500000; i++) {
        global[i] = i;
        stack[i] = i;
        heap[i] = i;
        zero[i] = i;
    }

    // sum of arrays
    int64_t sum_global = 0;
    int64_t sum_stack = 0;
    int64_t sum_heap = 0;
    int64_t sum_zero = 0;
    int start = clock();
    for (int i = 0; i < 500000; i++) {
        sum_global += global[i];
        sum_stack += stack[i];
        sum_heap += heap[i];
        sum_zero += zero[i];
    }
    int end = clock();

    printf("Using array indexing:\n");
    printf("Sum of global:\t%lld\n", sum_global);
    printf("Sum of stack:\t%lld\n", sum_stack);
    printf("Sum of heap:\t%lld\n", sum_heap);
    printf("Sum of zero:\t%lld\n", sum_zero);
    printf("Time taken for summing arrays: %d\n\n", (end - start));

    
    // sum using pointers 
    sum_global = 0;
    sum_stack = 0;
    sum_heap = 0;
    sum_zero = 0;
    start = clock();
    for(int i = 0; i < 500000; i++) {
        sum_global += *(global + i);
        sum_stack += *(stack + i);
        sum_heap += *(heap + i);
        sum_zero += *(zero + i);
    }
    end = clock();
    printf("Using pointer arithmetic:\n");
    printf("Sum of global:\t%lld\n", sum_global);
    printf("Sum of stack:\t%lld\n", sum_stack);
    printf("Sum of heap:\t%lld\n", sum_heap);
    printf("Sum of zero:\t%lld\n", sum_zero);
    printf("Time taken for summing arrays: %d \n\n", (end - start));

    // sum by incrementing pointers
    sum_global = 0;
    sum_stack = 0;
    sum_heap = 0;
    sum_zero = 0;
    start = clock();
    for (int *p = global, *q = stack, *r = heap, *s = zero; 
        p < global + 500000; p++, q++, r++, s++) {
        sum_global += *p;
        sum_stack += *q;
        sum_heap += *r;
        sum_zero += *s;
    }
    end = clock();
    printf("Using pointer incrementing:\n");
    printf("Sum of global:\t%lld\n", sum_global);
    printf("Sum of stack:\t%lld\n", sum_stack);
    printf("Sum of heap:\t%lld\n", sum_heap);
    printf("Sum of zero:\t%lld\n", sum_zero);
    printf("Time taken for summing arrays: %d \n\n", (end - start));

    sum_global = sum_array(global, 500000);
    sum_stack = sum_array(stack, 500000);
    sum_heap = sum_array(heap, 500000);
    sum_zero = sum_array(zero, 500000);
    printf("Using sum_array function:\n");
    printf("Sum of global:\t%lld\n", sum_global);
    printf("Sum of stack:\t%lld\n", sum_stack);
    printf("Sum of heap:\t%lld\n", sum_heap);
    printf("Sum of zero:\t%lld\n", sum_zero);
    printf("Time taken for summing arrays using sum_array function: %d \n\n", (end - start));

    // free heap and zero arrays
    free(heap);
    free(zero);
}