#include <stdlib.h>
#include "linkedlist.h"

Node* head = NULL;

void listInit(int val)
{
    head = malloc(sizeof(Node));
    if (head == NULL)
        return;
    head->value = val;
    head->next = NULL;
}

void insertFirst(int val)
{
    Node* newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void insertLast(int val)
{
    Node* newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return;
    newNode->value = val;
    newNode->next = NULL;
    Node* temp = head;
    Node* tempPrev = NULL;
    while (temp != NULL)
    {
        tempPrev = temp;
        temp = temp->next;
    }
    if (temp != head)
    {
        temp = newNode;
        tempPrev->next = newNode;
    }
    else
    {
        head = newNode;
    }
}

void insertAt(int val, int index)
{
    Node* newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return;
    newNode->value = val;
    
    Node* temp = head;
    Node* tempPrev = NULL;
    for (int i = 0; i < index; i++)
    {
        if (temp == NULL)
            return;
        tempPrev = temp;
        temp = temp->next;
    }
    
    newNode->next = temp;
    if (tempPrev != NULL)
        tempPrev->next = newNode;
    else
        head = newNode;
}

void deleteFirst()
{
    if (head == NULL)
        return;
    free(head);
    head = head->next;
}

void deleteLast()
{
    if (head == NULL)
        return;
    Node* last = head;
    Node* lastPrev = NULL;
    while (last->next != NULL)
    {
        lastPrev = last;
        last = last->next;
    }
    if (last != head)
    {
        lastPrev->next = NULL;
        free(last);
    }
    else
    {
        deleteFirst();
    }
}

void deleteAt(int index)
{
    if (head == NULL)
        return;
    Node* temp = head;
    Node* tempPrev = NULL;
    for (int i = 0; i < index; i++)
    {
        if (temp == NULL)
            return;
        tempPrev = temp;
        temp = temp->next;
    }
    if (temp != head)
    {
        tempPrev->next = temp->next;
        free(temp);
    }
    else
    {
        deleteFirst();
    }
}

void sortList()
{
    if (head == NULL)
        return;
    Node* curr = head;
    Node* iter = NULL;
    while (curr != NULL)
    {
        iter = curr->next;
        while (iter != NULL)
        {
            if (curr->value > iter->value)
            {
                int temp = curr->value;
                curr->value = iter->value;
                iter->value = temp;
            }
            iter = iter->next;
        }
        curr = curr->next;
    }
}
