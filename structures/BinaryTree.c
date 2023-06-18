//
// Created by danie on 18.06.2023.
//

#include "stdio.h"
#include "stdlib.h"

struct BinaryTree {
    int value;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

int countOccurrences(struct BinaryTree *tree, int searchValue) {
    if (tree == NULL) {
        return 0;
    } else if (tree->value < searchValue) {
        tree = tree->right;
        return countOccurrences(tree, searchValue);
    } else if (tree->value > searchValue) {
        tree = tree->left;
        return countOccurrences(tree, searchValue);
    } else if (tree->value == searchValue) {
        return countOccurrences(tree->left, searchValue) + countOccurrences(tree->right, searchValue) + 1;
    } else {
        return 0;
    }
}

// having a 1 step delayed pointer to insert the item
struct BinaryTree* insert(struct BinaryTree *tree, int value) {
    struct BinaryTree *prevNode = NULL;
    struct BinaryTree *currentNode = tree;
    while(currentNode != NULL){
        prevNode = currentNode;
        if(currentNode->value < value) currentNode = currentNode->right;
        else currentNode = currentNode->left;
    }
    // double check if insert has to be done left or right
    struct BinaryTree *node = malloc(sizeof (struct BinaryTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if(prevNode != NULL){
        tree = node;
    }
    else if(prevNode->value < value){
        prevNode->right = node;
    }
    else {
        prevNode->left = node;
    }
    return tree;
}

// having a 1 step delayed pointer to insert the item
struct BinaryTree* insertTree(struct BinaryTree *tree, struct BinaryTree *node) {
    struct BinaryTree *prevNode = NULL;
    struct BinaryTree *currentNode = tree;
    while(currentNode != NULL){
        prevNode = currentNode;
        if(currentNode->value < node->value) currentNode = currentNode->right;
        else currentNode = currentNode->left;
    }
    // double check if insert has to be done left or right
    if(prevNode != NULL){
        tree = node;
    }
    else if(prevNode->value < node->value){
        prevNode->right = node;
    }
    else {
        prevNode->left = node;
    }
    return tree;
}

struct BinaryTree* delete(struct BinaryTree* tree, struct BinaryTree* deleteNode) {
    return tree;
}

int determineHeight(struct BinaryTree* tree){
    if(tree == NULL)
        return 0;
    int leftHeight = determineHeight(tree->left);
    int rightHeight = determineHeight(tree->right);

    return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}

struct BinaryTree *search(struct BinaryTree *tree, int value) {
    if (tree->value == value) {
        return tree;
    } else if (tree->value < value) {
        return search(tree->right, value);
    } else if (tree->value > value) {
        return search(tree->left, value);
    }
    // returns NULL as nothing was found
    return tree;
}

int findMin(struct BinaryTree *tree) {
    struct BinaryTree *preNode = tree;
    while (tree != NULL) {
        preNode = tree;
        tree = tree->left;
    }
    return preNode->value;
}

int findMax(struct BinaryTree *tree) {
    struct BinaryTree *preNode = tree;
    while (tree != NULL) {
        preNode = tree;
        tree = tree->right;
    }
    return preNode->value;
}

void preOrderTraversal(struct BinaryTree* tree) {
    if(tree != NULL){
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
        printf("%d, ", tree->value);
    }
}

void postOrderTraversal(struct BinaryTree* tree) {
    if(tree != NULL){
        printf("%d, ", tree->value);
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
    }
}

void inOrderTraversal(struct BinaryTree* tree) {
    if(tree != NULL){
        inOrderTraversal(tree->left);
        printf("%d, ", tree->value);
        inOrderTraversal(tree->right);
    }
}

// min of right subtree
int findSuccessor(struct BinaryTree *tree) {
    tree = tree->right;
    return findMin(tree);
}


struct BinaryTree *SuccAbove(struct BinaryTree *p, struct BinaryTree *x) {
    struct node *succ;
    succ = NULL;
    while (p != x) {
        if (x->value < p->value) {
            succ = p;
            p = p->left;
        } else if (x->value > p->value) { p = p->right; }
    }
    return succ;
}

// max of left subtree
int findPredecessor() {}

int main() {}