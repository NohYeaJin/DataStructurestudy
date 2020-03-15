#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*before;
	int				data;
}				t_node;

typedef struct	s_deque
{
	t_node	*front;
	t_node	*back;
	t_node	*cur;
	int		data_num;
	
}				t_deque;

void	init_deque(t_deque *d)
{
	d->front = (t_node *)malloc(sizeof(t_node));
	d->back = (t_node *)malloc(sizeof(t_node));
	
	d->front->next = d->back;
	d->front->before = NULL;
	d->back->next = NULL;
	d->back->before = d->front;
	d->data_num = 0;
}

void	push_front(t_deque *d)
{
	int		n;
	t_node *new_d;
	
	new_d = (t_node *)malloc(sizeof(t_node));
	
	new_d->next = d->front->next;
	d->front->next->before = new_d;
	d->front->next = new_d;
	new_d->before = d->front;
	
	scanf("%d", &n);
	new_d->data = n;
	(d->data_num)++;
}

void	push_back(t_deque *d)
{
	int		n;
	t_node *new_d;
	
	new_d = (t_node *)malloc(sizeof(t_node));
	
	d->back->before->next = new_d;
	new_d->before = d->back->before;
	new_d->next = d->back;
	d->back->before = new_d;
	
	scanf("%d", &n);
	new_d->data = n;
	(d->data_num)++;
}

void	pop_front(t_deque *d)
{
	if (d->data_num == 0)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n",d->front->next->data);
	
	t_node *remem_node = d->front->next;
	
	d->front->next = remem_node->next;
	remem_node->next->before = d->front;
	free(remem_node); 
	(d->data_num)--;
}

void	pop_back(t_deque *d)
{
	if (d->data_num == 0)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n",d->front->next->data);
	
	t_node *remem_node = d->front->next;
	
	d->front->next = remem_node->next;
	remem_node->next->before = d->front;
	free(remem_node);
	(d->data_num)--;
}

void	size(t_deque *d)
{
	printf("%d\n",d->data_num);
}

void	empty(t_deque *d)
{
	if (d->data_num == 0)
		printf("1\n");
	else
		printf("0\n");
}

void	front(t_deque *d)
{
	if (d->data_num == 0)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", d->front->next->data);
}

void	back(t_deque *d)
{
	if (d->data_num == 0)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", d->back->before->data);
}

int		main(void)
{
	t_deque	d;
	int		leng;
	int		i;
	char	command[32];
	init_deque(&d);
	scanf("%d", &leng);
	i = 0;
	while (i < leng)
	{
		scanf("%s", command);
		if (!strcmp(command, "push_front"))
			push_front(&d);
		else if (!strcmp(command, "push_back"))
			push_back(&d);
		else if (!strcmp(command, "pop_front"))
			pop_front(&d);
		else if (!strcmp(command, "pop_back"))
			pop_back(&d);
		else if (!strcmp(command, "size"))
			size(&d);
		else if (!strcmp(command, "empty"))
			empty(&d);
		else if (!strcmp(command, "front"))
			front(&d);
		else if (!strcmp(command, "back"))
			back(&d);
		i++;
	}
	return (0);
}
