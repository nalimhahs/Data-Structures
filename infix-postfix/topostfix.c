#include <stdio.h>
#include <string.h>

#define MAX 20

char stack[MAX];

int top = -1;

void push(char c)
{
    if (top >= MAX)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        stack[++top] = c;
    }
}

char pop()
{
    if (top < 0)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void print()
{
    int p = top;
    printf("\nStack: ");
    for (int i = p; i >= 0; i--)
    {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int getPriority(char c)
{
    switch (c)
    {
    case '^':
        return 4;
    case '*':
        return 3;
    case '/':
        return 3;
    case '+':
        return 2;
    case '-':
        return 2;
    default:
        return 0;
    }
}

void main()
{
    int len, k = -1;

    char s[MAX], post[MAX], temp;

    printf("Enter the infix expression: ");
    scanf("%s", s);

    len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        switch (s[i])
        {

        case '(':
            push(s[i]);
            break;

        case ')':
            temp = pop();
            while (temp != '(')
            {
                post[++k] = temp;
                temp = pop();
            }
            break;

        case '^':

            while (getPriority(stack[top]) >= 4)
            {
                post[++k] = pop();
            }

            push(s[i]);
            break;

        case '*':

            while (getPriority(stack[top]) >= 3)
            {
                post[++k] = pop();
            }

            push(s[i]);
            break;

        case '/':

            while (getPriority(stack[top]) >= 3)
            {
                post[++k] = pop();
            }

            push(s[i]);
            break;

        case '+':

            while (getPriority(stack[top]) >= 2)
            {
                post[++k] = pop();
            }

            push(s[i]);
            break;

        case '-':

            while (getPriority(stack[top]) >= 2)
            {
                post[++k] = pop();
            }

            push(s[i]);
            break;

        default:
            post[++k] = s[i];
            break;
        }
    }

    while (top > -1)
        post[++k] = pop();

    post[++k] = '\0';
    printf("\nPostfix exp: %s\n", post);
}