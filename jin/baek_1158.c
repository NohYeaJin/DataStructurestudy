#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*before;
}				t_node;

typedef struct	s_list
{
	t_node *head;
}				t_list;

void	list_make(t_list *l, int data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	if (data == 1)
	{
		l->head = new_node;
		new_node->next = new_node;
		new_node->before = new_node;
	}
	else
	{
		new_node->next = l->head;
		new_node->before = l->head->before;
		l->head->before->next = new_node;
		l->head->before = new_node;
	}
	
}

void	list_del(t_list *l, int size, int jump)
{
	int 	i;
	int 	j;
	t_node *remem_node;
	t_node *cur;
	
	cur = l->head;
	i = 1;
	printf("<");
	while (1)
	{
		j = -1;
		if (i == 1)
			while (++j < jump - 1)
				cur = cur->next;
		else
			while (++j < jump)
				cur = cur->next;
		remem_node = cur;
		printf("%d",cur->data);
		cur->before->next = cur->next;
		cur->next->before = cur->before;
		if (i == size)
			break;
		printf(", ");
		i++;
		free(remem_node);
	}
	printf(">");
}

int main(void)
{
	int		size;
	int		jump;
	int 	i;
	t_list	*l;
	
	l = (t_list	*)malloc(sizeof(t_list));
	scanf("%d %d", &size, &jump);
	i = 1;
	while (i <= size)
	{
		list_make(l, i);
		i++; 
	}
	list_del(l, size, jump);
	free(l);
	return (0);
}
