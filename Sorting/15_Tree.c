#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the binary search tree.
struct Node
{
    int data;
    struct Node *left, *right;
};

// Creates a new tree node.
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Inserts a value into the binary search tree.
struct Node* insert(struct Node* root, int data)
{
    if(root == NULL)
        return newNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal prints values in sorted order for a BST.
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int x;
    struct Node* root = NULL;

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        // Insert each value into the tree.
        root = insert(root, x);
    }

    printf("Sorted Array: ");
    inorder(root);
    return 0;
}
