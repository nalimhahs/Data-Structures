#include <stdio.h>

void prettyPrint(int a[20][20], int m, int n)
{
  printf("\nMatrix is: \n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}

void main()
{
  int a[20][20], m, n, b[20][20];

  printf("Enter the number of rows: ");
  scanf("%d", &m);
  printf("Enter the number of columns: ");
  scanf("%d", &n);

  printf("Enter the elements: \n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  prettyPrint(a, m, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      b[i][m - j -1] = a[j][i];
    }
  }

  prettyPrint(b, n, m);
}
