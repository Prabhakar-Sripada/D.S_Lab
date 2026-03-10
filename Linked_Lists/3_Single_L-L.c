#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node*next;
};

struct Node *Head = NULL;

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
                printf("Enter the Data: ");
                scanf("%d", &data);

                Insertion_at_Beg(data);
                printf("%d is Inserted at Beggining", data);

                break;
            }

            case 2 :
            {
                printf("Enter the Data: ");
                scanf("%d", &data);

                Insertion_at_End(data);
                printf("%d is Inserted at Ending", data);

                break;
            }

            case 3 :
            {
                printf("Enter the Data & Position: ");
                scanf("%d", &data);

                Insertion_at_Pos(data, pos);
                printf("%d is Inserted at Position %d", data, pos);

                break;
            }

            case 4 :
            {
                Deletion_at_Beg();
                printf("Value Deleted at Beggining");

                break;
            }

            case 5 :
            {
                Deletion_at_End();
                printf("Value Deleted at Ending");

                break;
            }

            case 6 :
            {
                printf("Enter Position to Delete: ");
                scanf("%d", &pos);

                Deletion_at_Pos(pos);
                printf("Value Deleted at Position %d", pos);

                break;
            }

            case 7 :
            {
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