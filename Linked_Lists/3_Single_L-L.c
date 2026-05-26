#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the singly linked list.
struct Node
{
    int data;

    struct Node*next;
};

// Head stores the address of the first node.
struct Node *Head = NULL;

// Inserts a new node at the end of the list.
void Insertion_at_End(int data)
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode -> data = data;
    newnode -> next = NULL;

    if(Head == NULL)
        Head = newnode;
    else
    {
        temp = Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newnode;
    }
}

// Inserts a new node at the beginning of the list.
void Insertion_at_Beg(int data)
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode -> data = data;
    newnode -> next = NULL;

    if(Head == NULL)
        Head = newnode;
    else
    {
        newnode -> next = Head;
        Head = newnode;
    }
}

// Inserts a new node at the given position.
void Insertion_at_Pos(int data, int pos)
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode -> data = data;
    newnode -> next = NULL;

    while(pos - 2)
    {
        temp = temp -> next;

        pos--;
    }

    newnode -> next = newnode;
}

// Deletes the last node from the list.
void Deletion_at_End()
{
    struct Node *temp, *delnode;

    temp = Head;

    if(Head == NULL)
        printf("No node to delete");
    else if(Head -> next == NULL)
    {
        delnode = Head;
        Head = NULL;
        free(delnode);
    }
    else
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delnode = temp -> next;
        temp -> next = NULL;
        free(delnode);
    }
}

// Deletes the first node from the list.
void Deletion_at_Beg()
{
    struct Node *delnode;

    if(Head == NULL)
        printf("No node to delete");
    else if(Head -> next == NULL)
    {
        delnode = Head;
        Head = NULL;
        free(delnode);
    }
    else
    {
        delnode = Head;
        Head = Head -> next;
        free(delnode);
    }
}

// Deletes a node from the given position.
void Deletion_at_Pos(int pos)
{
    struct Node *temp, *delnode;

    temp = Head;

    while(pos - 2)
    {
        temp = temp -> next;
        pos--;
    }

    delnode = temp -> next;
    temp -> next = temp -> next -> next;
    free(delnode);
}

// Displays all nodes from first to last.
void Display()
{
    struct Node *temp;

    temp = Head;

    while(temp -> next != NULL)
    {
        printf("%d===>", temp -> data);
        temp = temp -> next;
    }

    printf("%d\n", temp -> data);
}

int main()
{
    int n, data, pos;

    printf("\n--Enter the number beside to Operate--\n");
    printf("1. Insert at Beggining\n 2. Insert at Ending\n 3. Insert at Position\n 4. Delete at Beggining\n 5. Delete at Ending\n 6. Delete at Position\n 7. Display");
    printf("\n--Enter '-1' to Exit--\n");

    printf("Enter you Choice: ");
    scanf("%d", &n);

    while(n != -1)
    {
        switch (n)
        {
            case 1 :
            {
                // Insert at beginning.
                printf("Enter the Data: ");
                scanf("%d", &data);

                Insertion_at_Beg(data);
                printf("%d is Inserted at Beggining", data);

                break;
            }

            case 2 :
            {
                // Insert at end.
                printf("Enter the Data: ");
                scanf("%d", &data);

                Insertion_at_End(data);
                printf("%d is Inserted at Ending", data);

                break;
            }

            case 3 :
            {
                // Insert at a specific position.
                printf("Enter the Data & Position: ");
                scanf("%d", &data);

                Insertion_at_Pos(data, pos);
                printf("%d is Inserted at Position %d", data, pos);

                break;
            }

            case 4 :
            {
                // Delete from beginning.
                Deletion_at_Beg();
                printf("Value Deleted at Beggining");

                break;
            }

            case 5 :
            {
                // Delete from end.
                Deletion_at_End();
                printf("Value Deleted at Ending");

                break;
            }

            case 6 :
            {
                // Delete from a specific position.
                printf("Enter Position to Delete: ");
                scanf("%d", &pos);

                Deletion_at_Pos(pos);
                printf("Value Deleted at Position %d", pos);

                break;
            }

            case 7 :
            {
                // Display current linked list.
                printf("The Linked List is: \n");

                Display();

                break;
            }

            default :
            {
                printf("ERROR: Invalid Input");

                break;
            }
        }

        printf("\n\nEnter your Choice: ");
        scanf("%d", &n);
    }

    printf("\n--Program Terminated--\n");

    return 0;
}
