#include <stdio.h>
#include <stdlib.h>

//Binary tree using array traversal

void create(int *t, int x);
void preorder(int *t, int x);
void inorder(int *t, int x);
void postorder(int *t, int x);

int main()
{
    int i;
    int t[100];
    for(i=0; i<100; i++){
        t[i] = -1; }
    create(t,1);
    printf("\nPreorder: ");
    preorder(t, 1);
    printf("\nInorder: ");
    inorder(t, 1);
    printf("\nPostorder: ");
    postorder(t, 1);
    return 0;
}

void create(int *t, int x){
    int num;
    printf("\nEnter the value: ");
    scanf("%d", &num);
    if(num == -1)
        return;
    t[x] = num;
    printf("LST of %d",t[x]);
    create(t,2*x);
    printf("RST of %d",t[x]);
    create(t,2*x+1);
    return;
}

void preorder(int *t,int x){
    if(t[x]!=-1){
        printf("%d ",t[x]);
        preorder(t,2*x);
        preorder(t,2*x+1);
    }
}

void inorder(int *t,int x){
    if(t[x]!=-1){
        inorder(t,2*x);
        printf("%d ",t[x]);
        inorder(t,2*x+1);
    }
}

void postorder(int *t,int x){
    if(t[x]!=-1){
        postorder(t,2*x);
        postorder(t,2*x+1);
        printf("%d ",t[x]);
    }
}





