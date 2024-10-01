/*  COP3502C
    Dylan Wilkins
    Lab 5, 09/30/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#define SIZE 100
#define EMPTY -1

struct stack {
    char items[SIZE];
    int top;
};

void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
int push(struct stack* stackPtr, char value);
int empty(struct stack* stackPtr);
char pop(struct stack* stackPtr);
int peek(struct stack* stackPtr);
void print_stack(struct stack* stackPtr);



int checkBalance(char exp[]);
int priority(char ch);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
int isParentheses(char ch1);

int checkBalance(char exp[]){
    int valid = 1;
    struct stack mine;
    initialize(&mine);
    /*if a (, {, or[, is found, push it to the stack, then pop and determine if there is
    a completing bracket/parantheses. print appropriate message*/
    printf("Checking balance...\n");
    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&mine, exp[i]);
        } else if (exp[i] == ')'){
            char x = pop(&mine);
            if(x != '('){
                valid = 0;
                printf("INVALID for )!!!\n");
                return valid;
            }
        } else if (exp[i] == '}'){
            char x = pop(&mine);
            if(x != '{'){
                valid = 0;
                printf("INVALID for }!!!\n");
                return valid;
            }
        } else if (exp[i] == ']'){
            char x = pop(&mine);
            if(x != '['){
                valid = 0;
                printf("INVALID for ]!!!\n");
                return valid;
            }
        }
    }
    if(pop(&mine)!='I'){
        valid = 0;
        printf("INVALID. You have extra!!!\n");
    }
    if(valid == 1){
        printf("VALID\n");
    }
}

int main(void) {
    int ch;
    char exp[SIZE], c;

    int valid;
    /*takes in expression, checks balance, prints the postfix if its valid*/
     printf("Enter Expression: ");
     scanf("%[^\n]s",exp);
     printf("Your input expression: %s\n", exp);
     valid = checkBalance(exp);
     if(valid)
     {
         char * postfix = infixToPostfix(exp);
         printf("The postfix is: %s\n", postfix);

         free(postfix);
     }

    return 0;
}


/*Prints the current stack*/
void print_stack(struct stack* stackPtr) {
     for(int i=0; i<=stackPtr->top; i++)
        printf("%c-->", stackPtr->items[i]);

     printf("\n");
}

/*Initializes the stack*/
void initialize(struct stack* stackPtr) {
     stackPtr->top = -1;
}

// If the push occurs, 1 is returned. If the
// stack is full and the push can't be done, 0 is
// returned.
int push(struct stack* stackPtr, char value) {

    // Check if the stack is full.
    if (full(stackPtr))
        return 0;

    // Add value to the top of the stack and adjust the value of the top.
    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}

// Returns true iff the stack pointed to by stackPtr is full.
int full(struct stack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}

// Returns true iff the stack pointed to by stackPtr is empty.
int empty(struct stack* stackPtr) {
    return (stackPtr->top == -1);
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char pop(struct stack* stackPtr) {

    char retval;

    // Check the case that the stack is empty.
    if (empty(stackPtr))
        return 'I';

    // Retrieve the item from the top of the stack, adjust the top and return
    // the item.
    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
int peek(struct stack* stackPtr) {

    // Take care of the empty case.
    if (empty(stackPtr))
        return EMPTY;

    // Return the desired item.
    return stackPtr->items[stackPtr->top];
}


char *infixToPostfix(char infix[])
{
    struct stack operators;
    initialize(&operators);
    int counter = 0;

    char* postfix = malloc(strlen(infix+1)*2);

    int length = strlen(infix);

    for(int i = 0; i < length; i++)
    {
        
        if(isdigit(infix[i]))
        {
            //to deal with multiple digits
            //keep adding as long as it is a digit
            while(isdigit(infix[i])) 
            {
                postfix[counter] = infix[i];
                i++;
                counter++;
            }
            i--;
            postfix[counter] = ' ';
            counter++;
            
        }
          
        else if(isOperator(infix[i]))
        {
            //push if stack is empty
            if(empty(&operators)){
                push(&operators, infix[i]);
            }
                

            //if the priority is higher than the top of the stack, pushing it to operators stack
            else if(priority(infix[i]) > priority(peek(&operators))){
                push(&operators, infix[i]);
            }
    

            //if priority is lower or equal, popping the stack into the postfix until it is empty or the priority of the char is
            //higher than the one from the top of stack
            else
            {
                //loop keeps going as long as stack is not empty, and prioirty of current operator is <= top of stack, and top of stack is not a parentheses
                while(!empty(&operators) && priority((infix[i])) <= priority(peek(&operators)) && !isParentheses(peek(&operators)))
                {
                    postfix[counter] = pop(&operators);
                    counter++;
                    postfix[counter] = ' ';
                    counter++; 
                }

                push(&operators, infix[i]);
            }
        }
        //checks if the char is a parentheses
        else if(infix[i]=='(' || infix[i]==')')
        {
            //if it is an open parentheses pushes it to operators
            if(infix[i]=='(')
                push(&operators, infix[i]);
                
            //if not, pops the operators stack into the postfix until it gets to an open parentheses.
            else
            {
                while(peek(&operators) != '(')
                {
                  postfix[counter] = pop(&operators);
                  counter++;
                  postfix[counter] = ' ';
                  counter++;
                }
                pop(&operators);
                
            }
        }

    } // end of iterating through the the infix

    
    //pops all the operators left in the stack and adds white spaces between them.
    //this is your job to finish on your own
    while(!empty(&operators))
    {
      postfix[counter] = pop(&operators);
      counter++;
      postfix[counter] = ' ';
      counter++;
    }
    //do not forget to put the null terminator to the end of postfix
    postfix[counter] = '\0';
  //return postfix expression  

  return postfix;
}


// returns the priority of the passed character
// (  {  [  : 0
// + - : 1
// * / %: 2
// ^ : 3
int priority(char ch)
{
    if(ch == '(' || ch == '{' || ch == '[') 
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/' || ch == '%')
        return 2;
    if(ch =='^') 
        return 3;
}

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return 1;
    return 0;
}

int isParentheses(char ch1)
{
    if(ch1 == '(' ||ch1 == ')' || ch1 == '{' || ch1 == '}' || ch1 == '[' || ch1 == ']') 
      return 1;
    return 0;
}