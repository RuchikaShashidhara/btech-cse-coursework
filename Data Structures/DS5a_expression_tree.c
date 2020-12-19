#include<stdio.h>
#include<stdlib.h>

//expression tree using infix, conversion through postfix and evaluating postorder

typedef struct tnode
{
char data;
struct tnode *left;
struct tnode *right;
}tnode;

int evaluate(tnode *t){
    int x;
    switch(t->data){
        case '+': return(evaluate(t->left)+evaluate(t->right));
        case '-': return(evaluate(t->left)-evaluate(t->right));
        case '*': return(evaluate(t->left)*evaluate(t->right));
        case '/': return(evaluate(t->left)/evaluate(t->right));
        default:printf("%c=",t->data);
        scanf("%d",&x);
        return x;
    }
}

int isoper(char ch){
    switch(ch){
    case '+':
    case '-':
    case '*':
    case '/':return 1;
    default: return 0;
    }
}

void push(tnode **stk, int *t, tnode* temp){
    ++(*t);
    stk[*t]=temp;
}

tnode *pop(tnode **stk, int *t){
    tnode *temp;
    temp=stk[*t];
    --(*t);
    return temp;
}

void postorder(tnode *t){
    if(t!=NULL){
    postorder(t->left);
    postorder(t->right);
    printf("%c ",t->data);
    }
}

void inorder(tnode *t){
    if(t!=NULL){
    inorder(t->left);
    printf("%c ",t->data);
    inorder(t->right);
    }
}

tnode* create_exptree(char *exp){
    tnode *temp;
    tnode *stk[100];
    int top=-1,i=0;
    while(exp[i]!='\0'){
	    char ch=exp[i];
	    temp=(tnode*)malloc(sizeof(tnode));
	    temp->data=ch;
	    temp->left=temp->right=NULL;
	    if(isoper(ch)){ //if operator
	        temp->right=pop(stk,&top);
	        temp->left=pop(stk,&top);
	        push(stk,&top,temp);
	    }
	    else
	        push(stk,&top,temp);//operand
	    i++;
    }
    return pop(stk,&top);
}

void main()
    {
    struct tnode *root;
    int ch,num,k;
    char exp[100];
    root=NULL;
    printf("Enter the postfix form of the expression...");
    scanf("%s",exp);
    root=create_exptree(exp);
    printf("The infix expression = \n");
    inorder(root);
    printf("\nThe postfix expression = \n");
    postorder(root);
    printf("\nEvaluating the expression\n");
    int result = evaluate(root);
    printf("\nThe evaluation of the expression = %d\n",result);
    return;
}
