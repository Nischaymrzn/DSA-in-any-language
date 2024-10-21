#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int n)
{
    int i;
    // Find the maximum and minimum values in the array
    int max = arr[0], min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    // Calculate the range of elements
    int range = max - min + 1;

    // Allocate memory for the count and output arrays
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Store the count of each element
    for (i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    // Modify the count array such that each element stores the sum of previous counts
    for (i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted elements into the original array
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    free(count);
    free(output);
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
