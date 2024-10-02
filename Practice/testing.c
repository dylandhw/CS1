#include <stdio.h>
#include <stdlib.h>
#define size 6
int stack[size];
int top;


void PUSH(int ele){
    if(top >= size){
        printf("??EMPTY??\n");
        return;
    } else {
        stack[++top] = ele;
    }
}

int POP(){
    if(top < 0){
        return -999;
    } else {
        return stack[top--];
    }
}

void display(){
    if(top < 0){
        printf("!!EMPTY!!\n");
    } else {
        for(int i = 0; i < top; i++){
            printf("%d ", stack[i]);
        }
    }
}

int main(void)
{
    int ele;
    char ch;
    top = -1;
    while(1)
    {
        printf("<<E = PUSH>>");
        printf("<<P = POP>>");
        printf("<<D = DISPLAY>>");
        printf("<<X = PUSH>>");

        scanf("%c",&ch);
        if(ch=='x')
        {
            printf("<<EXIT>>");
            break;
        }
        else if (ch=='e')
        {
            printf("<<ELEMENT>>");
            scanf("%d",&ele);
            PUSH(ele);
        }
        else if (ch=='p')
        {
            ele = POP();
            if(ele!=0 )
            {
                printf("<<ITEM POPED :%d >>",ele);
            }
        }
        else if(ch=='d')
        {
            display();
        }
        
    }
	return 0;
}