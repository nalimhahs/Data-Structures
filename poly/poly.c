#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int exponent, coeff;
    struct node *link;
} node;

node *getNode(int exp, int coeff)
{
    node *new = (node *)malloc(sizeof(node));
    new->exponent = exp;
    new->coeff = coeff;
    new->link = NULL;
    return new;
}

void getPoly(node *header)
{
    int exp, coeff;
    node *new, *ptr;
    char ch;
    ptr = header;
    do
    {
        // Assuming the user enters the data in decreasing order of power

        printf("\nEnter exponent of X: ");
        scanf("%d", &exp);
        printf("\nEnter coefficent of X: ");
        scanf("%d", &coeff);
        new = getNode(exp, coeff);
        ptr->link = new;
        ptr = ptr->link;
        printf("\nDo you want to add a new node?(y/N): ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

// Creates a copy of the given node
node *copyNode(node *n)
{
    node *new = getNode(n->exponent, n->coeff);
    new->link = NULL;
    return new;
}

node *polyAdd(node *poly1, node *poly2, node *poly3)
{
    node *ptr1, *ptr2, *ptr3;

    ptr1 = poly1->link;
    ptr2 = poly2->link;
    ptr3 = poly3;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent > ptr2->exponent)
        {
            ptr3->link = copyNode(ptr1);
            ptr3 = ptr3->link;
            ptr1 = ptr1->link;
        }
        else if (ptr2->exponent > ptr1->exponent)
        {
            ptr3->link = copyNode(ptr2);
            ptr3 = ptr3->link;
            ptr2 = ptr2->link;
        }
        else
        {
            ptr3->link = copyNode(ptr2);
            ptr3 = ptr3->link;
            ptr3->coeff = ptr1->coeff + ptr2->coeff;
            ptr2 = ptr2->link;
            ptr1 = ptr1->link;
        }
    }

    // Adding the remaining elements (if any) in poly 1
    while (ptr1 != NULL)
    {
        ptr3->link = ptr1;
        ptr3 = ptr3->link;
        ptr1 = ptr1->link;
    }

    // Adding the remaining elements (if any) in poly 2
    while (ptr2 != NULL)
    {
        ptr3->link = ptr2;
        ptr3 = ptr3->link;
        ptr2 = ptr2->link;
    }

    return poly3;
}

void printPoly(node *poly)
{
    node *ptr = poly->link;
    while (ptr != NULL)
    {
        printf("%dX^%d + ", ptr->coeff, ptr->exponent);
        ptr = ptr->link;
    }
    printf("\n");
}

void main()
{
    node *poly1 = getNode(-1, -1), *poly2 = getNode(-1, -1), *poly3 = getNode(-1, -1);
    printf("\nEnter polynomial 1: ");
    getPoly(poly1);
    printPoly(poly1);
    printf("\nEnter polynomial 2: ");
    getPoly(poly2);
    printPoly(poly2);
    polyAdd(poly1, poly2, poly3);
    printf("Final polynomial: ");
    printPoly(poly3);
}