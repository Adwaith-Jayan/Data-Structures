#include <stdio.h>
#include <stdlib.h>
// Define a structure for a tree node
struct TreeNode {
 int data;
 struct TreeNode* left;
 struct TreeNode* right;
};
// Function to create a new node
struct TreeNode* createNode(int data) {
 struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
 if (newNode == NULL) {
 printf("Memory allocation error\n");
 exit(EXIT_FAILURE);
 }
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
// Function to insert a new node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
 if (root == NULL) {
 return createNode(data);
 }
 if (data < root->data) {
 root->left = insertNode(root->left, data);
 } else {
 root->right = insertNode(root->right, data);
 }
 return root;
}
// Function for inorder traversal
void inorderTraversal(struct TreeNode* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
 }
}
// Function for preorder traversal
void preorderTraversal(struct TreeNode* root) {
 if (root != NULL) {
 printf("%d ", root->data);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
 }
}
// Function for postorder traversal
void postorderTraversal(struct TreeNode* root) {
 if (root != NULL) {
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%d ", root->data);
 }
}
// Function to find the minimum value node in a subtree
struct TreeNode* findMin(struct TreeNode* node) {
 while (node->left != NULL) {
 node = node->left;
 }
 return node;
}
// Function to delete a node with the given key from the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
 if (root == NULL) {
 return root;
 }
 if (key < root->data) {
 root->left = deleteNode(root->left, key);
 } else if (key > root->data) {
 root->right = deleteNode(root->right, key);
 } else {
 // Node with only one child or no child
 if (root->left == NULL) {
 struct TreeNode* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct TreeNode* temp = root->left;
 free(root);
 return temp;
 }
 // Node with two children
 struct TreeNode* temp = findMin(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
// Function to free memory allocated to the tree nodes
void freeTree(struct TreeNode* root) {
 if (root != NULL) {
 freeTree(root->left);
 freeTree(root->right);
 free(root);
 }
}
int main() {
 struct TreeNode* root = NULL;
 int choice, key;
 do {
 printf("\nBinary Tree Operations:\n");
 printf("1. Insert a new node\n");
 printf("2. Inorder traversal\n");
 printf("3. Preorder traversal\n");
 printf("4. Postorder traversal\n");
 printf("5. Delete a node\n");
 printf("6. Exit\n");
 printf("Enter your choice (1-6): ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the data for the new node: ");
 scanf("%d", &key);
 root = insertNode(root, key);
 printf("Node with data %d inserted.\n", key);
 break;
 case 2:
 printf("Inorder Traversal: ");
 inorderTraversal(root);
 printf("\n");
 break;
 case 3:
 printf("Preorder Traversal: ");
 preorderTraversal(root);
 printf("\n");
 break;
 case 4:
 printf("Postorder Traversal: ");
 postorderTraversal(root);
 printf("\n");
 break;
 case 5:
 printf("Enter the key to delete: ");
 scanf("%d", &key);
 root = deleteNode(root, key);
 printf("Node with key %d deleted.\n", key);
 break;
 case 6:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice. Please enter a number between 1 and 6.\n");
 }
 } while (choice != 6);
 // Free memory allocated to the tree nodes before exiting
 freeTree(root);
 return 0;
}
