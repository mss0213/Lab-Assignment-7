#include <stdio.h>

/* This code was written by Michael Schlosbon on 3/8/2024. The purpose was to compare the amount of swaps that Selection Sort and Bubble could make when sorting an array of numbers. */

void bubbleSort(int arr[], int n, int swaps[], int *totalSwaps) {
    int i, j, temp; // Create our variables used for our loops.
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[], int *totalSwaps) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps[arr[i]]++;
            swaps[arr[min_index]]++;
            (*totalSwaps)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1copy[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2copy[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[101] = {0}; // Since the values in the array are from 1 to 100
    int swaps2[101] = {0};
    int swaps3[101] = {0};
    int swaps4[101] = {0};
    int total_swaps1 = 0;
    int total_swaps2 = 0;
    int total_swaps3 = 0;
    int total_swaps4 = 0;
    
    // Bubble Sort
    printf("Using Bubble Sort: \n\n");
    bubbleSort(array1, n1, swaps1, &total_swaps1);
    bubbleSort(array2, n2, swaps2, &total_swaps2);

    // Output for array1
    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d times\n", array1[i], swaps1[array1[i]]);
    }
   
    printf("Total swaps: %d\n\n", total_swaps1);

    // Output for array2
    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d times\n", array2[i], swaps2[array2[i]]);
    }
  
  printf("Total swaps: %d\n\n", total_swaps2);
  printf("Using Selection Sort: \n");
  selectionSort(array1copy, n1, swaps3, &total_swaps3);
  selectionSort(array2copy, n2, swaps4, &total_swaps4);

  // Output for array1
  printf("\narray1:\n");
  for (int i = 0; i < n1; i++) {
      printf("%d: %d times\n", array1copy[i], swaps3[array1copy[i]]);
  }

  printf("Total swaps: %d\n\n", total_swaps3);

  // Output for array2
  printf("array2:\n");
  for (int i = 0; i < n2; i++) {
      printf("%d: %d times\n", array2copy[i], swaps4[array2copy[i]]);
  }

  printf("Total swaps: %d\n", total_swaps4);

    return 0;
}
