#include <stdio.h>
#include <stdlib.h>
#include "primes_gen.h"

int main(int argc, char *argv[]) {
    int num_primes;
    if(argc < 2) {
        printf("Usage: %s <num_primes>\n", argv[0]);
        num_primes = 100; // use default so can run debugger easily
    } else {
        num_primes = atoi(argv[1]);
    }
    printf("%s: Finding the first %d prime numbers...\n", argv[0], num_primes);

    struct prime_res result = generate_primes(num_primes);
    if(result.last_prime) {
        printf("%d-th prime number is %d\n", num_primes, result.last_prime);
    } else {
        printf("Failed to find the %d-th prime number within the limit.\n", num_primes);
    }
    printf("Time taken: %ld ticks\n", (long)result.time_taken);
    return 0;
}