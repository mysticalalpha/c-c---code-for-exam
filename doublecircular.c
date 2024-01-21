#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *lpt, *rpt;
};

struct node *first;

void create()
{
    char ch;
    struct node *ptr, *cpt;
    ptr = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &ptr->info);
    fflush(stdin);
    ptr->lpt = ptr->rpt = ptr;
    first = ptr;
    do
    {
        cpt = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &cpt->info);
        fflush(stdin);
        cpt->lpt = first;
        cpt->rpt = first;
        ptr->rpt = cpt;
        ptr->lpt = cpt;
        printf("enter y to enter more node and e to exit");
        ch = getchar();
    }while(ch == 'Y');
    ptr->rpt = first;
}

void display()
{
    struct node *ptr = first;
    while(ptr->rpt != first)
    {
        printf("%d", ptr->info);
        ptr = ptr->rpt;
    }
    printf("%d", ptr->info);
}

void insert_atbeg()
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &ptr->info);
    fflush(stdin);
    ptr->rpt = first;
    ptr->lpt = first->lpt;
    first->lpt->rpt = ptr;
    first->lpt = ptr;
    first = ptr;
    display();
}

void insert_atend()
{
    struct node *ptr;
    ptr = (struct  node*)malloc(sizeof(struct node));
    scanf("%d", &ptr->info);
    fflush(stdin);
    ptr->lpt = first->lpt;
    ptr->rpt = ptr;
    first->lpt->rpt = ptr;
    first->lpt = ptr;
    display();
}

void insert_afterdata()
{
    int data;
    scanf("%d", &data);
    fflush(stdin);
    struct node *ptr, *cpt;
    ptr = first;
    cpt = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &cpt->info);
    fflush(stdin);
    while(ptr->info != data)
    {
        ptr = ptr->rpt;
    }
    cpt->rpt = ptr->rpt;
    cpt->lpt = ptr;
    ptr->rpt = cpt;
    ptr->rpt->lpt = cpt;
    display();
}

void delete_atbeg()
{
    struct node *ptr = first;
    first->lpt->rpt = first->rpt;
    first->rpt->lpt = first->lpt;
    first = first->rpt;
    free(ptr);
    display();
}

void delete_atend()
{
    struct node *ptr = first->lpt;
    first->lpt = ptr->lpt;
    ptr->lpt->rpt = first;
    free(ptr);
    display();
}

void delete_afterdata()
{
    int data;
    scanf("%d", &data);
    fflush(stdin);
    struct node *ptr = first, *cpt;
    while(ptr->info != data)
    {
        cpt = ptr;
        ptr = ptr->rpt;
    }
    cpt->rpt = ptr->rpt;
    ptr->rpt->rpt = cpt;
    free(ptr);
    display();
}

int main()
{
    create();
    display();
    insert_atbeg();
    //display();
    insert_atend();
    //display();
    insert_afterdata();
    //display();
    delete_atbeg();
    //display();
    delete_atend();
    //display();
    delete_afterdata();
    //display();
    return 0;
}