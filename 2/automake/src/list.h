#ifndef _LIST_H
#define _LIST_H
struct LinkedList
{
  char data[512]; // строка
  struct LinkedList *next; //ссылка на следующий узел
};
typedef struct LinkedList *node;
node createNode();
node addNode(node head, char value[512]);
node NodeByIndex(int index, node head);
node DelByIndex(int index, node head);
int HowMuchNode(node head);
#endif