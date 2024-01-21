#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *lft, *rht;
};
struct node *root, *ptr;

struct node *create()
{
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->lft = NULL;
    ptr->rht = NULL;
    return ptr;
}

void construct()
{
    root = create();
    root->info = 10;
    root->lft = create();
    root->lft->info = 20;
    root->rht = create();
    root->rht->info = 30;
    root->lft->lft = create();
    root->lft->lft->info = 40;
}

void display(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->info);   // print the data of the node
        display(root->lft);  // display the first child of the node
        display(root->rht); // display the next sibling of the node
    }
}

int height(struct node *root)
{
    int lheight, rheight;
    if(root == NULL) return 0;
    lheight = height(root->lft);
    rheight = height(root->rht);
    
    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

int main()
{
    construct();
    display(root);
    int a = height(root);
    printf("\n%d",a);
    return 0;
}