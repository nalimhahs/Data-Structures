#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int data;
    struct node *lc, *rc;
} node;

node *getNode(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = x;
    new->lc = NULL;
    new->rc = NULL;
    return new;
}

node *stack[MAX];

int top = -1;

void getInitialTree(node *root)
{
    int x;
    printf("Enter data of root node: ");
    scanf("%d", &x);
    root->data = x;
}

int getHeight(node *root)
{
    int l = -1, r = -1;

    if (root->lc == NULL && root->rc == NULL)
        return 1;

    if (root->lc == NULL)
        return getHeight(root->rc) + 1;

    if (root->rc == NULL)
        return getHeight(root->lc) + 1;

    l = getHeight(root->lc);
    r = getHeight(root->rc);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

void push(node *i)
{
    if (top >= MAX)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        stack[++top] = i;
    }
}

node *pop()
{
    if (top < 0)
    {
        printf("\nUnderflow\n");
        return NULL;
    }
    else
    {
        return stack[top--];
    }
}

void printTree(node *root, int space)
{
    if (root == NULL)
        return;

    node *ptr;

    // push(root);
    // while (top != -1)
    // {
    //     ptr = pop();
    //     if (ptr != NULL)
    //     {

    //         push(ptr->rc);
    //         push(ptr->lc);
    //     }
    // }

    ptr = root;
    while (ptr != NULL || top != -1)
    {
        while (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->lc;
        }
        ptr = pop();
        printf(" %d ", ptr->data);
        ptr = ptr->rc;
    }
}

node *search(node *root, int key)
{

    node *l = NULL, *r = NULL, *ptr;
    if (root->data == key)
    {
        return root;
    }

    if (root->lc != NULL)
    {
        l = search(root->lc, key);
    }

    if (root->rc != NULL)
    {
        r = search(root->rc, key);
    }

    if (r != NULL)
    {
        return r;
    }
    else if (l != NULL)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}

void insert(node *root)
{

    int n, temp;
    char ch;
    node *new;
    printf("Enter the key to be appended to: ");
    scanf("%d", &n);
    node *ptr = search(root, n);

    if (ptr == NULL)
    {
        printf("\nNode not found!\n");
    }
    else
    {
        scanf("%c", &ch);
        printf("Left or right? (l/r): ");
        scanf("%c", &ch);

        switch (ch)
        {
        case 'l':
            if (ptr->lc != NULL)
                printf("\nCannot insert!\n");
            else
            {
                printf("\nEnter data: ");
                scanf("%d", &n);
                new = getNode(n);
                ptr->lc = new;
            }
            break;

        case 'r':
            if (ptr->rc != NULL)
                printf("\nCannot insert!\n");
            else
            {
                printf("\nEnter data: ");
                scanf("%d", &n);
                new = getNode(n);
                ptr->rc = new;
            }
            break;

        default:
            printf("\nInvalid option!\n");
            break;
        }
    }
}

int search_parent(node *root, node *ptr, node **parent)
{
    *parent = NULL;

    if (root->lc == ptr)
    {
        *parent = root;
        return -1;
    }
    if (root->rc == ptr)
    {
        *parent = root;
        return 1;
    }

    if (root->lc != NULL)
    {
        search_parent(root->lc, ptr, parent);
    }

    if (root->rc != NULL)
    {
        search_parent(root->rc, ptr, parent);
    }

    return 0;
}

void delete (node *root, int key)
{
    int pos;
    node *ptr = search(root, key), *parent;

    if (ptr == NULL)
    {
        printf("Node not found!\n");
        return;
    }
    else if (ptr->rc != NULL || ptr->lc != NULL)
    {
        printf("The node is not a leaf node!\n");
        return;
    }
    else
    {
        pos = search_parent(root, ptr, &parent);
        if (pos == 1)
        {
            parent->rc = NULL;
            free(ptr);
        }
        if (pos == -1)
        {
            parent->lc = NULL;
            free(ptr);
        }
    }
}

void main()
{
    node *root;
    int ch, i, n;
    char ans = 'y';
    root = getNode(-1);
    int key;

    printf("Enter Initial Tree: \n");
    getInitialTree(root);

    do
    {
        printf("\nMenu\n1. Insert\n2. Delete\n3. Print\n4. Exit\n\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            insert(root);
            break;

        case 2:

            printf("Enter the key to be deleted: ");
            scanf("%d", &n);
            delete(root, n);
            break;

        case 3:

            printTree(root, 0);
            break;

        case 4:

            return;

        default:
            printf("\nInvalid Option!!\n");
            break;
        }

    } while (ans == 'y');
}