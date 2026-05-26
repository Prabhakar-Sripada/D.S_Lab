#include<stdio.h>
#include<stdlib.h>

// Structure for one node of the linked-list queue.
struct node
{
    int data;
    struct node *next;
};

// Front is used for deletion and rear is used for insertion.
struct node *front = NULL;
struct node *rear = NULL;

// Inserts an element at the rear of the queue.
void insert()
{
    struct node *ptr;
    int item;
    
    ptr = (struct node*) malloc (sizeof(struct node));

    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        
        ptr -> data = item;
        ptr -> next = NULL;
        
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
        }
    }
}

// Deletes an element from the front of the queue.
void deleteElement()
{
    struct node *ptr;
    
    if(front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}

// Displays all queue elements from front to rear.
void display()
{
    struct node *ptr;
    ptr = front;
    
    if(front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        while(ptr != NULL)
        {
            printf("\n%d\n",ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main ()
{
    int choice = 0;
    // Menu-driven queue operations.
    while(choice != 4)
    {
        printf("\n****Main Menu****\n");
        printf("\n========================================\n");
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",& choice);
        
        switch(choice)
        {
            case 1:
                insert();
            break;

            case 2:
                deleteElement();
            break;

            case 3:
                display();
            break;

            case 4:
                exit(0);
            break;

            default:
                printf("\nEnter valid choice??\n");
        }
    }
    return 0;
}
