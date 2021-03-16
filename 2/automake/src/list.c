#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct LinkedList *node;

node createNode()
{
    node temp; // объявлкние узла
    temp = (node)malloc(sizeof(struct LinkedList)); // выделение памяти
    temp->next = NULL;// следующее значение
    return temp;// возвращаем новый узел
}

node addNode(node head, char value[512])
{
    node temp, p;// объявляем два узла
    temp = createNode(); // делаем из первого узел
    strcpy(temp->data, value); // добавляем данные
    if(head == NULL){
        head = temp;     //если список пуст то этот элемент станет верхним
    }
    else{
        p = head;// замена верхнего
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

node NodeByIndex(int index, node head)
{
  node n = head;
  for(size_t i = 0; i < index; i++){
    n = n->next;
  }
  return n;
}

node DelByIndex(int index, node head)
{
  if (index <= 0) return head;
  if (index == 1 && head->next != NULL) return head->next;
  NodeByIndex(index-1, head)->next = NodeByIndex(index+1, head);
  //free(NodeByIndex(index, head));
  return head;
}

int HowMuchNode(node head){
  if (head->next == NULL) return 0;
  int i = 0;
  while(head->next != NULL){
    head = head->next;
    i++;
  }
  return i;
}