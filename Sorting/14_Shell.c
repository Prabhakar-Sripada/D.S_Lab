#include <stdio.h>
void shellSort(int a[], int n) {
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j-gap] > temp; j -= gap) {
                a[j] = a[j-gap];
            }
            a[j] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    shellSort(a, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
