#include <stdio.h>
#include <stdlib.h>

int queue[20], size;
int front = -1, rear = -1;

void enqueue()
{
    int ele;

    if(rear == size - 1)
        printf("Queue overflows");
    else
    {
        printf("\nEnter element into Queue: ");
        scanf("%d", &ele);

        if(rear == -1)
        {
            front++;
            rear++;
            queue[rear] = ele;
        }
    }
}

void dequeue()
{
    if(front == -1)
        printf("Queue underflows");
    else
    {
        printf("Deleting element: %d", queue[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
    }
}

void display()
{
    int temp;

    if(front == -1)
        printf("Queue is empty");
    else
    {
        for(temp = front; temp <= rear; temp++)
            printf("%d\t", queue[temp]);
    }
}

int main()
{
    int option;

    printf("\nEnter Queue Size: ");
    scanf("%d", &size);

    printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");

    while(1)
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1 : enqueue(); break;

            case 2 : dequeue(); break;

            case 3 : display(); break;

            case 4 : exit(1); break;

            default : printf("ERROR: Enter a Valid Option.");
        }
    }

    return 0;
}