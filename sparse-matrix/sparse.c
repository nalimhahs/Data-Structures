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

	k = 1;
	int i = 1;
	int j = 1;
	d[0][0] = b[0][0];
	d[0][1] = b[0][1];
	int max = b[0][2] + c[0][2];
	while (k <= max)
	{
		if (b[i][0] < c[j][0] && i <= b[0][2])
		{
			d[k][0] = b[i][0];
			d[k][1] = b[i][1];
			d[k][2] = b[i][2];
			i++;
			k++;
		}
		else if (b[i][0] > c[j][0] && j <= c[0][2])
		{
			d[k][0] = c[j][0];
			d[k][1] = c[j][1];
			d[k][2] = c[j][2];
			k++;
			j++;
		}
		else
		{
			if (b[i][1] < c[j][1] && i <= b[0][2])
			{
				d[k][0] = b[i][0];
				d[k][1] = b[i][1];
				d[k][2] = b[i][2];
				i++;
				k++;
			}
			else if (b[i][1] > c[j][1] && j <= c[0][2])
			{
				d[k][0] = c[j][0];
				d[k][1] = c[j][1];
				d[k][2] = c[j][2];
				k++;
				j++;
			}
			else
			{
				d[k][0] = b[i][0] + c[j][0];
				d[k][1] = b[i][1] + c[j][1];
				d[k][2] = b[i][2] + c[j][2];
				k++;
				i++;
				j++;
				max--;
			}
		}
	}
	d[0][2] = k-1;
	printf("Sum: \n");
	for (int i = 0; i <= d[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
}