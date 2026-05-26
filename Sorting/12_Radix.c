#include <stdio.h>

// Finds the largest element to know the number of digits.
int getMax(int a[], int n)
{
    int max = a[0];

    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

// Sorts the array according to one digit position.
void countingSort(int a[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // Count occurrences of each digit.
    for(int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    // Convert count array into position array.
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array from right to left to keep sorting stable.
    for(int i = n - 1; i >= 0; i--) 
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        a[i] = output[i];
}

// Applies counting sort for every digit position.
void radixSort(int a[], int n)
{
    int max = getMax(a, n);

    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements (positive numbers): ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Sort the input array using radix sort.
    radixSort(a, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
