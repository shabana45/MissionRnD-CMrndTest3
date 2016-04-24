#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
#include <conio.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}
struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node* add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}
struct node_dll *newNode_DLL_spec(int key)
{
	struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
	temp->data = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
struct node_dll * make_dll_spec(int *arr, int len){
	struct node_dll *root = newNode_DLL_spec(arr[0]);
	struct node_dll *temp = root;
	for (int i = 1; i < len; i++){
		struct node_dll *cur = newNode_DLL_spec(arr[i]);
		temp->next = cur;
		cur->prev = temp;
		temp = temp->next;
	}
	return root;
}
int main(){
	int b1[] = { 5, 3, 2, 1, 4 };
	int b2[] = { 5, 3, 2, 1, 4 };
	int l1 = 7;
	int l2 = 5;
	struct node* root1 = NULL;
	struct node* root2 = NULL;
	struct node_dll * head = NULL;
	for (int i = 0; i < l2; i++)
		head = make_dll_spec(b2, l2);
	for (int i = 0; i < 5; i++)
		root1 = add_node_spec(root1, b1[i]);
	//printBST(root1);
	int x = is_identical(head, root1);
	printf("%d", x);
	_getch();
	return 0;
};