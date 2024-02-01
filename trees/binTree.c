// creating a binary tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Function to check if the tree is empty 
int isEmpty(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    return 0;
}

// Function to check if Node has parent 
bool hasParent(struct Node* node) {
    if (node->parent == NULL) {
        return false;
    }
    return true;
}

// Function to check if Node has left child 
bool hasLeftChild(struct Node* node) {
    if (node->left == NULL) {
        return false;
    }
    return true;
}

// Function to check if Node has right child 
bool hasRightChild(struct Node* node) {
    if (node->right == NULL) {
        return false;
    }
    return true;
} 

// Function to check if Node is a leaf 
bool isLeaf(struct Node* node) {
    if (node->left == NULL && node->right == NULL) {
        return true;
    }
    return false;
}

// Function to check if Node has any children
bool hasChildren(struct Node* node) {
    if (node->left != NULL || node->right != NULL) {
        return true;
    }
    return false;
}

// EX 10.3-2 Function that prints the data in each node of the tree 
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// EX 10.3-3 non-recursive function that, given n-node binary tree, prints
// the key of each node. Use a stack as auxiliary storage.
void printTreeNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function that checks if key is in tree 
struct Node* searchTree(struct Node* root, int key) {
    if (root->data == NULL || key == root->data) {
        return root;
    }
    if (key < root->data) {
        return searchTree(root->left, key);
    } else {
    return searchTree(root->right, key);
    }
    
}

struct Node* searchTreeNonRecursive(struct Node* root, int key) {
    while (root != NULL && key != root->data) {
        if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

// Function that return minimum key in tree
struct Node* treeMinimum(struct Node* x) {
    while (x->right != NULL) {
        x = x->left;
    }
    return x;
}

// Function that returns maximum key in tree
struct Node* treeMaximum(struct Node* x) {
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}

// Function that returns successor of node x
struct Node* treeSuccessor(struct Node* x) {
    if (x->right != NULL) {
        return treeMinimum(x->right);
    } else {
        struct Node* y = x->parent;
        while (y != NULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;

    }
}