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
int main(){
	int arr[] = { 1, 2, 3,4, 5, 0, -999, -999 };
	int len = 5;
	int actual_len = 5;
	int ans = 4;
	struct node* root = NULL;
	for (int i = 0; i < len; i++)
		root = add_node_spec(root, arr[i]);
	int x= get_missing_value(root, actual_len);
	printf("%d ", x);
	_getch();
	return 0;
};