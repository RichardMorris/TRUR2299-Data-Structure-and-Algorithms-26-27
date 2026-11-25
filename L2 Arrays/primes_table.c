#include <stdio.h>
#include <stdlib.h>
#include "primes_gen.h"

int main(int argc, char *argv[]) {
    int step_size;
    if(argc < 2) {
        printf("Usage: %s <step_size> <max_num>\n", argv[0]);
        step_size = 100; // use default so can run debugger easily
    } else {
        step_size = atoi(argv[1]);
    }

    int max_num;
    if(argc < 3) {
        max_num = 1000; // use default so can run debugger easily
    } else {
        max_num = atoi(argv[2]);
    }


    for(int num_primes = step_size; num_primes <= max_num; num_primes += step_size) {
        struct prime_res result = generate_primes(num_primes);
        long time_taken = (long)result.time_taken * 1000 / CLOCKS_PER_SEC;
        printf("%d\t%d\t%ld ms\n", num_primes, result.last_prime, time_taken);
    }
    return 0;
}