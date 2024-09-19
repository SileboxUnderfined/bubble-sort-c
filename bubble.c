#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int rand_max, length;

    printf("Введите максимальное рандомное число которое может выпасть: ");
    scanf("%d", &rand_max);
    printf("Введите размер массива: ");
    scanf("%d", &length);

    int* numbers = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % rand_max + 1;
    }

    printf("Массив - ");
    print_array(numbers, length);
    sort(numbers, length);
    printf("Отсортированный массив - ");
    print_array(numbers, length);

    free(numbers);

    return 0;
}

void sort(int* numbers, int length) {
    unsigned char is_sorted = 0;
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
    }
}

void print_array(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}