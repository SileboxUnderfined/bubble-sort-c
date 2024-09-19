#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int rand_max, length;

    printf("Enter max random integer: ");
    scanf("%d", &rand_max);
    printf("Enter array length: ");
    scanf("%d", &length);

    int* numbers = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % rand_max + 1;
    }

    printf("Initial array: ");
    print_array(numbers, length);

    clock_t start_time = clock();
    int count = sort(numbers, length);
    clock_t end_time = clock();

    double result_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    print_array(numbers, length);

    printf("Count of iterations: %d\n", count);
    printf("The array was sorted in %f ms", result_time);

    free(numbers);

    return 0;
}

int sort(int* numbers, int length) {
    unsigned char is_sorted = 0;

    int counter = 0;
    while (is_sorted == 0) {
        is_sorted = 1;
        for (int i = 0; i < length - 1; i++) {
            if (numbers[i] > numbers[i+1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                
                is_sorted = 0;
            }
        }

        length--;
        counter++;
    }

    return counter;
}

void print_array(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}