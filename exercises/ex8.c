//
// Created by danie on 19.06.2023.
//

#include "stdlib.h"
#include "stdio.h"

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insert(struct TreeNode **root, int val) {
    struct TreeNode *previousNode;
    struct TreeNode *currentNode = (*root);
    // traverse through nodes
    while (currentNode != NULL) {
        previousNode = currentNode;
        if (currentNode->value > val) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (previousNode == NULL) {
        (*root) = newNode;
    } else if (previousNode->value > val) {
        previousNode->left = newNode;
    } else {
        previousNode->right = newNode;
    }
}

void delete(struct TreeNode **root, int key) {
    struct TreeNode *prevNode = NULL;
    struct TreeNode *current = *root;

    // Find the node to be deleted and its parent
    while (current != NULL && current->value != key) {
        prevNode = current;
        if (key < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) {
        printf("Key not found in the tree.\n");
        return;
    }

    // Node to be deleted has two children
    if (current->left != NULL && current->right != NULL) {
        // Find inorder predecessor and its parent
        struct TreeNode *predecessor = current->left;
        struct TreeNode *prevPred = current;
        while (predecessor->right != NULL) {
            prevPred = predecessor;
            predecessor = predecessor->right;
        }

        // Replace the value of the node to be deleted with the value of the inorder predecessor
        current->value = predecessor->value;

        // Now delete the inorder predecessor
        if (prevPred->right == predecessor) prevPred->right = predecessor->left;
        else prevPred->left = predecessor->left;

        free(predecessor);
    } else {
        struct TreeNode *newNode;

        // Node to be deleted has only right child
        if (current->left == NULL) newNode = current->right;
            // Node to be deleted has only left child
        else if (current->right == NULL) newNode = current->left;

        // Node to be deleted is a leaf node
        if (prevNode == NULL) *root = newNode;
        else if (current == prevNode->left) prevNode->left = newNode;
        else prevNode->right = newNode;

        free(current);
    }
}


void preOrder(struct TreeNode **root) {
    if (*root != NULL) {
        preOrder(&(*root)->left);
        preOrder(&(*root)->right);
        printf("%d, ", (*root)->value);
    }
}

void inOrder(struct TreeNode **root) {
    if (*root != NULL) {
        inOrder(&(*root)->left);
        printf("%d, ", (*root)->value);
        inOrder(&(*root)->right);
    }
}

void postOrder(struct TreeNode **root) {
    if (*root != NULL) {
        printf("%d, ", (*root)->value);
        postOrder(&(*root)->left);
        postOrder(&(*root)->right);
    }
}

void traverseTree(struct TreeNode **root) {
    printf("Tree traversal: \n");
    printf("Pre Order: \n");
    preOrder(&(*root));
    printf("\nInOrder: \n");
    inOrder(&(*root));
    printf("\nPostOrder: \n");
    postOrder(&(*root));
    printf("\n");
}

int determineHeight(struct TreeNode **root) {
    if ((*root) == NULL) {
        return 1;
    }
    return determineHeight(&(*root)->left) > determineHeight(&(*root)->right) ? determineHeight(&(*root)->left) + 1 :
           determineHeight(&(*root)->right) + 1;
}


void printTree(struct TreeNode **root) {
    if ((*root) != NULL) {
        if ((*root)->left != NULL) {
            printf("%d ------ %d : %d\n", (*root)->value, (*root)->left->value, determineHeight(&(*root)));
        }
        if ((*root)->right != NULL) {
            printf("%d ------ %d : %d\n", (*root)->value, (*root)->right->value, determineHeight(&(*root)));
        }
        printTree(&(*root)->left);
        printTree(&(*root)->right);
    }
}

int main() {
    struct TreeNode *root = NULL;

    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 12);
    insert(&root, 1);
    //traverseTree(&root);
    delete(&root, 4);
    delete(&root, 12);
    delete(&root, 2);
    traverseTree(&root);
    printTree(&root);
    return 0;
}
