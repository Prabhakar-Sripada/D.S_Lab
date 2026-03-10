#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;

    struct node *next;
};

struct node *head = NULL;

void push()
{
    int val;

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("Unable to allocate Memory\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the Value: ");
    scanf("%d", &val);

    ptr -> val = val;
    ptr -> next = head;
    head = ptr;

    printf("Item Pushed\n");
}

void pop()
{
    if(head == NULL)
    {
        printf("Underflow\n");

        return;
    }

    struct node *ptr = head;

    printf("Popped Item: %d\n", ptr -> val);

    head = head -> next;

    free(ptr);
}

void display()
{
    struct node *ptr = head;

    if(ptr == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("--Printing Stack Elements--\n");

        while (ptr != NULL)
        {
            printf("%d\n", ptr -> val);
            ptr = ptr -> next;
        }
    }
}

int main()
{
    int choice;

    printf("\n****Stack Operations using ADT****\n");
    printf("\n----------\n");
    
    do
    {
        printf("\n1. Push \n2. Pop \n3. Show \n4. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : display(); break;
            case 4 : printf("Exiting ...\n"); break;

            default : printf("\nERROR: Enter a valid Choic\n");
        }
    }
    while (choice != 4); //Free allocated memory before Exiting

    while (head != NULL)
    {
        pop();
    }

    return 0;
}