#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "primes_gen.h"

int trial_divisions(unsigned int candidate, unsigned int *primes, int num_primes) {
    for (int j = 0; j < num_primes; ++j) {
        unsigned int p = primes[j];
        if (p * p > candidate) {
            break;
        }
        if (candidate % p == 0) {
            return 0;
        }
    }
    return 1;
}

// Finds the first num_primes prime numbers and returns the result in a prime_res struct.
struct prime_res generate_primes(int num_primes) {
    struct prime_res result;

    unsigned int *primes = malloc(num_primes * sizeof(unsigned int));
    primes[0] = 2;
    primes[1] = 3; // initialize the second prime

    time_t start = clock();
    // i is index for the next prime to find
    char isPrimeFlag = 1;
    for (int i = 2; i < num_primes; i++) {
        unsigned int candidate = primes[i-1];
        do {
            candidate += 1;
            isPrimeFlag = trial_divisions(candidate, primes, i);
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