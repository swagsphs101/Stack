#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack*ptr){
    if(ptr->top==-1) return 1;
    else return 0;
}

int isFull(struct stack*ptr){
    if(ptr->top==ptr->size-1) return 1 ;
    else return 0;
}

int stackTop(struct stack* ptr){
    return ptr->arr[ptr->top];
}

void push(struct stack*ptr,char val){
    if(isFull(ptr)){
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack*ptr){
    char val;
    if(isEmpty(ptr)){
        printf("Stack Underflow");
    }
    else{
        val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
    }
    return val;
}

int isOperator(char ch){
    if(ch=='^'|| ch=='/'|| ch=='*' || ch=='+' || ch=='-') return 1;
    else return 0;
}

int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='/' || ch=='*') return 2;
    else if (ch=='+' || ch=='-') return 1;
    else return 0;
}

char* InfixToPostfix(char* infix){
    struct stack* ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->size=100;
    ptr->top=-1;
    ptr->arr=(char*)malloc(ptr->size*sizeof(char));

    char*postfix=(char*)malloc(strlen(infix+1)*sizeof(char));

    int i=0; //Infix scanner
    int j=0; //Postfix scanner

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(ptr))){
                push(ptr,infix[i]);
                i++;
            }
            else{
            	while(precedence(infix[i])<=precedence(stackTop(ptr))){
				     postfix[j]=pop(ptr);
                      j++;
				}
                push(ptr,infix[i]);
                i++;
            }
        }
    }
    while(!isEmpty(ptr)){
         postfix[j]=pop(ptr);
         j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
//{   char str[]="A+B*C-D/E^F*G*H";
    char str[50];
    printf("Give the infix expression:");
    scanf("%s",str);
    char* infix=str;
//    printf("%c",*infix);
    printf("The postfix expression is:%s",InfixToPostfix(infix));
    return 0;
}

