/*
Programa que gerencia uma lista encadeada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

int primeiro = 0;

struct Node {
  char name[50];
  struct Node *next;
};

struct Node* newNode(char* name){
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  strcpy(node->name, name);
  node->next = NULL;
  return node;
}

void append(struct Node** head_ref, char* name){
  // Remover qualquer nova linha (\n) do final do nome
  name[strcspn(name, "\n")] = 0;

  struct Node* new_node = newNode(name);
  struct Node *last = *head_ref;

  if (*head_ref == NULL){
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void mergeLists(struct Node** list1, struct Node* list2){
  if (*list1 == NULL){
    *list1 = list2;
    return;
  }

  struct Node* last = *list1;
  while (last->next != NULL){
    last = last->next;
  }
  last->next = list2;
}

void mergeFound(struct Node** found, struct Node* list1, struct Node* list2){
  if (primeiro == 1){
    //primeiro = 1;
    mergeLists(&list2, list1);
    return;
  }
  struct Node* last = *found;
  struct Node* rest = last->next;
  last->next = list2;
  while (list2->next != NULL){
    list2 = list2->next;
  }
  list2->next = rest;
}

struct Node* findNode(struct Node* head, char* name){
  struct Node* prior = head;
  int count = 0;
  while(head != NULL){
    //head = head->next;
    if (strcmp(head->name, name) == 0){
      //printf("%s %s" , head->name, name);
      head = prior;
      if(!count) primeiro = 1;
      else if (count == 1) primeiro = 2;
      return head;
    }
    prior = head;
    head = head->next;
    count++;
  }
  return NULL;
}

void printList(struct Node *node){
  while (node != NULL){
    printf("%s", node->name);
    if (node->next != NULL) // Se não for o último nó, imprime um espaço
      printf(" ");
    node = node->next;
  }
  printf("\n"); // Imprime uma nova linha no final da lista
}

int main(void){
  char line[500], line2[500], name[50];
  char *token;

  struct Node* head = NULL;
  struct Node* head2 = NULL;

  fgets(line, sizeof(line), stdin);
  //line[strcspn(line, "\n")] = 0;
  fgets(line2, sizeof(line), stdin);
  //line[strcspn(line2, "\n")] = 0;
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;

  token = strtok(line, " ");
  while(token != NULL){
    append(&head, token);
    token = strtok(NULL, " ");
  }
  token = strtok(line2, " ");
  while(token != NULL){
    append(&head2, token);
    token = strtok(NULL, " ");
  }
  struct Node* foundNode = findNode(head, name);
  if (foundNode != NULL){
    mergeFound(&(foundNode), head, head2);
  } else if(strcmp(name, "nao") == 0){
    mergeLists(&head, head2);
  }

  (!primeiro || primeiro == 2) ? printList(head) : printList(head2);

  return 0;
}
