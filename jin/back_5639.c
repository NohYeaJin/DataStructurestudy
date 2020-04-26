#include <stdio.h>
#include <stdlib.h>

typedef struct			s_tree_node
{
	int					data;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;

typedef	struct			s_list_node
{
	t_tree_node			*data;
	struct s_list_node	*next;
}						t_list_node;

typedef struct	s_stack
{
	t_list_node	*head;
}				t_stack;

typedef	void (*func) (int);


t_tree_node	*make_tree_node(int data)
{
	t_tree_node *node = (t_tree_node *)malloc(sizeof(t_tree_node));

	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void		make_sub_left(t_tree_node *node, t_tree_node *left)
{
	node->left = left;
}

void		make_sub_right(t_tree_node *node, t_tree_node *right)
{
	node->right = right;
}

void		stack_push(t_stack *stack, t_tree_node *node)
{
	t_list_node	*new_node = (t_list_node *)malloc(sizeof(t_list_node));
	
	new_node->data = node;
	new_node->next = stack->head;
	stack->head = new_node;
}

void		show_data(int data)
{
	printf("%d\n", data);
}

void		post_traverse(t_tree_node *node, func show_data)
{
	if (node == NULL)
		return ;
	post_traverse(node->left, show_data);
	post_traverse(node->right, show_data);
	show_data(node->data);
}

void	 		show_post_express(t_tree_node *node)
{
	post_traverse(node, show_data);
}


int 		main(void)
{
	int			num[10000];
	int			i;
	int			j;
	int			k;
	t_stack		stack;
	t_tree_node	*node;
	t_list_node *cur;

	stack.head = NULL;
	i = -1;
	while(1)
	{
		scanf("%d", &num[++i]);
		getchar();
		if (num[i] == -99)
			break;
		node = make_tree_node(num[i]);
		stack_push(&stack, node);
		if (i != 0 && num[i] < num[i - 1])
			make_sub_left(stack.head->next->data, node);
		else if (i != 0 && num[i] > num[i - 1])
		{
			j = 1;
			while (i - j >= 0 && num[i - j] < num[i])
				j++;
			j--;
			cur = stack.head;
			k = -1;
			while (++k < j)
				cur = cur->next;
			make_sub_right(cur->data, node);
		}
	}
	while (cur->next)
		cur = cur->next;
	printf("----------\n");
	show_post_express(cur->data);
}
