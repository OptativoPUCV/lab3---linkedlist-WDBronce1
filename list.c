#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
//Ejercicio 1 ####################################
List * createList() 
{
  List* lista = (List *)malloc(sizeof(List));
  lista -> head = NULL;
  lista -> tail = NULL;
  lista -> current = NULL;
  return lista;
}

//Ejercicio 2 ####################################
void * firstList(List * list) 
{
  if(list == NULL || list->head == NULL)
  {
    return NULL;
  }
  while(list->current->prev != NULL)
  {
    list->current = list->current->prev;
  }
  list -> head = list->current;
  return list->current->data;
}

void * nextList(List * list) 
{
  if(list == NULL || list->current == NULL || list->current->next == NULL)
  {
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}

//Ejercicio 3 ####################################
void * lastList(List * list) 
{
  if(list == NULL || list->tail == NULL)
  {
    return NULL;
  }
  while(list->current->next != NULL)
  {
    list->current = list->current->next;
  }
  list -> tail = list->current;
  return list->current->data;
}

void * prevList(List * list) 
{
  if(list == NULL || list->current == NULL || list->current->prev == NULL)
  {
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}

//Ejercicio 4 ####################################
void pushFront(List * list, void * data) 
{
  if(list == NULL)
  {
    return;
  }
  list -> current = list -> head;
  Node * NuevoNodo = createNode(data);
  if(list -> head == NULL)
  {
    list -> head = NuevoNodo;
  }
  else
  {
    NuevoNodo -> next = list -> head;
    list -> head -> prev = NuevoNodo;
    list -> head = NuevoNodo;
  }
}
//###############################################
void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

//Ejercicio 5 ####################################
void pushCurrent(List * list, void * data) 
{
  if(list == NULL || list->current == NULL)
  {
    return;
  }
  Node * NuevoNodo = createNode(data);
  NuevoNodo -> prev = list -> current;
  NuevoNodo -> next = list -> current -> next;
  list -> current -> next = NuevoNodo;
  if(NuevoNodo -> next != NULL)
  {
    NuevoNodo -> next -> prev = NuevoNodo;
  }
  else
  {
    list -> tail = NuevoNodo;
  }
}
//#############################################
void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

//Ejercicio 6 ####################################
void * popCurrent(List * list) 
{
  if (list == NULL || list->current == NULL)
  {
    return NULL;
  }
  Node * NodoEliminado = list->current;
  if(list->current->prev != NULL)
  {
    list->current->prev->next = list->current->next;
  }
  else
  {
    list->head = list->current->next;
    
  }
  list->current -> next ->prev = list ->current->prev;
  list->current -> next = NULL;
  list->current -> prev = NULL;
  return NodoEliminado->data;
}

//############################################
void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}