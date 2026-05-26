#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the binary search tree.
struct node
{
    int data;
    struct node *left, *right;
};

// Creates a new tree node with left and right child as NULL.
struct node* createNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Inserts a value into the binary search tree using recursion.
struct node* insert(struct node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

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
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        // Each value is inserted into the tree one by one.
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);                                              

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
