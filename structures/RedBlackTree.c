//
// Created by danie on 20.06.2023.
//

#include "stdio.h"
#include "stdlib.h"

struct node {
    int value;
    struct node *parent;
    struct node *left;
    struct node *right;
    char color; //(r)ed // (b)lack
};

struct node* rightRotate(struct node *tree, struct node *nodeToRotate){
    struct node *leftChild = nodeToRotate->left;
    nodeToRotate->left = leftChild->right;
    leftChild->parent = nodeToRotate->parent;

    if(leftChild->right != NULL) {
        leftChild->right->parent = nodeToRotate;
    }
    if(nodeToRotate->parent == NULL){
        tree = leftChild;
    } else {
        if(nodeToRotate == nodeToRotate->parent->right){
            nodeToRotate->parent->right = leftChild;
        } else {
            nodeToRotate->parent->left = leftChild;
        }
    }
    leftChild->right = nodeToRotate;
    nodeToRotate->parent = leftChild;
    return tree;
}

struct node* leftRotate(struct node *tree, struct node *nodeToRotate){
    struct node *rightChild = nodeToRotate->right;
    nodeToRotate->right = rightChild->left;
    rightChild->parent = nodeToRotate->parent;

    if(rightChild->left != NULL) {
        rightChild->left->parent = nodeToRotate;
    }
    if(nodeToRotate->parent == NULL){
        tree = rightChild;
    } else {
        if(nodeToRotate == nodeToRotate->parent->left){
            nodeToRotate->parent->left = rightChild;
        } else {
            nodeToRotate->parent->right = rightChild;
        }
    }
    rightChild->left = nodeToRotate;
    nodeToRotate->parent = rightChild;

    return tree;
}

struct node* insertFixup(struct node *tree, struct node *insert){
    // insert = new node
    // p = parent
    // g = grandfather
    // u = uncle

    // never coded, will never do.
}

struct node* rbtInsert(struct node *tree, struct node *insert){
    struct node *prevNode = NULL;
    struct node *root = tree;
    while(root != NULL){
        prevNode = root;
        if(insert->value > root->value){
            root = root->right;
        } else {
            root = root->left;
        }
    }
    // regular insert of a node into a tree except there is a parent and a color to assign (default red)
    insert->parent = prevNode;
    insert->color = 'r';

    if(prevNode == NULL){
        tree = insert;
    } else {
        if(insert->value < prevNode->value){
            prevNode->left = insert;
        }
        else{
            prevNode->right = insert;
        }
    }
    // and also we have to fix the tree to match the conditions again
    // fixInput(tree)
    return tree;
}

struct node* createNode(int i){
    struct node* node = malloc(sizeof (struct node));
    node->value = i;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

struct node* search(struct node *tree, int val){
    struct node *temp = tree;
    while(temp != NULL && temp->value != val){
        if(temp->value < val) temp = temp->right;
        else temp = temp->left;
    }
    if(temp == NULL){
        return NULL;
    }
    return temp;
}

int main(){
    struct node *tree = createNode(10);
    tree = rbtInsert(NULL, tree);
    tree = rbtInsert(tree, createNode(5));
    tree = rbtInsert(tree, createNode(15));
    tree = rbtInsert(tree, createNode(2));
    tree = rbtInsert(tree, createNode(7));
    tree = rbtInsert(tree, createNode(6));
    tree = rbtInsert(tree, createNode(8));

    leftRotate(tree, search(tree, 5));
    leftRotate(tree, search(tree, 10));
    rightRotate(tree, search(tree, 5));
    rightRotate(tree, search(tree, 7));
}