#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *getNode(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = x;
    return new;
}

void getCircularLL(node *header)
{
    int x;
    char ch;
    node *ptr, *temp;
    ptr = header;
    do
    {
        printf("Enter data: ");
        scanf("%d", &x);
        ptr->link = getNode(x);
        temp = ptr->link;
        temp->link = header;
        ptr = ptr->link;
        printf("Do you want to add another node?(y/N): ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    } while (ch == 'y');
}

void printCircularLL(node *header)
{
    node *ptr;
    ptr = header->link;
    while (ptr != header)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

void mergeCircularLL(node *header1, node *header2)
{
    node *ptr;
    ptr = header1->link;
    while (ptr->link != header1)
    {
        ptr = ptr->link;
    }
    ptr->link = header2->link;
    ptr = ptr->link;
    while (ptr->link != header2)
    {
        ptr = ptr->link;
    }
    ptr->link = header1;
    free(header2);
}

void main()
{
    node *header1, *header2;
    header1 = getNode(-1);
    header2 = getNode(-1);
    printf("\nEnter values into the first circular linked list: \n");
    getCircularLL(header1);
    printCircularLL(header1);
    printf("\nEnter values into the second circular linked list: \n");
    getCircularLL(header2);
    printCircularLL(header2);
    printf("\nMerged circular linked list is: \n");
    mergeCircularLL(header1, header2);
    printCircularLL(header1);
}