#include <stdio.h>
#include <stdlib.h>

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

void push(struct stack*ptr,char val){
    if(isFull(ptr)){
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

void pop(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow");
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
    }
}

int parenthesisMatch(char exp){
    struct stack* ptr;
    ptr->size=100;
    ptr->top=-1;
    ptr->arr=(char)malloc(ptr->size*sizeof(char));
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(ptr,exp[i]);
        }
        else if(exp[i]==')'){
            if (isEmpty(ptr)) return 0;
            else pop(ptr);
        }
    }
    if(isEmpty(ptr)) return 1;
}

int main()
{
//    char ch;
	char exp;
    printf("Enter the expression:");
    scanf("%c",&exp);
    char *exp=&ch;
//    Check if the stack is empty
    if (parenthesisMatch(exp))printf("The parenthesis are matching");
    else printf("The parenthesis are not matching");

    return 0;
}
