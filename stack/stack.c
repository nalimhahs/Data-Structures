#include <stdio.h>
#define MAX 20

int stack[MAX];

int ptr = -1;

void push()
{
    int i;
    if (ptr >= MAX)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter number: ");
        scanf("%d", &i);
        stack[++ptr] = i;
    }
}

void push_para(int i)
{
    stack[++ptr] = i;
}

int pop()
{
    if (ptr < 0)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        return stack[ptr--];
    }
}

void mth(int m)
{
    if (m - 1 > ptr)
    {
        printf("\nInvalid m!\n");
        return;
    }
    else
    {
        int a[MAX], i = 0, p = ptr;
        while (ptr > p - m)
        {
            a[i] = pop();
            printf("\n%d", a[i]);
            i++;
        }
        p = i;
        for (int i = p - 2; i >= 0; i--)
        {
            push_para(a[i]);
        }
    }
}

void print()
{
    int p = ptr;
    printf("\nStack: ");
    for (int i = p; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main()
{
    int ch, m;
    while (1)
    {
        printf("\nMenu\n1. Push\n2. Pop\n3. Pop m nos\n4. Exit\n\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            push();
            print();
            break;

        case 2:

            pop();
            print();
            break;

        case 3:

            printf("Enter number: ");
            scanf("%d", &m);
            mth(m);
            print();
            break;

        case 4:

            return;

        default:
            printf("\nInvalid Option!!\n");
            break;
        }
    }
}