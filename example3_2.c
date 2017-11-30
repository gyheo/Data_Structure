#include <stdio.h>
#include <stdlib.h>

struct node{
  char *data;

  struct node *next;
};

typedef struct node Node;
Node *head = NULL;

void add_first(char *item);

void main(void){
  head = (Node*)malloc(sizeof(Node));
  head->data = "Tuesday";
  head->next = NULL;

  Node *q = (Node*)malloc(sizeof(Node));
  q->data = "Thursday";
  q->next = NULL;
  head->next = q;

  // q = (Node*)malloc(sizeof(Node));
  // q->data = "Monday";
  // q->next = head;
  // head = q;
  add_first("Monday");

  Node *p = head;
  while(p != NULL){
    printf("%s \n", p->data);
    p = p->next;
  }
}

void add_first(char *item){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = item;
  temp->next = head;
  head = temp;
}
