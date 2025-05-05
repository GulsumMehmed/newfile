#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Функция за намиране на прости числа до x чрез алгоритъма на Ератостен
bool* eratosthenes(int x) {
    bool* sieve = (bool*) malloc((x + 1) * sizeof(bool));
    if (!sieve) {
        printf("Грешка при заделяне на памет.\n");
        exit(EXIT_FAILURE);
    }

    // Инициализиране на всички елементи като "не е маркирано"
    memset(sieve, false, (x + 1) * sizeof(bool));

    // От 2 до корен квадратен от x
    for (int i = 2; i * i <= x; i++) {
        if (!sieve[i]) {
            // Маркиране на кратните на i
            for (int j = i * i; j <= x; j += i) {
                sieve[j] = true;
            }
        }
    }

    return sieve;
}

// Функция за отпечатване на простите числа
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
    printf("Въведете число: ");
    scanf("%d", &x);

    bool* sieve = eratosthenes(x);
    printf("Прости числа до %d:\n", x);
    print_primes(sieve, x);

    free(sieve); // Освобождаване на заделената памет
    return 0;
}
