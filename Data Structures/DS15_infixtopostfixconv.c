#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Infix expression to Postfix expression conversion

//Stack type
typedef struct Stack{
    int top;
    unsigned capacity;
    int *array;
}Stack;

//Stack Operations
Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
    if(!stack)
        return NULL;
        
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    
    if(!stack->array)
        return NULL;
        
    return stack;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

char peek(Stack* stack){
    return stack->array[stack->top];
}

char pop(Stack* stack){
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack* stack, char op){
    stack->array[++stack->top] = op;
}

//Returns 1 if ch is a character between a-zA-Z
int isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

//Returns the precedence of ch - higher value returned implies higher precedence
int prec1(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

//Infix expression to Postfix expression conversion
int InfixToPostfix(char *exp){
    int i, k;
    
    // Create a Stack of capacity equal to expression size 
    Stack* stack = createStack(strlen(exp));
    if(!stack) // See if Stack was created successfully
        return -1;
        
    for(i=0, k=-1; exp[i]; i++){
        
        // If the scanned character is an operand, add it to output.
        if(isOperand(exp[i]))
            exp[++k] = exp[i];
            
        // If the scanned character is an ‘(‘, push it to the Stack.
        else if(exp[i]=='(')
            push(stack, exp[i]);

        // If the scanned character is an ‘)’, pop and output from the Stack until an '(' is found
        else if(exp[i]==')'){
            while(!isEmpty(stack) && peek(stack)!='(')
                exp[++k] = pop(stack);
            if(!isEmpty(stack) && peek(stack)!='(')
                return -1; //invalid expression
            else
                pop(stack);
        }
        else{ //an operator is encountered
            while(!isEmpty(stack) && (prec1(exp[i])<=prec1(peek(stack))))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    //pop all the operators from the Stack
    while(!isEmpty(stack))
        exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf("%s", exp);
}

int main(){
    //char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    char exp[] = "a+b*d*(c-e)";
    InfixToPostfix(exp);
    return 0;
}




    
