#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lft, *rht;
};

int count = 0;
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
    root->lft->rht = create();
    root->lft->rht->info = 50;
    root->rht->lft = create();
    root->rht->lft->info = 60;
    root->rht->rht = create();
    root->rht->rht->info = 70;
}

void display(struct node *root)
{
    if(root != NULL)
    {
        printf("%d \t", root->info);
        display(root->lft);
        display(root->rht);
    }
}

int leaf_no(struct node *root)
{
    if(root == NULL) return 0;
    if(root->lft == NULL && root->rht == NULL) // if(root->lft != NULL && root->rht != NULL) for count of non leaf node
        ++count;
    leaf_no(root->lft);
    leaf_no(root->rht);
    return count;
}

int main()
{
    construct();
    display(root);
    leaf_no(root);
    printf("\n%d", count);
    return 0;
}