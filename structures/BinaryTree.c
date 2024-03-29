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
struct BinaryTree *insert(struct BinaryTree *tree, int value) {
    struct BinaryTree *prevNode = NULL;
    struct BinaryTree *currentNode = tree;
    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->value < value) currentNode = currentNode->right;
        else currentNode = currentNode->left;
    }
    // double check if insert has to be done left or right
    struct BinaryTree *node = malloc(sizeof(struct BinaryTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if (prevNode == NULL) {
        tree = node;
    } else if (prevNode->value < value) {
        prevNode->right = node;
    } else {
        prevNode->left = node;
    }
    return tree;
}

// having a 1 step delayed pointer to insert the item
struct BinaryTree *insertTree(struct BinaryTree *tree, struct BinaryTree *node) {
    struct BinaryTree *prevNode = NULL;
    struct BinaryTree *currentNode = tree;
    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->value < node->value) currentNode = currentNode->right;
        else currentNode = currentNode->left;
    }
    // double check if insert has to be done left or right
    if (prevNode == NULL) {
        tree = node;
    } else if (prevNode->value < node->value) {
        prevNode->right = node;
    } else {
        prevNode->left = node;
    }
    return tree;
}

void delete(struct BinaryTree *root, struct BinaryTree *deleteNode) {
    struct BinaryTree *prevNode = NULL;
    struct BinaryTree *current = root;

    // Find the node to be deleted and its parent
    while (current != NULL && current->value != deleteNode->value) {
        prevNode = current;
        if (deleteNode->value < current->value)
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
        struct BinaryTree *predecessor = current->left;
        struct BinaryTree *prevPred = current;
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
        struct BinaryTree *newNode;

        // Node to be deleted has only right child
        if (current->left == NULL) newNode = current->right;
            // Node to be deleted has only left child
        else if (current->right == NULL) newNode = current->left;

        // Node to be deleted is a leaf node
        if (prevNode == NULL) root = newNode;
        else if (current == prevNode->left) prevNode->left = newNode;
        else prevNode->right = newNode;

        free(current);
    }
}

int determineHeight(struct BinaryTree *tree) {
    if (tree == NULL)
        return 0;
    int leftHeight = determineHeight(tree->left);
    int rightHeight = determineHeight(tree->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
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

void preOrderTraversal(struct BinaryTree *tree) {
    if (tree != NULL) {
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
        printf("%d, ", tree->value);
    }
}

void postOrderTraversal(struct BinaryTree *tree) {
    if (tree != NULL) {
        printf("%d, ", tree->value);
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
    }
}

void inOrderTraversal(struct BinaryTree *tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->left);
        printf("%d, ", tree->value);
        inOrderTraversal(tree->right);
    }
}

// min of right subtree
// next node in an in-order traversal of the BST
/*int findSuccessor(struct BinaryTree *tree) {
    tree = tree->right;
    return findMin(tree);
}*/

// next node in an in-order traversal of the BST
struct BinaryTree* findSuccessor(struct BinaryTree *tree, struct BinaryTree *successorNode){

    // the successorNode will actually have a successor in its tree
    //successor of successorNode => min of this node
    // => 17 -> 14, 20
    // => 20 -> 18, 19
    // >> successor: 18
    if(successorNode->right != NULL){
        struct BinaryTree *successor = successorNode->right;
        while(successor->left != NULL){
            successor = successor->left;
        }
        return successor;
    }

    // the successorNode does not have a successor in its own tree >> we have to go up the tree
    struct BinaryTree *successor = NULL;
    while(tree != NULL){
        // traverse through the tree to find the successor
        if(successorNode->value < tree->value){
            successor = tree;
            tree = tree->left;
        } else if(successorNode->value > tree->value){
            tree = tree->right;
        } else {
            break;
        }
    }
    return successor;
}

// max of left subtree
// previous node in an in-order traversal of the BST
struct BinaryTree* findPredecessor(struct BinaryTree *tree, struct BinaryTree *predecessorNode) {
    if(predecessorNode->left != NULL){
        struct BinaryTree* pred = predecessorNode->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    struct BinaryTree* predecessor = NULL;
    while(tree != NULL){
        if(tree->value < predecessorNode->value){
            tree = tree->right;
        } else if(tree->value > predecessorNode->value){
            predecessor = tree;
            tree = tree->left;
        } else {
            break;
        }
    }
    return predecessor;
}

int main() {
    struct BinaryTree *node = malloc(sizeof (struct BinaryTree));
    node->value = 8;
    node->left = NULL;
    node->right = NULL;
    struct BinaryTree *tree = malloc(sizeof (struct BinaryTree));
    tree->value = 10;
    tree->left = NULL;
    tree->right = NULL;
    tree = insertTree(NULL, tree);
    tree = insertTree(tree, node);
    tree = insert(tree, 20);
    tree = insert(tree, 15);
    tree = insert(tree, 13);
    tree = insert(tree, 17);
    tree = insert(tree, 30);
    tree = insert(tree, 7);
    tree = insert(tree, 9);
    inOrderTraversal(tree);
    printf("\n");
    preOrderTraversal(tree);
    printf("\n");
    postOrderTraversal(tree);
    printf("\n");

    printf("Height: %d\n", determineHeight(tree));
    printf("Successor of 10: %d\n", findSuccessor(tree, tree)->value);
    printf("Successor of 20: %d\n", findSuccessor(tree, search(tree, 20))->value);
    printf("Successor of 15: %d\n", findSuccessor(tree, search(tree, 15))->value);
    printf("Successor of 13: %d\n", findSuccessor(tree, search(tree, 13))->value);
    //printf("Successor of 30: %d\n", findSuccessor(tree, search(tree, 30))->value);
    printf("Predecessor of 10: %d\n", findPredecessor(tree, search(tree, 10))->value);
    printf("Predecessor of 20: %d\n", findPredecessor(tree, search(tree, 20))->value);
    printf("Predecessor of 15: %d\n", findPredecessor(tree, search(tree, 15))->value);
    printf("Predecessor of 13: %d\n", findPredecessor(tree, search(tree, 13))->value);
    //printf("Predecessor of 7: %d\n", findPredecessor(tree, search(tree, 7))->value);

    //printf("Predecessor: %d\n", findSuccessor(tree));
    //printf("Predecessor: %d\n", findSuccessor(tree));

    printf("Search %p\n", search(tree, 15));

    printf("Min of Tree: %d\n", findMin(tree));
    printf("Max of Tree: %d\n", findMax(tree));

    delete(tree, search(tree, 8));
    delete(tree, search(tree, 10));
    delete(tree, search(tree, 13));
    inOrderTraversal(tree);
}