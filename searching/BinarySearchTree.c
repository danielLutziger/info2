//
// Created by danie on 09.06.2023.
//

/**
* contains:
 * - insertion
 * - deletion
 * - travsersal
 * - search
 * - conversion to a balanced tree
*/

/**
* binary search tree (BST) is a data structure
 * - left subtree contains only nodes with keys <= than the parent
 * - right subtree contains only nodes with keys >= than the parent
 * -> left and right subtree are thus also binary search trees
 *
 *            50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
*/

#include "stdio.h"
#include "stdlib.h"

struct node {
    int key;
    struct node *left, *right; //pointer to left and right child
};

struct node* newNode(int key){
    struct node* temp = (struct node*) malloc(sizeof (struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    // if the tree is empty return a new node, aka become the parent
    if (node == NULL){
        return newNode(key);
    }

    // go down in tree
    if(key < node->key){
        node->left = insert(node->left, key);
    } else if (key > node->key){
        node->right = insert(node->right, key);
    }

    // return the unchanged pointer
    return node;
}

void inorder(struct node* node){
    if(node != NULL) {
        // follow the pointers
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 70);
    insert(root, 32);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 70);
    insert(root, 69);

    // print inorder traversal
    inorder(root);
    return 0;

}