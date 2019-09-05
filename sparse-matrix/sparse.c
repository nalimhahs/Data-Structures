#include <stdio.h>

void convertTo3Column(int a[10][10], int m, int n, int b[][3])
{
	int k = 1;
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
}

void transpose(int b[][3], int c[][3])
{
	int k = 1;
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
}

int add(int b[][3], int c[][3], int d[][3])
{
	if (c[0][0] != b[0][0] || c[0][1] != b[0][1])
	{
		return 0;
	}
	int k = 1;
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
				d[k][0] = b[i][0];
				d[k][1] = b[i][1];
				d[k][2] = b[i][2] + c[j][2];
				k++;
				i++;
				j++;
				max--;
			}
		}
	}
	d[0][2] = k - 1;
	return 1;
}

void print3Column(int a[][3])
{
	for (int i = 0; i <= a[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void get3column(int a[][3])
{
	printf("Enter total number of Rows: ");
	scanf("%d", &a[0][0]);
	printf("Enter total number of Columns: ");
	scanf("%d", &a[0][1]);
	printf("Enter total number of Elements: ");
	scanf("%d", &a[0][2]);

	for (int i = 1; i <= a[0][2]; i++)
	{
		printf("Enter row of %d: ", i);
		scanf("%d", &a[i][0]);
		printf("Enter col of %d: ", i);
		scanf("%d", &a[i][1]);
		printf("Enter value of %d: ", i);
		scanf("%d", &a[i][2]);
	}
	printf("The three column matrix entered is: \n");
	print3Column(a);
}

void main()
{
	int a[10][10], m, n, b[100][3], k = 1, c[100][3], d[100][3], ch;

	printf("Menu\n1. Convert to 3 column\n2. Transpose\n3. Add\nEnter Choice: ");
	scanf("%d", &ch);

	switch (ch)
	{
	case 1:
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

		convertTo3Column(a, m, n, b);

		printf("\nRequired Three Column Matrix:\n\n");
		print3Column(b);

		break;

	case 2:
		get3column(b);
		transpose(b, c);
		printf("\nThe transposed matrix is:\n\n");
		print3Column(c);
		break;

	case 3:
		printf("Enter matrix 1:\n");
		get3column(b);
		printf("Enter matrix 2:\n");
		get3column(c);
		if (!add(b, c, d))
		{
			printf("They cannot be added!\n");
			break;
		}
		printf("Sum of the two matrix is: \n\n");
		print3Column(d);
		break;

	default:
		printf("Invalid choice!\n");
		break;
	}
}