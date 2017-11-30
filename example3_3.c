#include <stdio.h>
#include <stdlib.h>

struct node{
  char *data;

  struct node *next;
};

typedef struct node Node;

// head가 지역변수인 경우
// Node *head = NULL;

// void add_first(char *item);
Node* add_first(Node *head, char *item);

void main(void){
  Node *head = NULL;
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
  // add_first("Monday");
  head = add_first(head, "Monday");

  Node *p = head;
  while(p != NULL){
    printf("%s \n", p->data);
    p = p->next;
  }
}

/*
// 원리는 똑같고 이차원 포인터를 이용했을 뿐
void add_first(Node **ptr_head, char *item){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = item;
  temp->next = *ptr_head;
  *ptr_head = temp;
}
*/

Node* add_first(Node *head, char *item){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = item;
  temp->next = head;
  return temp;
}
