// Shell_sort: Sort an array of numbers array[0]...array[n-1] into increasing order
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 6 // Length of the tested array:

void shell_sort(int * array, int length) {
    // There are three nested loops in this algorithm.
    int temp_var;

    // First for loop controls the gap between the compared elements:
    for (int gap = length/2; gap > 0; gap /= 2) {
        // Second for loop steps along the elements:
        for (int i = gap; i < length; i++) {
            // Third for loop compares each pair of elements that is seperated...
            // ... and reverse any out of order.
            for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
                temp_var = array[j];
                array[j] = array[j + gap];
                array[j + gap] = temp_var;
            }
        }
    }
}

int main(void) {
    // Declare an array:
    int array_integers[LENGTH];

    // Populate the array:
    for (int i = 0; i < LENGTH; i++) {
        array_integers[i] = rand() % 100;
        printf("%d \t", array_integers[i]);
    }
    printf("\n");

    // Apply the sorting algorithm:
    shell_sort(array_integers, LENGTH);

    // Display the sorted array:
    for (int i = 0; i < LENGTH; i++) {
        printf("%d \t", array_integers[i]);
    }  
    printf("\n");

    return 0;
}