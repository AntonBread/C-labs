#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int value;
    Node* next;
};

void listInit(int val);

void insertFirst(int val);
void insertLast(int val);
void insertAt(int val, int index);

void deleteFirst();
void deleteLast();
void deleteAt(int index);

void sortList();

#endif
