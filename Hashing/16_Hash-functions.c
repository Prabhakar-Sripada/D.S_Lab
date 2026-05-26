#include <stdio.h>
#include <stdlib.h>

int divisionHash(int key, int size)
{
    int hash = key % size;
    return hash < 0 ? hash + size : hash;
}

int multiplicationHash(int key, int size)
{
    double product = (key < 0 ? -(double)key : key) * 0.6180339887;
    return (int)(size * (product - (int)product));
}

int midSquareHash(int key, int size)
{
    long n = key < 0 ? -(long)key : key;
    long square = n * n;
    int digits = 0;

    for (long temp = square; temp > 0; temp /= 10)
        digits++;

    for (int i = 0; i < (digits - 2) / 2; i++)
        square /= 10;

    return (square % 100) % size;
}

int getHash(int key, int size, int method)
{
    switch (method) {
        case 1: return divisionHash(key, size);
        case 2: return multiplicationHash(key, size);
        default: return midSquareHash(key, size);
    }
}

void showComparison(int keys[], int count, int size)
{
    printf("\nKey\tDivision\tMultiplication\tMid-Square\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", keys[i],
               divisionHash(keys[i], size),
               multiplicationHash(keys[i], size),
               midSquareHash(keys[i], size));
    }
}

void clearTable(int table[], int size)
{
    for (int i = 0; i < size; i++)
        table[i] = -1;
}

void insertKeys(int table[], int keys[], int count, int size, int method)
{
    clearTable(table, size);

    for (int i = 0; i < count; i++) {
        int index = getHash(keys[i], size, method);
        if (table[index] == -1) {
            table[index] = keys[i];
            printf("%d inserted at index %d\n", keys[i], index);
        } else {
            printf("Collision at index %d: %d skipped\n", index, keys[i]);
        }
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < size; i++)
        table[i] == -1 ? printf("%2d: Empty\n", i) : printf("%2d: %d\n", i, table[i]);
}

int main(void)
{
    int size, count, choice;

    printf("Enter hash table size: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid table size.\n");
        return 1;
    }

    printf("Enter number of keys: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid key count.\n");
        return 1;
    }

    int *table = malloc(size * sizeof(int));
    int *keys = malloc(count * sizeof(int));
    if (table == NULL || keys == NULL) {
        printf("Memory allocation failed.\n");
        free(table);
        free(keys);
        return 1;
    }

    printf("Enter %d keys: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &keys[i]) != 1) {
            printf("Invalid input.\n");
            free(table);
            free(keys);
            return 1;
        }
    }

    while (1) {
        printf("\n1.Division  2.Multiplication  3.Mid-Square  4.Compare  5.Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
                insertKeys(table, keys, count, size, choice);
                break;
            case 4:
                showComparison(keys, count, size);
                break;
            case 5:
                free(keys);
                free(table);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    free(keys);
    free(table);
    return 0;
}
