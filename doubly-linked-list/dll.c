#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *rlink, *llink;
} node;

node *getNode(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = x;
    new->rlink = NULL;
    new->llink = NULL;
    return new;
}

void getInitialLL(node *header)
{
    int x;
    char ch;
    node *ptr, *temp;
    ptr = header;
    do
    {
        printf("Enter data: ");
        scanf("%d", &x);
        ptr->rlink = getNode(x);
        temp = ptr->rlink;
        temp->rlink = NULL;
        temp->llink = ptr;
        ptr = ptr->rlink;
        printf("Do you want to add another node?(y/N): ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    } while (ch == 'y');
}

void printLL(node *header)
{
    node *ptr;
    if (header->rlink == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    ptr = header->rlink;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->rlink;
    }
}

void insertAtFront(node *header)
{
    int x;
    node *new;
    printf("Enter data: ");
    scanf("%d", &x);
    new = getNode(x);
    new->rlink = header->rlink;
    new->llink = header;
    header->rlink = new;
}

void insertAtKey(node *header, int key)
{
    int x;
    node *new, *ptr;
    ptr = header->rlink;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->rlink;
    }
    if (ptr->data == key)
    {
        printf("Enter data: ");
        scanf("%d", &x);
        new = getNode(x);
        new->rlink = ptr->rlink;
        new->llink = ptr;
        ptr->rlink = new;
    }
    else
    {
        printf("Key not found!");
    }
}

void insertAtEnd(node *header)
{
    int x;
    node *new, *ptr;
    ptr = header->rlink;
    while (ptr->rlink != NULL)
        ptr = ptr->rlink;

    printf("Enter data: ");
    scanf("%d", &x);
    new = getNode(x);
    new->llink = ptr;
    ptr->rlink = new;
}

void deleteAtFront(node *header)
{
    if (header->rlink == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr;
    ptr = header->rlink;
    header->rlink = ptr->rlink;
    ptr = ptr->rlink;
    ptr->llink = header;
    ptr = ptr->llink;
    free(ptr);
}

void deleteAtKey(node *header, int key)
{
    if (header->rlink == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr, *temp, *temp2;
    ptr = header->rlink;
    while (ptr->rlink != NULL && ptr->data != key)
    {
        ptr = ptr->rlink;
    }
    if (ptr->data == key)
    {
        temp = ptr->rlink;
        if (ptr->rlink == NULL)
        {
            return;
        }
        else if (temp->rlink == NULL)
        {
            return;
        }
        ptr->rlink = temp->rlink;
        temp = temp->rlink;
        temp->llink = ptr;
        // ptr = ptr->rlink;
        // free(temp2);
    }
    else
    {
        printf("Key not found!");
    }
}

void deleteAtEnd(node *header)
{
    if (header->rlink == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr, *temp;
    temp = header;
    ptr = header->rlink;
    while (ptr->rlink != NULL)
    {
        temp = ptr;
        ptr = ptr->rlink;
    }
    temp->rlink = ptr->rlink;
    free(ptr);
}

void main()
{
    node *header;
    int ch, i;
    char ans = 'y';
    header = getNode(-1);
    int key;

    printf("Enter Initial linked list: \n");
    getInitialLL(header);

    do
    {
        printf("\nMenu\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("\nEnter method\n1. Beginning\n2. After key\n3. At the end\n\nEnter Choice: ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                insertAtFront(header);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                insertAtKey(header, key);
                break;

            case 3:
                insertAtEnd(header);
                break;

            default:
                printf("\nInvalid Option!!\n");
                break;
            }
            printLL(header);
            break;

        case 2:

            printf("\nEnter method\n1. Beginning\n2. After key\n3. At the end\n\nEnter Choice: ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                deleteAtFront(header);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAtKey(header, key);
                break;

            case 3:
                deleteAtEnd(header);
                break;

            default:
                printf("\nInvalid Option!!\n");
                break;
            }
            printLL(header);
            break;

        case 3:

            printLL(header);
            break;

        case 4:

            return;

        default:
            printf("\nInvalid Option!!\n");
            break;
        }

    } while (ans == 'y');
}