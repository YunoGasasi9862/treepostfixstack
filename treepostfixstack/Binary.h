#pragma once
typedef char BType;
typedef struct Bnode_s

{

	BType data;
	Bnode_s* right;
	Bnode_s* left;
}Bnode_t;

Bnode_t* getNode(BType data)
{
	Bnode_t* tree;
	tree = (Bnode_t*)malloc(sizeof(Bnode_t));
	tree->data = data;
	tree->right = NULL;
	tree->left = NULL;
	return tree;
}

void PostOrder(Bnode_t* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c", root->data);

	}
}

void Inorder(Bnode_t* root)
{
	if (root != NULL)
	{
		if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
		{ //YAYAYAY I WAS ABLE TO DO IT!!
			printf("(");
		}
		Inorder(root->left);
		printf("%c", root->data);
		Inorder(root->right);
		if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
		{
			printf(")");
		}
	}
}