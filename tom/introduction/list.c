#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[])
{
    printf("Start...\n");
    DoublyLinkedList myList = {0, 0};
 
    Node nodeA;
    nodeA.value = "A";
    insertBeginning(myList, &nodeA);
    myList.firstNode = &nodeA;
    myList.lastNode = &nodeA;
    printf("List after insertBeginning\n");
    printList(myList);

    Node nodeC;
    nodeC.value = "C";
    insertAfter(myList, &nodeA, &nodeC);
    printf("List after insertAfter\n");
    printList(myList);

    Node nodeB;
    nodeB.value = "B";
    insertBefore(myList, &nodeC, &nodeB);
    printf("List after insertBefore\n");
    printList(myList);

    Node* findB = findInList(myList, "B");
    printf("findB=%s\n", findB->value);

    removeFromList(myList, &nodeB);
    printf("List after remove\n");
    printList(myList);
    
    return 0;
}