#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the AVL tree.
struct node {
    int data, height;
    struct node *left, *right;
};

// Returns height of a node, or 0 if node is NULL.
int height(struct node *n) { return n ? n->height : 0; }

// Returns the greater of two values.
int max(int a, int b) { return a > b ? a : b; }

// Creates a new AVL tree node.
struct node* newNode(int data) {
    struct node* n = malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// Performs right rotation to balance the AVL tree.
struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Performs left rotation to balance the AVL tree.
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Balance factor = height of left subtree - height of right subtree.
int getBalance(struct node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Inserts a value and rebalances the AVL tree if required.
struct node* insert(struct node* root, int key) {
    if (!root) return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    // Left-left and right-right cases.
    if (balance > 1 && key < root->left->data) return rightRotate(root);
    if (balance < -1 && key > root->right->data) return leftRotate(root);

    // Left-right case.
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-left case.
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal: Left, Root, Right.
void inorder(struct node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: Root, Left, Right.
void preorder(struct node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left, Right, Root.
void postorder(struct node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    while (n--)
    {
        scanf("%d", &x);
        // Insert and balance after every value.
        root = insert(root, x);
    }

    printf("\nInorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);

    return 0;
}
