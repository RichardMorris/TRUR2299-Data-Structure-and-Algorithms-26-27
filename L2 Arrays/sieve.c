#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "primes_gen.h"

struct prime_res generate_primes(int num_primes) {
    struct prime_res result;
    
    int num_entries = 20000000;

    unsigned int *found = malloc(num_primes * sizeof(unsigned int));

    unsigned int *initial = malloc(num_entries * sizeof(unsigned int));
    bool *possible = malloc(num_entries * sizeof(bool));
    time_t start = clock();
    for(int i = 0; i < num_entries; i++) {
        initial[i] = i;
        possible[i] = true;
    }
    possible[0] = false;
    possible[1] = false;
    int cur_prime = 2;
    int cur_index = 2;
    int num_to_test = num_entries;
    int num_coprime = 0;
    int primes_found = 0;

    for(int loop = 0; loop < num_primes; loop++) {
        // first entry in initial is a prime
        found[primes_found++] = cur_prime;

        // filter out multiples of cur_prime
        for(int multiple = cur_prime*cur_prime; multiple < num_entries; multiple += cur_prime) {
            possible[multiple] = false;
        }
        for(int i = cur_index+1; i < num_to_test; i++) {
            if(possible[i]) {
                cur_prime = initial[i];
                cur_index = i; 
                break;
            }
        }
        if(loop % 1000 == 0 || loop < 10) {
            printf("%d %d %d %ld\n", loop, cur_prime, num_coprime, clock() - start);
        }
    }

    time_t end = clock();

    result.time_taken = end - start;
//    result.last_prime = isPrimeFlag ? primes[num_primes-1] : 0;
    result.last_prime = cur_prime;
    free(initial);
    free(found);
    return result;
}