#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *left, *right;
};
struct Node* newnode(int value)
{
struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
temp->data = value;
temp->left = temp->right = NULL;
return temp;
}
struct Node* insertNode(struct Node* node, int value)
{
if (node == NULL) {
return newnode(value);
}
if (value < node->data)
{
node->left = insertNode(node->left, value);
}
else if (value > node->data)
{
node->right = insertNode(node->right, value);
}

return node;
}
void postOrder(struct Node* root)
{
if (root != NULL)
{
postOrder(root->left);
postOrder(root->right);
printf(" %d ", root->data);

}
}
