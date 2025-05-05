#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool* eratosten (int x)
{
    bool* seive = (bool*) malloc(sizeof(bool) * (x+1));
    memset (seive, false, sizeof (bool) * (x+1));
    for (int i = 2; i <= x; i++ )
    {
        if (!seive[i])
        {
            for (int j = i + i; j <= x; j += i)
            {
                seive [j] = true;
            }
        }
    }
    return seive;

}

void print_primes(bool* sieve, int x) {
    for (int i = 2; i <= x; i++) {
        if (!sieve[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);

    bool* sieve = eratosten(x);
    print_primes(sieve, x);

    free(sieve); 
    return EXIT_SUCCESS;
}
