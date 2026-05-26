#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the binary search tree.
struct node
{
    int data;
    struct node *left, *right;
};

// Creates a new tree node.
struct node* newNode(int x)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

// Inserts a value into the binary search tree.
struct node* insert(struct node* root, int x)
{
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Inorder traversal: Left, Root, Right.
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right.
void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root.
void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node* root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        // Build the tree by inserting each value.
        root = insert(root, x);
    }

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
