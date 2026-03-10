//Stacks using Arrays

#include <stdio.h>
#include <stdlib.h>

int stack[100];
int size;
int top = -1;

void push() //Function to insert into stack
{
    if (top == size-1)
        printf("\nStack overflows");
    else
    {
        top++;

        printf("Enter Stack Element: \n");
        scanf("%d", &stack[top]);

    }
}

void pop() //Function to delete from stack
{
    int temp;

    if(top == -1)
        printf("Stack underflows");
    else
    {
        temp = stack[top];

        top--;

        printf("\nDeleted Element: %d", temp);
    }
}

void display() //Function to Display values in stack
{
    int i;

    if (top == -1)
        printf("\nStack is empty");
    else
    {
        printf("\nStack elements: ");

        for(i = 0; i <= top; i++)
            printf("%d\t", stack[i]);
    }
}

void top_of_the_stack() //To display top value of Stack
{
    if (top == -1)
        printf("Stack is empty");
    else
        printf("Top of the Stack: %d", stack[top]);
}

void is_empty() //To check if Stack is empty or not
{
    if (top == -1)
        printf("Stack is empty");
    else
        printf("Stack is not empty");
}


int main()
{
    int opt;

    printf("Enter size of Stack: ");
    scanf("%d", &size);

    printf("\n1. Push \n2. Pop \n3. Top of the Stack \n4. is Empty \n5. Display \n6. Exit");

    while(1)
    {
        printf("\nEnter your option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1: push(); break;

            case 2: pop(); break;

            case 3: top_of_the_stack(); break;

            case 4: is_empty(); break;

            case 5: display(); break;

            case 6: exit(1); break;

            default: printf("\nInvalid Option\n");
        }
    }

    return 0;
}