#include <time.h>
#include <stdlib.h>
struct prime_res {
    time_t time_taken;
    unsigned int last_prime;
};

struct prime_res generate_primes(int num_primes);
