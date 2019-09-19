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
    new->link = NULL;
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
        ptr->link = getNode(x);
        temp = ptr->link;
        temp->link = NULL;
        ptr = ptr->link;
        printf("Do you want to add another node?(y/N): ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    } while (ch == 'y');
}

void printLL(node *header)
{
    node *ptr;
    if (header->link == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    ptr = header->link;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

void insertAtFront(node *header)
{
    int x;
    node *new;
    printf("Enter data: ");
    scanf("%d", &x);
    new = getNode(x);
    new->link = header->link;
    header->link = new;
}

void insertAtKey(node *header, int key)
{
    int x;
    node *new, *ptr;
    ptr = header->link;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->link;
    }
    if (ptr->data == key)
    {
        printf("Enter data: ");
        scanf("%d", &x);
        new = getNode(x);
        new->link = ptr->link;
        ptr->link = new;
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
    ptr = header->link;
    while (ptr->link != NULL)
        ptr = ptr->link;

    printf("Enter data: ");
    scanf("%d", &x);
    new = getNode(x);
    ptr->link = new;
}

void deleteAtFront(node *header)
{
    if (header->link == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr;
    ptr = header->link;
    header->link = ptr->link;
    free(ptr);
}

void deleteAtKey(node *header, int key)
{
    if (header->link == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr, *temp;
    ptr = header->link;
    while (ptr->link != NULL && ptr->data != key)
    {
        ptr = ptr->link;
    }
    if (ptr->data == key)
    {
        temp = ptr->link;
        ptr->link = temp->link;
        free(temp);
    }
    else
    {
        printf("Key not found!");
    }
}

void deleteAtEnd(node *header)
{
    if (header->link == NULL)
    {
        printf("\nNo elements in linked list!\n");
        return;
    }
    node *ptr, *temp;
    temp = header;
    ptr = header->link;
    while (ptr->link != NULL)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr->link  ;
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