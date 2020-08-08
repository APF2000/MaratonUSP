#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node *left;
	struct node *right;
	
	char substance[5];
}node, *Node;


int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

int profundidade(Node root)
{
	if(root == NULL) return 0;

	return 1 + max(profundidade(root->left), profundidade(root->right));
}

void print_tree(Node root, int tabs)
{
	//int i;	

	if(root == NULL)
	{
		printf(" ");
		return;
	}

	printf("'%s'{", root->substance);

	printf("esq: ");
	print_tree(root->left, tabs + 1);

	printf("dir: ");
	print_tree(root->right, tabs + 1);

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
}

// Conecta os reagentes de uma fórmula aos seus antecessores
// na lista de nós (nodes).
void link_formulas(Node all_nodes, Node new_node, int last_pos)
{
	int i;
	int right = 0, left = 0;
	char new_sub_esq[5], new_sub_dir[5];


	// Copiando a string pra new_sub
	strcpy(new_sub_esq, new_node->left->substance);
	strcpy(new_sub_dir, new_node->right->substance);

	for(i = last_pos - 1; i >= 0; i--)
	{
		if( strcmp(all_nodes[i].substance, new_sub_esq) == 0 && !left)
		{
			left = 1;
			free(new_node->left);
			new_node->left = &all_nodes[i]; 
		}
		if( strcmp(all_nodes[i].substance, new_sub_dir) == 0 && !right)
		{
			right = 1;
			free(new_node->right);
			new_node->right = &all_nodes[i];
		}

		if(left && right) return;		
	}


	if(!left && new_node->left != NULL){
		new_node->left->left = NULL;
		new_node->left->right = NULL;
	}
	if(!right && new_node->right != NULL){
		new_node->right->left = NULL;
		new_node->right->right = NULL;
	}
}

int qtde_recipientes(Node root)
{
	int esq, dir;
	int q_min, q_max;

	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 0;

	esq = qtde_recipientes(root->left);
	dir = qtde_recipientes(root->right);	

	q_max = max(esq, dir);
	q_min = min(esq, dir);

	if(q_max == q_min) return 1 + q_max;
	else return q_max;
}

int main()
{
	Node b, c;
	node a;
	node* nodes;

	int n, i;

	scanf("%d", &n);
	while(n != 0)
	{
		nodes = malloc(n * sizeof(node));
		for(i = 0; i < n; i++)
		{
			b = malloc(sizeof(node));
			c = malloc(sizeof(node));

			a.left = b;
			a.right = c;

			scan_formula(&a, b, c);
			link_formulas(nodes, &a, i);

			nodes[i] = a;
		}

		printf("%s requires %d containers\n", nodes[n-1].substance, qtde_recipientes(&nodes[n - 1]) );

		//print_tree(&nodes[n-1], 0);

		free(nodes);
		scanf("%d", &n);
	}

	return 0;
}

/* Casos de teste

7
E + D -> T1 C + T1 -> T2 B + T1 -> T3 T2 + T3 -> T4 T1 + T4 -> T6 A + T4 -> T5 T5 + T6 -> P

                                         p
                      /-----------------/  \\\\\\\\\\\\\\\\\\\\
                     T5                                       T6
           //////////  \\\\\\\\                     //////////  \\\\\\\\\
          A                    T4                  T1                    T4
                          /////  \\\\          ///// \\\\           /////  \\\\\    
                         T2         T3        E          D         T2           T3
                     //// \\\     //  \\                         //  \\       //  \\
                    T1      C    B     T1                       T1    C      B     T1
                   /  \               /   \                    /  \               /  \    
                  E   D              E    D                   E    D             E    D


Caso cíclico (IMPOSSÍVEL?):
CONTRA AS REGRAS?
3
A + T1 -> T2   
T2 + B -> T1  
T1 + T2 -> P

                            P

            T1                            T2

    T2           B                   T1        A

 T1   A                          T2     B


Dois reagentes levam a produtos diferentes + duplicata
4
A + B -> T1
A + B -> T2
C + D -> T2
T1 + T2 -> P


Reações que não têm nada a ver com o produto final
5
A + B -> ABCDE
C + T -> CET
SEXO - AMOR -> VONTA
AMOR - SEXO -> AMIZA
ABCDE + CET -> FIM


Mais de uma reação leva ao mesmo produto (SEG-FAULT):
5
A + B -> T1
C + D -> T2
T2 + A -> T3
T1 + C -> T3
T2 + T3 -> P

                                     p

                T2                                        T3

      C                  D                      T1                   C
                  
                                          A           B

VS

                                     p

                T2                                        T3

      C                  D                      T2                   A
                  
                                          C           D


6
F + G -> T1
D + T1 -> T2
T1 + T2 -> T3
C + T3 -> T5
A + B -> T4
T4 + T5 -> P
		                         p
                       /////////////////   \\\\\\\\\\\\\\\\\
		     T5                                     T4
               //////  \\\\\                          //////  \\\\\
	      T3           C                          A            B
	  ////  \\\\
	 T1       T2
      ///  \\    // \\
      F     G   D    T1
                    /  \
                   F    G

1
2H + O -> Water

5
A + B -> T1
C + D -> T2
E + F -> T3
T2 + T3 -> T4
T4 + T1 -> P

3
a + b -> ab
ab + c -> abc
abc + d -> abcd
0

*/
