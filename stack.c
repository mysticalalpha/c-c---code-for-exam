#include<stdio.h>
#include<stdlib.h> // added this header file to use malloc and free functions

struct node{
    int info;
    struct node *next;
};
struct node *top;

void create(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = NULL;
    top = temp; // assigned temp to top instead of NULL
}

void push(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = top;
    top = temp;
}

void delet()
{
    if(top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *temp;
        //temp = (struct node*)malloc(sizeof(struct node)); // removed this line as it is not needed
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display() // added this function to display the stack elements
{
    struct node *temp;
    temp = top;
    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

int main()
{
    int data[] = {10,20,30,40,50};
    create(*data); // this will create a stack with 10 as the only element
    push(*(data+1)); // this will push 20 on top of the stack
    push(*(data+2)); // this will push 30 on top of the stack
    push(*(data+3));
    delet(); // this will delete 30 from the stack
    display(); // this will display the stack elements
    return 0;
}
