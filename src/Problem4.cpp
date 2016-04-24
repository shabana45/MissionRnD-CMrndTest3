/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* add_node(struct node *root, int data);
void preorder(struct node* root2, int* arr, int* i);
struct node * new_node(int data);
void merge_two_bst(struct node *root1, struct node *root2){
	if (root1 == NULL)
		root1 = root2;
	int* arr = (int*)malloc(15 * sizeof(int));
	int* i = (int*)calloc(1, sizeof(int));
	preorder(root2, arr, i);
	for (int j = 0; j < *i; j++)
		root1 = add_node(root1, arr[j]);
	free(i);
}
void preorder(struct node* root2, int* arr, int* i)
{
	if (root2 == NULL) return;
	arr[*i] = root2->data;
	(*i)++;
	preorder(root2->left, arr, i);
	preorder(root2->right, arr, i);
}
struct node* add_node(struct node *root, int data){
	if (root == NULL) return new_node(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);

	return root;
}
struct node * new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}