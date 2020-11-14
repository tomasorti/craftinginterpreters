#ifndef LIST_INCLUDED
#define LIST_INCLUDED
#include <stdio.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    char* value;
};

typedef struct DoublyLinkedList DoublyLinkedList;
struct DoublyLinkedList {
    Node* firstNode;
    Node* lastNode;
};

void insertAfter(DoublyLinkedList list, Node* node, Node* newNode)
{
    newNode->prev = node;
    if (node->next == 0) {
        newNode->next= 0;
        list.lastNode = newNode;
    } else {
        newNode->next = node->next;
        node->next->prev = newNode;
    }
    node->next = newNode;
}

void insertBefore(DoublyLinkedList list, Node* node, Node* newNode) 
{
    newNode->next = node;
    if (node->prev == 0) {
        newNode->prev = 0;
        list.firstNode = newNode;
    } else {
        newNode->prev = node->prev;
        node->prev->next = newNode;
    }
    node->prev = newNode;
}

void insertBeginning(DoublyLinkedList list, Node* newNode) 
{
    if (list.firstNode == 0) {
        list.firstNode = newNode;
        list.lastNode = newNode;
        newNode->prev = 0;
        newNode->next = 0;
    } else {
        insertBefore(list, list.firstNode, newNode);
    }
}

void insertEnd(DoublyLinkedList list, Node* newNode)
{
    if (list.lastNode == 0){
        insertBeginning(list, newNode);
    } else {
        insertAfter(list, list.lastNode, newNode);
    }
}

void printList(DoublyLinkedList list) 
{
    Node* node = list.firstNode;
    while (node != 0) {
        printf("(node: %s) <-> ", node->value);
        node = node->next;
    }
    printf("\n");
}

Node* findInList(DoublyLinkedList list, const char* str) 
{
    Node* node = list.firstNode;
    while (node != 0) {
        if (!strcmp(str, node->value))
            return node;
        node = node->next;
    }
    return 0;
}

void removeFromList(DoublyLinkedList list, Node* node)
{
    if (node->prev == 0) {
        list.firstNode = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == 0) {
        list.lastNode = node->prev;
    } else {
        node->next->prev = node->prev;
    }
} 
#endif