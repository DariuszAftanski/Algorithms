// Merge_Sort Algorithm
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10       // Size of the array used in testing.
#define INFINITY 999        // The greatest value allowed in the array.

void merge(int * array, int opening_index, int division_point, int closing_index) {
    // Calculate the length of each sub-array:
    const int length_left = (division_point + 1) - opening_index;
    const int length_right = closing_index - division_point;

    // Extend the size of sub-array by one, to fit an extra INFINITY key:
    int left_array[length_left + 1];
    int right_array[length_right + 1];

    // Create temporary arrays to hold keys from sorted sub-arrays:
    for (int i = 0; i < length_left; i++)   { left_array[i] = array[opening_index + i]; }
    for (int j = 0; j < length_right; j++)  { right_array[j] = array[(division_point + 1) + j]; }
    
    // Append the INFINITY key to each of the temporary arrays:
        // It is easier to have a key that's greater than any other key...
        // ... than to check if we reached the end of array.
    left_array[length_left] = INFINITY;
    right_array[length_right] = INFINITY;

    // Merge the temporary arrays:
    int i = 0;      // Initialise index of left_array (temporary array).
    int j = 0;      // Initialise index of right_array (temporary array).

    // Merging:
    for (int k = opening_index; k <= closing_index; k++) {
        // Pick the lesser key from the temp.arrays:
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];           // Assign lesser key to the main array.
            i++;                                // Move past the "used" key (left_array).
        }
        else {
            array[k] = right_array[j];          // Assign lesser key to the main array.
            j++;                                // Move past the "used" key (right_array).
        } 
    }
}


void merge_sort(int * array, int opening_index, int closing_index) {
    if (closing_index > opening_index) {

        // Find the middle-point in the array.
        int division_point = (opening_index + closing_index) / 2;

        // Apply the algorithm recursively on the sub-arrays:
            // Left sub-array:
            merge_sort(array, opening_index, division_point );
            // Right sub-array:
            merge_sort(array, division_point + 1, closing_index);

        // Put the sub-arrays together, while sorting them
        merge(array, opening_index, division_point, closing_index);
    }
}

int main(void) {
    // Initialise an array with size defined at the top of the text-file.
    int array[ARRAY_SIZE];
    
    printf("\nThe original list of numbers is:\n");
    
    // Initialise the array with pseudo-random numbers:
    for (int i = 0; i < (ARRAY_SIZE - 1); i++) {
        array[i] = rand() % INFINITY; 
        printf("%d \t", array[i]);      // Display the unsorted array.
    }

    // Execute the merge-sort algorithm:
    merge_sort(array, 0, ARRAY_SIZE-1);

    printf("\nThe sorted list of numbers is:\n");
    for (int i = 0; i < (ARRAY_SIZE - 1); i++) {
        printf("%d \t", array[i]);      // Display the sorted array.
    }

    printf("\n \n");

    return 0;
}