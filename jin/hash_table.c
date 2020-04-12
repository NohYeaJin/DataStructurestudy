#include <stdio.h>
#include <stdlib.h>

int		h_func(int x, int M)
{
	return (x % M);
}

void	table_init(int *table, int M)
{
	int i;
	
	i = -1;
	while (++i < M)
		table[i] = -1;
}

void	print_table(int	*table, int M)
{
	int i;
	
	i = -1;
	while (++i < M)
		if (table[i] > 0)
			printf("%d ", table[i]);
	printf("\n");
}

int		main(void)
{
	int 	M;
	int 	*table;
	int		num;
	char	input;
	
	scanf("%d", &M);
	table = (int *)malloc(sizeof(int) * M);
	table_init(table, M);
	while (input != 'e')
	{
		scanf("%c", &input);
		if (input == 'i')
		{
			scanf(" %d", &num);
			table[h_func(num, M)] = num;
		}
		else if (input == 's')
		{
			scanf(" %d", &num);
			if (table[h_func(num, M)] == num)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (input == 'p')
			print_table(table, M);
		else if (input == 'd')
		{
			scanf(" %d", &num);
			if (table[h_func(num, M)] == num)
			{
				printf("1\n");
				table[h_func(num, M)] = -1;
			}
			else
				printf("0\n");
		}
		else if (input == 'e')
			break ;
	}
	free(table);
}
