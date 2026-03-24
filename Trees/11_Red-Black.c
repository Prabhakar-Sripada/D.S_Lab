#include <stdio.h>
#include <stdlib.h>

enum color { RED, BLACK };

struct node
{
    int data;
    int color;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* newNode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->color = RED;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void fixColor()
{
    if (root != NULL)
        root->color = BLACK;
}

void inorder(struct node* root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d(%c) ", root->data,
               root->color == RED ? 'R' : 'B');
        inorder(root->right);
    }
}

int main()
{
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    while (n--)
    {
        scanf("%d", &x);
        root = insert(root, x);
        fixColor();   /* Keep root black */
    }

    printf("\nInorder Traversal (with color): ");
    inorder(root);

    return 0;
}