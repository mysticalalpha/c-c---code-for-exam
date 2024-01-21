#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
}; // added a semicolon here
struct node *front, *rear;

void insert(int data)
{
    if (rear == NULL)
    {
        //printf("underflow"); // removed this line as it is not correct to print underflow when the queue is empty
        rear = (struct node*)malloc(sizeof(struct node));
        rear->info = data;
        rear->next = NULL;
        front = rear;
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = data;
        temp->next = NULL; // added this line to make the next pointer of the new node NULL
        rear->next = temp;
        rear = rear->next;
    }
}

void delete()
{
    struct node *temp;
    temp = front;
    if (front == NULL) // added this condition to check if the queue is empty
    {
        printf("underflow");
    }
    else if (front == rear) // added this condition to check if the queue has only one element
    {
        front = rear = NULL;
        free(temp);
    }
    else // added this else block to delete the front element of the queue
    {
        front = front->next;
        free(temp);
    }
}

void display() // added this function to display the queue elements
{
    struct node *temp;
    temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

int main()
{
    int data[] = {10, 20, 30, 40, 50}; // changed data from a single variable to an array of five elements
    for (int i = 0; i < 5; i++) // added this loop to insert all the elements of the array into the queue
    {
        insert(data[i]);
    }
    
    delete(); // this will delete 10 from the queue
    display(); // this will display the queue elements
    return 0;
}
