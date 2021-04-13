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

int main(){
    struct node *root = malloc(sizeof(struct node));
    if(root == NULL){
        return -1;
    }

    root->data = 0;
    root->left = NULL;
    root->right = NULL;
  
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
            struct node *newNode = malloc(sizeof(struct node));
            if(newNode == NULL){
                fprintf(stderr, "ERROR: could not allocate memory\n");
                return;
            }

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;

            root->right = newNode;
        } else {
            insertValue(value, root->right);
        }
    } else {
        /* take left branch */
        if(root->left == NULL){
            /* add the new node here */
            struct node *newNode = malloc(sizeof(struct node));
            if(newNode == NULL){
                fprintf(stderr, "ERROR: could not allocate memory\n");
                return;
            }

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;

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
