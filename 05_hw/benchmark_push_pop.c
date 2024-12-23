#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

// Функция для проведения бенчмарков push
void benchmark_push(Stack* stack, size_t test_size) {
    clock_t start = clock();
    for (size_t i = 0; i < test_size; i++) {
        push(stack, (int)i);
    }
    clock_t end = clock();
    printf("Push %zu: %.6f seconds\n", test_size, (double)(end - start) / CLOCKS_PER_SEC);
}

// Функция для проведения бенчмарков pop
void benchmark_pop(Stack* stack, size_t test_size) {
    clock_t start = clock();
    for (size_t i = 0; i < test_size; i++) {
        pop(stack);
    }
    clock_t end = clock();
    printf("Pop %zu: %.6f seconds\n", test_size, (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    Stack stack;
    initStack(&stack);

    // Массив с разными объемами данных
    size_t test_sizes[] = { 1000000, 10000000 };

    for (int i = 0; i < 3; i++) {
        size_t test_size = test_sizes[i];

        // Benchmark push
        benchmark_push(&stack, test_size);

        // Refill stack for pop benchmark
        for (size_t j = 0; j < test_size; j++) {
            push(&stack, (int)j);
        }

        // Benchmark pop
        benchmark_pop(&stack, test_size);
    }

    destroyStack(&stack);
    return 0;
}
