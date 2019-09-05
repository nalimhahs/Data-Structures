#include <stdio.h>

void main()
{
	int a[10][10], m, n, b[100][3], k = 1, c[100][3], d[100][3];

	printf("Enter rows and columns: ");
	scanf("%d%d", &m, &n);

	printf("Enter Values: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Matrix you entered: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				k++;
			}
		}
	}

	b[0][0] = m;
	b[0][1] = n;
	b[0][2] = k - 1;

	printf("Three Column Matrix\n");
	for (int i = 0; i <= b[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}

	printf("Transpose is:\n");
	k = 1;
	c[0][0] = b[0][0];
	c[0][1] = b[0][1];
	c[0][2] = b[0][2];

	for (int i = 0; i < b[0][1]; i++)
	{
		for (int j = 1; j <= b[0][2]; j++)
		{
			if (b[j][1] == i)
			{
				c[k][1] = b[j][0];
				c[k][0] = b[j][1];
				c[k][2] = b[j][2];
				k++;
			}
		}
	}

	printf("Transpose: \n");
	for (int i = 0; i <= c[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}

	k = 0;
	int i = 0;
	int j = 0;
	while (k < b[0][2] + c[0][2])
	{
		
	}
	
}