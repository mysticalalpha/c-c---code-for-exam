#include <stdio.h>
#include <stdlib.h> // for malloc function

struct node
{
  int info;
  struct node *link;
};

struct node *first;
void display();

void create()
{
  struct node *ptr, *cpt;
  char ch; // declare ch as char type
  ptr = (struct node *)malloc(sizeof(struct node));
  //printf("Enter the first Node");
  scanf("%d", &ptr->info);
  fflush(stdin);
  ptr->link = NULL;
  first = ptr;
  do
  {
    cpt = (struct node *)malloc(sizeof(struct node));
    //printf("Enter the second node");
    fflush(stdin);
    scanf("%d", &cpt->info);
    fflush(stdin);
    ptr->link = cpt;
    ptr = cpt; // update ptr to point to cpt
    printf("pass Y for more node and E for exit\n");
    ch = getchar();// use getchar instead of getch10
    fflush(stdin);
  } while(ch == 'Y');
  ptr->link = NULL;
}

void display()
{
  struct node *ptr;
  ptr = first;
  while (ptr != NULL)
  {
    printf("%d ", ptr->info);
    ptr = ptr->link;
  }
  printf("\n");
}

void insert_atbeg()
{
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &ptr->info);
  ptr->link = first;
  first = ptr;
  display();
}

void insert_atend()
{
  struct node *ptr, *cpt;
  ptr = first;
  cpt = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &cpt->info);
  cpt->link = NULL;
  while (ptr->link != NULL)
  {
    ptr = ptr->link;
  }
  ptr->link = cpt;
  display();
}

void insert_afterdata()
{
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
    ptr = ptr->link;
  }
  cpt->link = ptr->link;
  ptr->link = cpt;
  display();
}

void delete_begnode()
{
  struct node *ptr;
  ptr = first;
  first = first->link;
  free(ptr);
  display();
}

void delete_endnode()
{
  struct node *ptr, *cpt = first; // using singlr pointer;
  while (cpt->link != NULL)       // while(cpt->link->link != NUll);
  {
    ptr = cpt; // cpt = cpt->link;
    cpt = cpt->link;
  }
  ptr->link = NULL; // free(cpt->link);
  free(cpt);        // ptr->link = NULL;
  display();
}

void delete_afterdata()
{
  int data;
  scanf("%d", &data);
  fflush(stdin);
  struct node *ptr, *cpt = first;
  while (cpt->info != data)
  {
    ptr = cpt;
    cpt = cpt->link;
  }
  ptr->link = cpt->link;
  free(cpt);
  display();
} 

int main() // display function is used after every function because after every function list value are changing
{
  create();
  display();
  insert_atbeg();
  //display();
  insert_atend();
  //display();
  insert_afterdata();
  //display();
  delete_begnode();
  //display();
  delete_endnode();
  //display();
  delete_afterdata();
  //display();
  return 0;
}
