#include <stdio.h>
#include <stdlib.h>

// Structure for one node of the doubly linked list.
struct Node {
    int data;
    struct Node *prev, *next;
};

// Head stores the address of the first node.
struct Node *Head = NULL;

// Creates a new node with previous and next links as NULL.
struct Node* create(int data) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

// Insertions
// Inserts a new node at the beginning.
void insertBeg(int data) {
    struct Node *n = create(data);
    if (Head) Head->prev = n, n->next = Head;
    Head = n;
}

// Inserts a new node at the end.
void insertEnd(int data) {
    struct Node *n = create(data), *t = Head;
    if (!Head) { Head = n; return; }
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

// Inserts a new node after reaching the given position.
void insertPos(int data, int pos) {
    struct Node *n = create(data), *t = Head;
    for (int i = 1; i < pos-1 && t; i++) t = t->next;
    if (!t) return;
    n->next = t->next;
    if (t->next) t->next->prev = n;
    t->next = n; n->prev = t;
}

// Deletions
// Deletes the first node.
void deleteBeg() {
    if (!Head) return;
    struct Node *t = Head;
    Head = Head->next;
    if (Head) Head->prev = NULL;
    free(t);
}

// Deletes the last node.
void deleteEnd() {
    if (!Head) return;
    struct Node *t = Head;
    while (t->next) t = t->next;
    if (t->prev) t->prev->next = NULL;
    else Head = NULL;
    free(t);
}

// Deletes the node at the given position.
void deletePos(int pos) {
    struct Node *t = Head;
    for (int i = 1; i < pos && t; i++) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else Head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

// Display
// Displays the list from first node to last node.
void display() {
    for (struct Node *t = Head; t; t = t->next)
        printf("%d <-> ", t->data);
    printf("NULL\n");
}

// Main
int main() {
    int ch, data, pos;
    while (1) {
        // Menu repeats until the user enters -1.
        printf("\n1.Beg 2.End 3.Pos 4.DelBeg 5.DelEnd 6.DelPos 7.Show -1.Exit\n");
        scanf("%d", &ch);
        if (ch == -1) break;

        if (ch <= 3) {
            printf("Enter data: "); scanf("%d", &data);
        }
        if (ch == 3 || ch == 6) {
            printf("Enter position: "); scanf("%d", &pos);
        }

        switch (ch) {
            case 1: insertBeg(data); break;
            case 2: insertEnd(data); break;
            case 3: insertPos(data, pos); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: deletePos(pos); break;
            case 7: display(); break;
            default: printf("Invalid\n");
        }
    }
    return 0;
}
