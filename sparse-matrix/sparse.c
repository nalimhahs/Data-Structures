#include <stdio.h>

void convertTo3Column(int a[10][10], int m, int n, int b[][3]){
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

void transpose(int b[][3], int c[][3]){
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

int add(int b[][3], int c[][3], int d[][3]){
	if(c[0][0] != b[0][0] || c[0][1] != b[0][1]){
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
	return 1;
}

void print3Column(int a[][3]){
	for (int i = 0; i <= a[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

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

	convertTo3Column(a, m, n, b);

	printf("Three Column Matrix\n");
	print3Column(b);

	transpose(b, c);

	printf("Transpose: \n");
	print3Column(c);

	if(add(b, c, d)){
		printf("They cannot be added!\n");
		return;
	}
	
	printf("Sum: \n");
	print3Column(d);
}