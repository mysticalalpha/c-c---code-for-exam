#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lft, *rht;
};
int flag = 0;
struct node *root = NULL;

struct node *create(int data)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->lft = NULL;
    ptr->rht = NULL;
    ptr->info = data;
    return ptr;
}

void search(struct node *ptr, int data)
{
    //int flag = 0;
    if(ptr == NULL){
        printf("tree don't exist");
        return;
    }
    else{
        if(ptr->info == data){
            flag = 1; return;
            
        }
        if (flag == 0 && ptr->lft != NULL){
            search(ptr->lft, data);
        }
        if (flag == 0 && ptr->rht != NULL)
        {
            search(ptr->rht, data);
        } // Added semicolon to resolve error
    }
}

void postorder(struct node *ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->lft);
        postorder(ptr->rht);
        printf("%d ", ptr->info);
    }
}

int main()
{
    root = create(10);
    root->lft = create(20);
    root->rht = create(30);
    root->lft->lft = create(50);
     search(root, 30);
    if(flag)
        printf("search is success full\n");
    else
        printf("search is unsuccess full\n");
    postorder(root);
    
    return 0;
}