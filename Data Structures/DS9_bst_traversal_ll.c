#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left,*right;
} Node;

Node* create_tree();
void preorder(Node* t);
void inorder(Node* t);
void postorder(Node* t);
int leafcount(Node *t);
int height(Node* t);

int main(){
    Node *root;
    int leaves, h;
    root = create_tree();
    printf("\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    leaves = leafcount(root);
    printf("\nLeaves: %d", leaves);
    h = height(root);
    printf("\nHeight: %d", h);
    return 0;
}

Node* create_tree(){
    Node *temp;
    int x;
    printf("\nEnter value: ");
    scanf("%d", &x);
    if(x == -1)
        return NULL;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    printf("\nLST of %d: ",x);
    temp->left = create_tree();
    printf("\nRST of %d: ",x);
    temp->right = create_tree();
    return temp;
}

void preorder(Node* t){
    if(t != NULL){
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(Node* t){
    if(t != NULL){
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void postorder(Node* t){
    if(t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

int leafcount(Node *t){
    int lcount, rcount;
    lcount = rcount = 0;
    if(t != NULL){
        if((t->left == NULL) && (t->right == NULL))
            return 1;
        lcount = leafcount(t->left);
        rcount = leafcount(t->right);
        return lcount + rcount;
    }
    return 0;
}

int height(Node* t){
    int lcount, rcount;
    lcount = rcount = 0;
    if(t != NULL){
        if((t->left == NULL) && (t->right == NULL))
            return 0;
        lcount = height(t->left);
        rcount = height(t->right);
        if(lcount > rcount)
            return lcount+1;
        return rcount+1;
    }
    return -1;
}





