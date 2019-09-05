#include <stdio.h>

void main()
{
    int a[20], n, k, pairs[10][2], count = 0;
    printf("Enter elements in array: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);

    int closest = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;

            if (a[i] + a[j] > closest && a[i] + a[j] <= k)
            {
                count = 0;
                closest = a[i] + a[j];
                pairs[count][0] = a[i];
                pairs[count][1] = a[j];
            }
            else if (a[i] + a[j] == closest && a[i] + a[j] <= k)
            {
                pairs[count][0] = a[i];
                pairs[count][1] = a[j];
                count++;
            }
        }
    }
    printf("Closest pairs are: \n");
    for (int i = 0; i < count; i++)
    {
        printf("Pair %d: %d, %d \n", i+1, pairs[i][0], pairs[i][1]);
    }
    
}