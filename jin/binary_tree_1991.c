#include <stdio.h>

typedef struct	s_node
{
	char left;
	char right;
}				t_node;

void	pre_traval(t_node *node, unsigned char data)
{
	if (data == '.')
		return ;
	printf("%c", data);
	pre_traval(node, node[data].left);
	pre_traval(node, node[data].right);
}

void	inorder_traval(t_node *node, unsigned char data)
{
	if (data == '.')
		return ;
	inorder_traval(node, node[data].left);
	printf("%c", data);
	inorder_traval(node, node[data].right);
}

void	post_traval(t_node *node, unsigned char data)
{
	if (data == '.')
		return ;
	post_traval(node, node[data].left);
	post_traval(node, node[data].right);
	printf("%c", data);
}

int		main(void)
{
	unsigned char	alp[3];
	int				command_num;
	int				i;
	t_node			node[128];

	scanf("%d", &command_num);
	getchar();
	i = -1;
	while (++i <command_num)
	{
		scanf("%c %c %c", &alp[0], &alp[1], &alp[2]);
		getchar();
		node[alp[0]].left = alp[1];
		node[alp[0]].right = alp[2];
	}
	pre_traval(node, 'A');
	printf("\n");
	inorder_traval(node, 'A');
	printf("\n");
	post_traval(node, 'A');
	printf("\n");
	return (0);
}


/*
typedef struct	s_node
{
	char			data;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

t_node	*make_node(char data)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	set_data(t_node *node, char a, char b, char c)
{
	node->data = a;
	if (b != '.')
		node->left = make_node(b);
	if (c != '.')
		node->right = make_node(c);
}

int		main(void)
{
	char	alp[3];
	int		comm_num;
	int		i;
	t_node	*node;

	node = make_node('\0');
	scanf("%d", &comm_num);
	getchar();
	i = -1;
	while (++i < node_num)
	{
		scanf("%c %c %c", &alp[0], &alp[1], &alp[2]);
		getchar();
		set_data(node, alp[0], alp[1], alp[2]);
	}
}
*/
