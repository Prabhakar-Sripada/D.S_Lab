#include <stdio.h>
#include <stdlib.h>

// Division method: hash value is found using key % table size.
int divisionHash(int key, int size)
{
    key = abs(key);
    return key % size;
}

// Multiplication method: uses a constant value between 0 and 1.
int multiplicationHash(int key, int size)
{
    float A = 0.618033f;

    key = abs(key);
    float value = key * A;
    float fraction = value - (int)value;

    return (int)(size * fraction);
}

// Mid-square method: squares the key and extracts middle digits.
int midSquareHash(int key, int size)
{
    key = abs(key);
    int square = key * key;
    int middle = (square / 10) % 100;

    return middle % size;
}

// Calls the selected hash function according to the user's choice.
int getHashValue(int key, int size, int choice)
{
    switch (choice)
    {
        case 1:
            return divisionHash(key, size);

        case 2:
            return multiplicationHash(key, size);

        case 3:
            return midSquareHash(key, size);

        default:
            return -1;
    }
}

// Displays hash index for every key using the selected method.
void displayResult(int keys[], int n, int size, int choice)
{
    int i, index;

    printf("\nKey\tHash Index\n");

    for (i = 0; i < n; i++)
    {
        index = getHashValue(keys[i], size, choice);
        printf("%d\t%d\n", keys[i], index);
    }
}

// Reads all keys from the user.
int inputKeys(int keys[], int n)
{
    int i;

    printf("Enter keys:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);
    }

    return 1;
}

// Displays the menu of available hash methods.
void displayMenu()
{
    printf("\n1. Division Method");
    printf("\n2. Multiplication Method");
    printf("\n3. Mid-Square Method");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

int main()
{
    int *keys;
    int n, size, choice;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    printf("Enter number of keys: ");
    scanf("%d", &n);

    if (size <= 0 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Dynamic memory allocation for storing keys.
    keys = (int *)malloc(n * sizeof(int));

    if (keys == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    inputKeys(keys, n);

    // Repeats until the user chooses to exit.
    do
    {
        displayMenu();
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3)
        {
            displayResult(keys, n, size, choice);
        }
        else if (choice != 4)
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    free(keys);
    return 0;
}
