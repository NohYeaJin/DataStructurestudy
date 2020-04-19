#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	char			data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_list
{
	t_node *head;
	t_node *tail;
	t_node *cur;
}				t_list;

int		ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	list_init(t_list *list)
{
	list->head = (t_node *)malloc(sizeof(t_node));
	list->cur = list->head;
	list->tail = list->head;
}

void	str_insert(t_list *list, char data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof (t_node));
	new_node->data = data;
	new_node->prev = list->cur;
	if (list->cur == list->tail)
	{
		list->cur->next = new_node;
		list->cur = new_node;
		list->tail = new_node;
	}
	else if (list->cur != list->tail)
	{
		new_node->next = list->cur->next;
		list->cur->next->prev = new_node;
		list->cur->next = new_node;
	}
}

void	list_delete(t_list *list)
{
	t_node *remem_node = list->cur;
	
	if (list->cur == list->tail)
		list->tail = list->tail->prev;
	else
	{
		list->cur->prev->next = list->cur->next;
		list->cur->next->prev = list->cur->prev;
	}
	list->cur = list->cur->prev;
	free(remem_node);
}

void	list_print(t_list *list)
{
	list->cur = list->head->next;
	while (list->cur != list->tail)
	{
		printf("%c",list->cur->data);
		list->cur = list->cur->next;
	}
	printf("%c",list->cur->data);
	printf("\n");
}

void	command_insert(t_list *list)
{
	int 	size;
	int 	i;
	char	command;

	scanf("%d", &size);
	getchar();
	i = -1;
	while (++i < size)
	{
		command = fgetc(stdin);
		getchar();
		if (command == 'L' && list->cur != list->head)
			list->cur = list->cur->prev;
		else if (command == 'D' && list->cur != list->tail)
			list->cur = list->cur->next;
		else if (command == 'B' && list->cur != list->head)
			list_delete(list);
		else if (command == 'P')
		{
			command = fgetc(stdin);
			getchar();
			str_insert(list, command);
		}
	}
}

int 	main(void)
{
	char	str[600000];
	int		i;
	t_list	list;
	
	list_init(&list);
	fgets(str, sizeof(str), stdin);
	str[ft_strlen(str) - 1] = '\0';
	i = -1;
	while (++i < ft_strlen(str))
		str_insert(&list, str[i]);
	command_insert(&list);
	list_print(&list);
	list.cur = list.tail;
	while (list.cur != list.head)
		list_delete(&list);
	free(list.cur);
}
