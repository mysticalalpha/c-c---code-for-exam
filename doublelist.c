#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lpt, *rpt;
};

struct node *first;
void display();

void create()
{
    char ch;
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &ptr->info);
    fflush(stdin);
    ptr->lpt = ptr->rpt = NULL;
    first = ptr;
    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &cpt->info);
        fflush(stdin);
        ptr->rpt = cpt;
        cpt->lpt = ptr;
        cpt->rpt = NULL;
        printf("enter y to enter more node and e to exit");
        ch = getchar();
    } while (ch == 'Y');
    ptr->rpt = NULL;
}

void display()
{
    struct node *ptr = first;
    while (ptr != NULL)
    {
        printf("%d", ptr->info);
        ptr = ptr->rpt;
    }
}

void insert_atbeg()
{
    printf("insert at begining");
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &ptr->info);
    fflush(stdin);
    ptr->lpt = NULL;
    ptr->rpt = first;
    first = ptr;
    display();
}

void insert_atend()
{
    printf("insert at end");
    struct node *ptr, *cpt;
    ptr = first;
    cpt = (struct node *)malloc(sizeof(struct node));
    cpt->rpt = NULL;
    scanf("%d", &cpt->info);
    fflush(stdin);
    while (ptr->rpt != NULL)
    {
        ptr = ptr->rpt;
    }
    cpt->lpt = ptr;
    ptr->rpt = cpt;
    display();
}

void insert_afterdata()
{
    printf("insert after data you will enter");
    int data;
    scanf("%d", &data);
    fflush(stdin);
    struct node *ptr, *cpt;
    ptr = first;
    cpt = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &cpt->info);
    fflush(stdin);
    while (ptr->info != data)
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
    printf("deletion of begining node");
    struct node *ptr = first;
    first->rpt->lpt = NULL;
    first = first->rpt;
    free(ptr);
    display();
}

void delete_atend()
{
    printf("deletion of last node");
    struct node *ptr, *cpt;
    ptr = first;
    while (ptr->rpt != NULL)
    {
        cpt = ptr;
        ptr = ptr->rpt;
    }
    cpt->rpt = NULL;
    free(ptr);
    display();
}

void delete_afterdata()
{
    printf("deletion of node after data you will enter");
    int data;
    scanf("%d", &data);
    fflush(stdin);
    struct node *ptr = first, *cpt;
    while (ptr->info != data)
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
    // display();
    insert_atend();
    // display();
    insert_afterdata();
    // display();
    delete_atbeg();
    // display();
    delete_atend();
    // display();
    delete_afterdata();
    // display();
    return 0;
}