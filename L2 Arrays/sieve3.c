#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "primes_gen.h"

struct prime_res generate_primes(int num_primes) {
    struct prime_res result;
    
//    int num_entries = 20,000,000;
    int num_entries = 20000000;

    unsigned int *found = malloc(num_primes * sizeof(unsigned int));

    unsigned int *initial = malloc(num_entries * sizeof(unsigned int));
    unsigned int *next = malloc(num_entries * sizeof(unsigned int));
    time_t start = clock();
    for(int i = 0; i < num_entries; i++) {
        initial[i] = i+2;
    }

    int cur_prime = 2;
    int num_to_test = num_entries;
    int num_coprime = 0;
    int primes_found = 0;

    for(int loop = 0; loop < num_primes; loop++) {
        // first entry in initial is a prime
        cur_prime = initial[0];
        found[primes_found++] = cur_prime;

        // filter out multiples of cur_prime
        num_coprime = 0;
        for(int i = 0; i < num_to_test; i++) {
            if(initial[i] % cur_prime != 0) {
                next[num_coprime++] = initial[i];
            }
        }
        int *tmp = initial;
        initial = next;
        next = tmp;
        num_to_test = num_coprime;
        // if(loop % 1000 == 0 || loop < 10) {
        //     printf("%d %d %d %ld\n", loop, cur_prime, num_coprime, clock() - start);
        // }
        if(cur_prime * cur_prime > num_entries) {
            for(int i = 0; i < num_coprime; i++) {
                if(primes_found >= num_primes) {
                    break;
                }
                found[primes_found++] = initial[i];
            }
            break;
        }
    }
    time_t end = clock();

    result.time_taken = end - start;
//    result.last_prime = isPrimeFlag ? primes[num_primes-1] : 0;
    result.last_prime = found[num_primes-1];
    free(initial);
    free(found);
    return result;
}