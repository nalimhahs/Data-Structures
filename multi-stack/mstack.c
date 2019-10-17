#include <stdio.h>
#define MAX 30

int stack[MAX];
int sub_count = 1;
int ptr[MAX];

void init(){
    printf("Enter number of stacks: ");
    scanf("%d", &sub_count);
    for (int i = 0; i < sub_count; i++)
    {
        ptr[i] = -1;
    }
}

void push(int m)
{
    int i, val;
    if (ptr[m] >= MAX/sub_count)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        printf("Enter number: ");
        scanf("%d", &i);
        ptr[m]++;
        val = m*MAX/sub_count + ptr[m];
        stack[val] = i;
    }
}

int pop(int m)
{
    if (ptr[m] < 0)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        return stack[m*MAX/sub_count + --ptr[m]];
    }
}

void print(int m)
{
    printf("\nStack %d: ", m);
    for (int i = ptr[m] + m*MAX/sub_count; i >=  m*MAX/sub_count; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void print_all(){
    for (int i = 0; i < sub_count; i++)
    {
        print(i);
    }
}

void main()
{
    int ch, m;
    init();
    while (1)
    {
        printf("\nMenu\n1. Push\n2. Pop\n3. Exit\n\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("Enter stack number: ");
            scanf("%d", &m);
            if(m >= sub_count || m < 0){
                printf("Invalid stack no!");
                break;
            }
            push(m);
            // print(m);
            break;

        case 2:

            printf("Enter stack number: ");
            scanf("%d", &m);
            if(m >= sub_count || m < 0){
                printf("Invalid stack no!");
                break;
            }
            pop(m);
            // print(m);
            break;

        case 3:

            return;

        default:
            printf("\nInvalid Option!!\n");
            break;
        }
        print_all();
    }
}