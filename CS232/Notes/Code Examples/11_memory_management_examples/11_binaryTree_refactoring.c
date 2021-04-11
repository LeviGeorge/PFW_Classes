#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#define TOTAL_NUMBER 1000

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insertValue(int value, struct node *root);
void destroyTree(struct node *root);
void printTree(struct node *root);
void createNode(int value, struct node **newNode);

int main(){
    struct node *root = NULL;
    createNode(0, &root);
    if(root == NULL){
        return -1;
    }
 
    srand(time(NULL));
    for(int i = 0; i < TOTAL_NUMBER; i++){
        insertValue(rand() - (RAND_MAX / 2), root);
    }

    printTree(root);

    destroyTree(root);

    return 0;
}

void insertValue(int value, struct node *root){
    if(value > root->data){
        /* take right branch */
        if(root->right == NULL){
            /* add the new node here */
            struct node *newNode = NULL;
            createNode(value, &newNode);
            if(newNode == NULL){
                fprintf(stderr, "ERROR: could not allocate memory\n");
                return;
            }
            root->right = newNode;
        } else {
            insertValue(value, root->right);
        }
    } else {
        /* take left branch */
        if(root->left == NULL){
            /* add the new node here */
            struct node *newNode = NULL;
            createNode(value, &newNode);
            if(newNode == NULL){
                fprintf(stderr, "ERROR: could not allocate memory\n");
                return;
            }
            root->left = newNode;
        } else {
            insertValue(value, root->left);
        }
    }
}

void destroyTree(struct node *root){
    if(root == NULL){
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

void printTree(struct node *root){
    if(root == NULL){
        return;
    }

    printTree(root->left);
    printf("%d\n", root->data);
    printTree(root->right);
}

void createNode(int value, struct node **newNode) {
    *newNode = malloc(sizeof(struct node));
    if(*newNode == NULL){
        return;
    }

    (*newNode)->data = value;
    (*newNode)->left = NULL;
    (*newNode)->right = NULL;
}
