#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{
    int size;
    int top;
    char *data;
}Stack;

int isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
int isFull(Stack *s){
    if((s->top+1) == s->size){
        int newSize = s->size / 2;
        s->size += newSize;
        s->data = (char *)realloc(s->data,s->size * sizeof(char));
        return 1;
    }
    return 0;
}
void push(Stack* s,char data){
    if(isFull(s)){
        printf("\nSize Increased ");
    }
    s->data[s->top+1] = data;
    s->top++;
}
int peak(Stack* s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return -1;
    }
    return s->data[s->top];
}
char pop(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return ' ';
    }
    return s->data[s->top--];
}
Stack* createStack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = 5;
    s->data = (char *)malloc(s->size * sizeof(char));
    return s;
}
int isAlpha(char ch){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        return 1;
    return 0;
}
int checkPrecidence(char ch){
    if (ch == '+' || ch == '-') 
        return 1;
    else if (ch == '*' || ch == '/') 
        return 2;
    else if (ch == '^') 
        return 3;
    return 0;
}
void reverse(char *expresion,int n){
    for(int i = 0; i < n / 2; i++){
        char ch = expresion[i];
        expresion[i] = expresion[n-i-1];
        expresion[n-i-1] = ch;
    }
} 
int main(){
    Stack *s1 = createStack();
    char expresion[] = "X+Y*(Z-W)";
    reverse(expresion,strlen(expresion)); 
    char postfix[strlen(expresion)];
    int idx = 0;
    for(int i = 0; i < strlen(expresion); i++){
        if(isAlpha(expresion[i])){
            postfix[idx++] = expresion[i];
        }
        else if(expresion[i] == ')'){
            push(s1,')');
        }
        else if(expresion[i] == '('){
            while (!isEmpty(s1) && peak(s1) != ')')
            {
                postfix[idx++] = pop(s1);
            }
            pop(s1);
        }
        else{
            while (!isEmpty(s1) && checkPrecidence(s1->data[s1->top]) >= checkPrecidence(expresion[i])){
                postfix[idx++] = pop(s1);
            }
            push(s1,expresion[i]);
        }
    }
    while (!isEmpty(s1))
    {
        postfix[idx++] = pop(s1);
    }
    reverse(postfix,idx);
}