#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Binary.h"
#include "stack.h"
#include <string.h>

Bnode_t* ConstructExpresion(char expression[])
{
	stack_t s;
	InitializeStack(&s);
	Bnode_t* mainroot=NULL;
	Bnode_t* node=NULL; //this is for push only
	for (int i = 0; i < strlen(expression); i++)
	{
		if (*(expression + i) == '*' || *(expression + i) == '/'
			|| *(expression + i) == '+' || *(expression + i) == '-')
		{

			Bnode_t* right = pop(&s);
			Bnode_t* left = pop(&s);
			mainroot = getNode(*(expression + i));
			mainroot->left = left;
			mainroot->right = right;
			Push(&s, mainroot);  //main root for pushing

		}
		else
		{
			node = getNode(*(expression + i));
			Push(&s, node);


		}

	}

	return pop(&s); //returns the last pop value :)
}

int main(void)
{
	printf("Enter a postfix expression: ");
	char expression[20];
	scanf("%s", expression);
	Bnode_t* root=ConstructExpresion(expression);
	PostOrder(root);
	printf("\n");
	Inorder(root);
	return 0;
}