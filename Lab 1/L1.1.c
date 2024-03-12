/*	Write a program to construct a binary tree to support the following operations. Assume no duplicate elements while constructing the tree.
i.	Given a key, perform a search in the binary search tree. If the key is found then display “key found” else insert the key in the binary search tree. */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data=key;
    newNode -> left = newNode -> right = NULL;
    return newNode;
};

struct Node* insert(struct Node* root, int key){
    if (root == NULL){
        return createNode(key);
    }

    if (key < root -> data){
        root -> left = insert(root -> left, key);
    } else if (key > root -> data){
        root -> right = insert(root -> right, key);
        }
    return root;
}

void searchKey(struct Node* root, int key){
    if (root == NULL || root-> data == key){
        if (root != NULL){
            printf("Key found! \n");
        } else{
            printf("Key not found, inserting %d \n",key);
        }
        return;
    }

    if (key < root -> data){
        searchKey(root ->left, key);
        } else {
        searchKey(root -> right, key);
        }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int key;
    printf("Enter elements for the binary search tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &key);
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

    printf("In-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Enter a key to search or insert: ");
    scanf("%d", &key);

    searchKey(root, key);

    printf("Updated in-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}
