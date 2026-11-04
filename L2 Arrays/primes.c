#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_PRIMES 1000000

int main(int argc, char *argv[]) {
    unsigned short primes[MAX_PRIMES];
    int num_primes;
    if(argc < 2) {
        printf("Usage: %s <num_primes>\n", argv[0]);
        num_primes = 100; // use default so can run debugger easily
    } else {
        num_primes = atoi(argv[1]);
    }
    printf("%s: Finding the first %d prime numbers...\n", argv[0], num_primes);

    primes[0] = 2;

    time_t start = clock();
    // i is index for the next prime to find
    char isPrimeFlag = 1;
    for (int i = 1; i < num_primes; i++) {
        unsigned int candidate = primes[i-1];
        do {
            ++candidate;
            isPrimeFlag = 1;
            // j is index of prev prime
            for (int j = 0; j < i; ++j) {
                if( candidate % primes[j] == 0) {
                    isPrimeFlag = 0;
                    break;
                }
            }
        } while (!isPrimeFlag && candidate < 65535-2);
        if(!isPrimeFlag)
            break;
        // now found a prime save it
        primes[i] = candidate;
    }
    time_t end = clock();

    if(isPrimeFlag) {
        printf("%d-th prime number is %d\n", num_primes, primes[num_primes-1]);
    } else {
        printf("Failed to find the %d-th prime number within the limit.\n", num_primes);
    }
    printf("Time taken: %ld ticks\n", (long)(end - start));

    return 0;
}