#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lht, *rht;
};
struct node *root, *ptr;

struct node *create_node(int data)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->lht = NULL;
    ptr->rht = NULL;
    return ptr;
}

void create_tree()
{
    root = create_node(10);                // create root node with data 1
    root->lht = create_node(20);           // create first child of root with data 2
    root->lht->rht = create_node(30);      // create next sibling of first child with data 3
    root->lht->rht->rht = create_node(40); // create next sibling of second child with data 4
    root->lht->lht = create_node(50);      // create first child of first child with data 5
    root->lht->lht->rht = create_node(60); // create next sibling of first child’s first child with data 6
}

void display(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // print the data of the node
        display(root->lht);        // display the first child of the node
        display(root->rht);        // display the next sibling of the node
    }
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    int lheight = height(root->lht);
    int rheight = height(root->rht);

    if (lheight > rheight)
        return lheight + 1;
    else
        return rheight + 1;
}

int main()
{
    create_tree();
    display(root);
    int a = height(root);
    printf("\n%d", a);
    return 0;
}