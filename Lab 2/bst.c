#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *p = root;

    struct Node *t, *f = NULL; // f->follow or tail pointer
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t; // root becomes the new node
        return;
    }
    while (p)
    {
        f = p;
        if (key == p->data)
        {
            return; // when key is found don't return anything
        }
        else if (key < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    // when key is not found or p becomes NULL it will come out of the loop,make a new node and link it with follow pointer
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (key < f->data)
    {
        f->lchild = t;
    }
    else
    {
        f->rchild = t;
    }
}

int inOrder(struct Node *p)
{
    if (p != NULL)
    {
        inOrder(p->lchild);
        printf("%d  ", p->data);
        inOrder(p->rchild);
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    inOrder(root);
}