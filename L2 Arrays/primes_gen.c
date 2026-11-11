#include <time.h>
#include <stdlib.h>
#include <limits.h>

#include "primes_gen.h"

struct prime_res generate_primes(int num_primes) {
    struct prime_res result;

    unsigned int *primes = malloc(num_primes * sizeof(unsigned int));
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
        } while (!isPrimeFlag && candidate < UINT_MAX - 2);
        if(!isPrimeFlag)
            break;
        // now found a prime save it
        primes[i] = candidate;
    }
    time_t end = clock();

    result.time_taken = end - start;
    result.last_prime = isPrimeFlag ? primes[num_primes-1] : 0;
    
    free(primes);
    return result;
}