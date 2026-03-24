#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
};

int height(struct node *n)
{
    if (n == NULL) return 0;
    return n -> height;
}

int max(int a, int b)
{
    return(a > b) ? a : b;
}

struct node* newNode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));

    n -> data = data;
    n -> left = n -> right = NULL;
    n -> height = 1;
    return n;
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y -> left;
    y -> left = x -> right;
    x -> right = y;

    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x -> right;
    x -> right = y -> left;
    y -> left = x;

    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;

    return y;
}

int getBalance(struct node* n)
{
    if(n == NULL) return 0;
    return height(n -> left) - height(n -> right);
}

struct node* insert(struct node* root, int key)
{
    if(root == NULL)
        return newNode(key);
    
    if (key < root -> data)
        root -> left = insert(root -> left, key);
    else
        root -> right = insert(root -> right, key);

    root -> height = max(height(root -> left), height(root -> right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && key < root -> left -> data)
        return rightRotate(root);

    if(balance < -1 && key > root -> right -> data)
        return leftRotate(root);

    if(balance > 1 && key > root -> right -> data)
    {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }

    if(balance < -1 && key < root -> right -> data)
    {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct node* root)
{
    if(root)
    {
        inorder(root -> left);
        printf("%d", root -> data);
        inorder(root -> right);
    }
}

void preorder(struct node* root)
{
    if(root)
    {
        printf("%d", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(struct node* root)
{
    if(root)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d", root -> data);
    }
}

int main()
{
    struct node* root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    while (n--)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}