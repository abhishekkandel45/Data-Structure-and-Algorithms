//Evaluate postfix Expression using stack in ASCII order

#inclde <stdio.h>
#include <stdlib.h>
#include <string.h>

void push (int  *stack , int  *top , int data){
    stack [++(top)] = data;
}

int pop (int *stack , int *top){
    return stack [(top)--];
}

void evaluatePostfix(char *s){
    int len = strlen(s);
    int *stack = (int *)malloc(sizeof(int)*len);
    int top = -1;
    int i = 0;
    while(i < len){
        if(s[i] >= '0' && s[i] <= '9'){
            push(stack,&top,s[i]-'0');
        }else{
            int a = pop(stack,&top);
            int b = pop(stack,&top);
            switch(s[i]){
                case '+':
                    push(stack,&top,a+b);
                    break;
                case '-':
                    push(stack,&top,b-a);
                    break;
                case '*':
                    push(stack,&top,a*b);
                    break;
                case '/':
                    push(stack,&top,b/a);
                    break;
            }
        }
        i++;
    }
    printf("Result: %d\n",pop(stack,&top));
}

