#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
TreeNode* createTreeNode(int data);
TreeNode* insert(TreeNode* root, int data);
void inorder(TreeNode* root);
void printTree(TreeNode* root, int level, const char* prefix);

// Function implementations
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) return createTreeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void printTree(TreeNode* root, int level, const char* prefix) {
    if (root == NULL) return;

    // Print the current node with indentation and prefix
    printf("%*s%s%d\n", level * 4, "", prefix, root->data);

    // Recursively print the left and right children
    char newPrefix[20];
    snprintf(newPrefix, sizeof(newPrefix), "L--- ");
    printTree(root->left, level + 1, newPrefix);

    snprintf(newPrefix, sizeof(newPrefix), "R--- ");
    printTree(root->right, level + 1, newPrefix);
}

#endif // BINARY_TREE_H_INCLUDED
