#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define CLOCKS_PER_MILLI (CLOCKS_PER_SEC / 1000)

// Simple cases for n * 3 arrays
// need to specify the second dimension of the array
// so C can work out the memory layout correctly
// Just used to check array alocation works
int64_t sum0(int32_t arr[][3], int rows)
{
    int cols = 3;
    int64_t sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

// First example from interviewer, summing row-wise
int64_t sum1(int32_t array[][10000], int rows, int cols)
{
    int64_t sum=0;
    for (int x = 0; x < 9999; x++) for (int y = 0; y <= 9999; y++) sum += array[x][y];
    return sum;
}

// Second example from interviewer, summing column-wise
int64_t sum2(int32_t array[][10000], int rows, int cols)
{
    int64_t sum=0;
    for (int y = 0; y <= 9999; y++) for (int x = 0; x < 9999; x++) sum += array[x][y];
     return sum;
}

// Third example uses loop unrolling to sum the array elements efficiently
int64_t sum3(int32_t array[][10000], int rows, int cols)
{
    int64_t sum=0;
    int32_t *ptr = &array[0][0]; // Take the address of the first element of the array
    for (int i = 0; i < 10000*10000; i++)
        sum += ptr[i];
    return sum;
}

// Fourth example adds a couple of optimizations by iterating from the end and using pointer arithmetic
int64_t sum4(int32_t array[][10000], int rows, int cols)
{
    int64_t sum=0;
    int32_t *ptr = &array[0][0];
    for (int i =10000*10000-1; i >= 0; --i)
        sum += *ptr++;
    return sum;
}

// First example from interviewer, summing row-wise
int64_t sum1a(int32_t array[][10000], int rows, int cols)
{
    int64_t sum=0;
    for (int x = 0; x <= 9999; x++) for (int y = 0; y <= 9999; y++) sum += array[x][y];
    return sum;
}

// Delaring a large array outside of any function, 
// so it is allocated in the global/static memory area rather than the stack.
int32_t arr3[10000][10000];

int main()
{
    int32_t arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int64_t result = sum0(arr1, 2);
    printf("Sum of array elements: %lld\n", result);

    // Initialize a large 2D array using int32_t arr2[700][700];
    // allocates memory on the stack rather than the heap
    // this about the maximum size of arrays that can be allocated on the stack
    // at just under 2,000,000 bytes.
    int32_t arr2[700][700];
    printf("Size of arr2: %zu\n", sizeof(arr2));
    // int32_t arr2[750][750];
    // fails.
    printf("Size of arr3: %zu\n", sizeof(arr3));
    
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            arr3[i][j] = 1;
        }
    }


    int start = clock();
    int64_t res1 = sum1(arr3, 10000, 10000);
    int end = clock();

    printf("Method 1 time taken: %.0f ms\n", (double)(end - start) / CLOCKS_PER_MILLI);

    start = clock();
    int64_t res2 = sum2(arr3, 10000, 10000);
    end = clock();

    printf("Method 2 time taken: %.0f ms\n", (double)(end - start) / CLOCKS_PER_MILLI);

    start = clock();
    int64_t res3 = sum3(arr3, 10000, 10000);
    end = clock();

    printf("Method 3 time taken: %.0f ms\n", (double)(end - start) / CLOCKS_PER_MILLI);

    start = clock();
    int64_t res4 = sum4(arr3, 10000, 10000);
    end = clock();

    printf("Method 4 time taken: %.0f ms\n", (double)(end - start) / CLOCKS_PER_MILLI);

    getchar();
    printf("Sums: %lld, %lld, %lld, %lld\n", res1, res2, res3, res4);

    // Dynamically allocated 2D array on the heap using malloc
    int (*arr4)[10000];
    arr4 = malloc(10000*10000*sizeof(int32_t));

    int n=1;
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            arr4[i][j] = n++;
        }
    }

    start = clock();
    int64_t res5 = sum4(arr4, 10000, 10000);
    end = clock();
    
    printf("Method 5 result %lld time taken: %.0f ms\n", res5, (double)(end - start) / CLOCKS_PER_MILLI);

    start = clock();
    int64_t res6 = sum1a(arr4, 10000, 10000);
    end = clock();
    
    printf("Method 1a result %lld time taken: %.0f ms\n", res6, (double)(end - start) / CLOCKS_PER_MILLI);

}