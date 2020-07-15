#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node *left;
	struct node *right;
	
	char substance[5];//[5];
}node, *Node;

void print_tree(Node root, int tabs)
{
	int i;	

	if(root == NULL)
	{
		printf(" ");
		return;
	}

	//for(i=0; i < tabs; i++) printf("\t");
	printf("'%s'{", root->substance);

	printf("esq: ");
	print_tree(root->left, tabs + 1);

	printf("dir: ");
	print_tree(root->right, tabs + 1);

	//for(i=0; i < tabs; i++) printf("\t");
	printf("} ");
}

// Escaneia os nomes das substâncias na fórmula química a + b -> c
void scan_formula(Node a, Node b, Node c)
{
	char garbage[2];

	
	scanf("%5s", b->substance);
	scanf("%2s", garbage);

	scanf("%5s", c->substance);
	scanf("%2s", garbage);

	scanf("%5s", a->substance);

	/*b->right = NULL;
	b->left = NULL;

	c->right = NULL;
	c->left = NULL;*/
}

// Conecta os reagentes de uma fórmula aos seus antecessores
// na lista de nós (nodes).
void link_formulas(Node* all_nodes, Node new_node, int last_pos)
{
	int i;
	int right = 0, left = 0;
	char new_sub_esq[5], new_sub_dir[5];

	
	printf("-----------------------------------------\n");

	// Copiando a string pra new_sub
	strcpy(new_sub_esq, new_node->left->substance);
	strcpy(new_sub_dir, new_node->right->substance);

	printf("Ponteiro vetor: %d; ponteiro new_node: %d;\n", all_nodes, new_node);

	printf("new_sub_esq = %s, new_sub_dir = %s, new_mode.sub = %s\n", new_sub_esq, new_sub_dir, new_node->substance);

	printf("Blz ate aqui\n");

	for(i = last_pos - 1; i >= 0; i--)
	{
		printf("Blz ate aqui2\n");
		/*printf("Node: (%s) -> (%s,%s)\n", (*all_nodes)[i].substance, (*all_nodes)[i].left->substance, (*all_nodes)[i].right->substance);
		printf("cmpesq = %d; cmpdir = %d", strcmp((*all_nodes)[i].left->substance, new_sub), strcmp((*all_nodes)[i].right->substance, new_sub));*/

		printf("Endereço da posição %d : %d\n", i, &(*all_nodes)[i]);

		if( strcmp((*all_nodes)[i].substance, new_sub_esq) == 0 )
		{
			printf("Achou um correspondente na pos %d para encaixar à esquerda\n", i);
			left = 1;
	
			printf("Esquerda antes : %d\n", new_node->left);
			free(new_node->left);
			new_node->left = &(*all_nodes)[i]; 
			printf("Esquerda depois : %d\n", new_node->left);
		}
		printf("Blz ate aqui3\n");
		if( strcmp((*all_nodes)[i].substance, new_sub_dir) == 0 )
		{
			printf("Achou um correspondente na pos %d para encaixar à direita\n", i);
			right = 1;
			printf("Direita antes : %d\n", new_node->right);
			free(new_node->right);
			new_node->right = &(*all_nodes)[i];
			printf("Direita depois : %d\n", new_node->right); 
		}

		if(left && right) return;		
	}

	printf("Blz ate aqui4 %d %d\n", right, left);
	if(!left && new_node->left != NULL){
		new_node->left->left = NULL;
		new_node->left->right = NULL;
	}
	if(!right && (*all_nodes)[last_pos].right != NULL){
		new_node->right->left = NULL;
		new_node->right->right = NULL;
	}
	printf("Blz ate aqui5\n");
	
	print_tree(new_node, 0);
}

int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

int profundidade(Node root)
{
	if(root == NULL) return 0;
	//if(root->left == NULL && root->right == NULL) return 1;

	return 1 + max(profundidade(root->left), profundidade(root->right));
}

int main()
{
	Node b, c;
	node a;
	node d;
	node* nodes;
	int n, i;
	char seta[2];

	scanf("%d", &n);
	while(n != 0)
	{
		nodes = malloc(n * sizeof(node));
		for(i = 0; i < n; i++)
		{
			//nodes[i] = malloc(sizeof(node));			

			//a = malloc(sizeof(node));
			b = malloc(sizeof(node));
			c = malloc(sizeof(node));

			a.left = b;
			a.right = c;

			scan_formula(&a, b, c);
			link_formulas(&nodes, &a, i);
			printf("[(%d) -> (%d,%d)]\n", &nodes[i], nodes[i].left, nodes[i].right);
			
			//printf("%s, %s = %s\n", a.substance, b->substance, c->substance);		
			nodes[i] = a;
		}

		printf("Profundidade da árvore: %d\n", profundidade(&nodes[n-1]));

		printf("Agora os endereços das posições do vetor e para onde apontam\n");
		for(i = 0; i < n; i++)
		{
			printf("[(%d) -> (%d,%d)];", &nodes[i], nodes[i].left, nodes[i].right);
			printf("[(%s) -> (", nodes[i].substance);
			if(nodes[i].left != NULL) printf("%s", nodes[i].left->substance);
			printf(",");
			if(nodes[i].right != NULL) printf("%s", nodes[i].right->substance);
			printf(")]\n");
		}

		/*for(i = 0; i < n; i++)
		{
			//printf("\nOi");
			d = nodes[i];
			printf("\n(%s) -> (%s), (%s)", d.substance, d.left->substance, d.right->substance);
		}*/
		print_tree(&nodes[n - 1], 0);

		free(nodes);
		scanf("%d", &n);
	}

/*
	a = malloc(sizeof(node));
	b = malloc(sizeof(node));
	c = malloc(sizeof(node));

	scanf("%5s", a->substance);
	printf("%s %d %d %d\n", a->substance, a->left, a->right, NULL);	*/

	return 0;
}

/* Casos de teste

7
E + D -> T1 C + T1 -> T2 B + T1 -> T3 T2 + T3 -> T4 T1 + T4 -> T6 A + T4 -> T5 T5 + T6 -> P

*/
