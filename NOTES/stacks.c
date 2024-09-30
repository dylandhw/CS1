// playing with stacks 
#include <stdio.h>
#define size 6
int stack[size];
int top;

void PUSH(int ele){
    if (top >= size-1){ // check if the stack is full by comparing the top to the size
        printf("FULL!!!"); // size-1 because indices start at 0
        return;
    } else {
        stack[++top] = ele;
    }
}

int POP(){
    if(top < 0){
        printf("EMPTY!!!");
        return 0;
    } else {
        return stack[top--];
    }
}

void display(){
    printf("Current Stack:\n");
    for(int i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }
}

int main(void)
{
    int ele;
    char ch;
    top = -1;
    while(1)
    {
        printf("\npress e for Push, press p for POP, press d for displaying, press x for Exit\nEnter your choice: ");
        scanf("%c",&ch);
        if(ch=='x')
        {
            printf("<<EXIT>>");
            break;
        }
        else if (ch=='e')
        {
            printf("Enter an element to PUSH in the stack: ");
            scanf("%d",&ele);
            PUSH(ele);
        }
        else if (ch=='p')
        {
            ele = POP();
            if(ele!=0 )
            {
                printf(" ITEM POPED :%d ",ele);
            }
        }
        else if(ch=='d')
        {
            display();
        }
        char c;
        //the following line is the flush the enter key from the above input, so that the next %c scanf does not skip taking input
        while((c=getchar())!= '\n' && c !=EOF);
    }
	return 0;
}
