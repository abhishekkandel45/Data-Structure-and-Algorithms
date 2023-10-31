//Longest Valid Parentheses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int len =strlen(s);
    char *stack = (char *)malloc(sizeof(char)*len);
    int top = -1;               //index of top element
    int max = 0;                //max lenght od Valid Parentheses
    int i = 0;                  //Index of the current Elelement in the string
    int start = 0;
    while(i < len){
        if(s[i] == '('){
            stack[++top] = i;
        }else{
            if(top == -1){
                start = i+1;
            }else{
                top--;
                if(top == -1){
                    max = max > i-start+1 ? max : i-start+1;  
                }else{
                    max = max > i-stack[top] ? max : i-stack[top];
                }
            }
        }
        i++;
    }
    return max;
}


int main(){
    printf("Enter the string: ");
    char *s = (char *)malloc(sizeof(char)*100);
    scanf("%s",s);
    printf("Longest Valid Parentheses: %d\n",longestValidParentheses(s));
    return 0;
}