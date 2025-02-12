#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{
    int size;
    int top;
    char *data;
}Stack;
typedef struct
{
    int size;
    int top;
    int *data;
}StackNum;

int isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
int isEmptyNum(StackNum *s){
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
int isFullNum(StackNum *s){
    if((s->top+1) == s->size){
        int newSize = s->size / 2;
        s->size += newSize;
        s->data = (int *)realloc(s->data,s->size * sizeof(int));
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
void pushNum(StackNum* s,char data){
    if(isFullNum(s)){
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
int peakNum(StackNum* s){
    if(isEmptyNum(s)){
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
int popNum(StackNum *s){
    if(isEmptyNum(s)){
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
StackNum* createStackNum(){
    StackNum *s = (StackNum *)malloc(sizeof(StackNum));
    s->top = -1;
    s->size = 5;
    s->data = (int *)malloc(s->size * sizeof(int));
    return s;
}
int isAlpha(char ch){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')  
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
void infixToPostfix(Stack *s1,char *expresion,char *postfix){
    int idx = 0;
    for(int i = 0; i < strlen(expresion); i++){
        if(isAlpha(expresion[i])){
            postfix[idx++] = expresion[i];
            
        }
        else if(expresion[i] == '('){
            push(s1,'(');
        }
        else if(expresion[i] == ')'){
            while (!isEmpty(s1) && peak(s1) != '(')
            {
                postfix[idx++] = pop(s1);
            }
            pop(s1);
        }
        else{
            while (!isEmpty(s1) && checkPrecidence(s1->data[s1->top]) > checkPrecidence(expresion[i])){
                postfix[idx++] = pop(s1);
            }
            push(s1,expresion[i]);
        }
    }
    while (!isEmpty(s1))
    {
        postfix[idx++] = pop(s1);
    }
    postfix[idx] = '\0';
}
void infixToPrefix(Stack *s1,char *expresion,char *prefix){
    reverse(expresion,strlen(expresion)); 
    int idx = 0;
    for(int i = 0; i < strlen(expresion); i++){
        if(isAlpha(expresion[i])){
            prefix[idx++] = expresion[i];
        }
        else if(expresion[i] == ')'){
            push(s1,')');
        }
        else if(expresion[i] == '('){
            while (!isEmpty(s1) && peak(s1) != ')')
            {
                prefix[idx++] = pop(s1);
            }
            pop(s1);
        }
        else{
            while (!isEmpty(s1) && checkPrecidence(s1->data[s1->top]) >= checkPrecidence(expresion[i])){
                prefix[idx++] = pop(s1);
            }
            push(s1,expresion[i]);
        }
    }
    while (!isEmpty(s1))
    {
        prefix[idx++] = pop(s1);
    }
    reverse(prefix,idx);
    prefix[idx] = '\0';
}
int isDig(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
int solve(char *postFix,int isPrefix){
    StackNum *s = createStackNum();
    if(isPrefix)
        reverse(postFix,strlen(postFix));
    for(int i = 0; postFix[i] != '\0'; i++){
        char ch = postFix[i];
        if(isDig(ch)){
            pushNum(s,ch - '0');
        }
        else{
            int oprand1,oprand2;
            if(isPrefix){
                oprand2 = popNum(s);
                oprand1 = popNum(s);
            }
            else{
                oprand1 = popNum(s);
                oprand2 = popNum(s);
            }
            switch (ch)
            {
                case '+':
                    pushNum(s,oprand2 + oprand1);
                    break;
                case '-':
                    pushNum(s,oprand2 - oprand1);
                    break;
                case '*':
                    pushNum(s,oprand2 * oprand1);
                    break;
                case '/':
                    pushNum(s,oprand2 / oprand1);
                    break;
                default:
                    break;
            }
        }
    }
    return popNum(s);
}

int main(){
    Stack *s1 = createStack();
    char expresion[] = "2*4/2*2";

    char postfix[strlen(expresion)];
    char prefix[strlen(expresion)];

    infixToPostfix(s1,expresion,postfix);
    infixToPrefix(s1,expresion,prefix);

    printf("\nPost : %s",postfix);
    printf("\nPre : %s",prefix);

    printf("\n\nPost Fix Answer : %d ",solve(postfix,0));
    printf("\n\nPre Fix Answer : %d ",solve(prefix,1));
}