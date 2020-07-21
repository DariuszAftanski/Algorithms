#include <stdio.h>
#include <stdlib.h>
#define ARRAY_LENGTH 20
#define RANDOM_RANGE 100


void Insertion_Sort(int * array, int lenght) {
    for (int i = 1; i < lenght; i++) {
        int key = array[i];

        // Insert array[i] into the sorted sequence.
        int j = i - 1; // Do not touch the selected element.
        while ((j >= 0) && (array[j] > key)) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main(void) {

    int array[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = rand() % RANDOM_RANGE;
        printf("%d \t", array[i]);
    }
    printf("\n");

    Insertion_Sort(array, ARRAY_LENGTH);
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d \t", array[i]);
    }
    printf("\n");
    return 0;
}