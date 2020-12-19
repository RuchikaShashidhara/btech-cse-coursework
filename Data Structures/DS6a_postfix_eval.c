#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

//Conversion of infix to postfix, Postfix expression evaluation
  
// Stack type 
typedef struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}Stack; 
  
// Stack Operations 
Stack* createStack( unsigned capacity ) 
{ 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
  
    if (!stack)
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array)
        return NULL; 
  
    return stack; 
} 
  
int isEmpty(Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
char peek(Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
  
char pop(Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
  
void push(Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  
// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    Stack* stack = createStack(strlen(exp)); 
    int i; 
  
    // See if stack was created successfully 
    if (!stack)
        return -1; 
  
    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 
  
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2 / val1); break; 
            } 
        } 
    } 
    return pop(stack); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    char exp[] = "231*+9-"; 
    printf ("postfix evaluation: %d", evaluatePostfix(exp)); 
    return 0; 
} 
