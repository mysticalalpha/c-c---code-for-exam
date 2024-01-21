#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root, *ptr;

struct node *create_node()
{
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void construct()
{
    root = create_node();
    root->data = 100;
    root->left = create_node();
    root->left->data = 50;
    root->right = create_node();
    root->right->data = 200;
    root->left->left = create_node();
    root->left->left->data = 40;
    root->left->right = create_node();
    root->left->right->data= 60;
}

void display(struct node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d\n", root->data);
        display(root->right);
        //printf("%d\n", root->data);
    }
}

int main()
{
    construct();
    display(root);
    // root = create_node();
    return 0;
}