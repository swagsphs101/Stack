#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack*ptr){
    if(ptr->top==-1) return 1;
    else return 0;
}

int isFull(struct stack*ptr){
    if(ptr->top==ptr->size-1) return 1 ;
    else return 0;
}

void push(struct stack*ptr,int val){
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
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
    }
}

void display(struct stack* ptr){
    int i=0;
    while(i!=ptr->top){
        printf("%d ",ptr->arr[i]);
        i++;
    }
    printf("%d ",ptr->arr[ptr->top]);
	printf("\n");
}

void peek(struct stack*ptr,int pos){
	int arrayIndex=ptr->top-pos+1;
	if(arrayIndex<0) printf("Not a valid position for the array");
	else printf("%d\n",ptr->arr[arrayIndex]);
}

int main()
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 5;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    printf("Stack has been created successfully\n");
     while(1){
              int choice;
              printf("1.Push\n");
              printf("2.Pop\n");
              printf("3.Display\n");
              printf("4.Peek\n");
              printf("5.Exit\n");
              printf("Enter your choice:");  
              scanf("%d", &choice);
            switch(choice){
                case 1:
                {
                    int val;
                    printf("Enter the value you want to push");
                    scanf("%d",&val);
                    push(ptr,val);
                    printf("Element has been pushed successfully\n");
                    break;
                }
                case 2:
                {
                    pop(ptr);
                    printf("Elemenet popped successfully\n");
                    break;
                }
                case 3:
                {   
                    display(ptr);
                    break;
                }
                case 4:
                {   int pos;
                    printf("Enter the postion to see the value");
                    scanf("%d",&pos);
                	peek(ptr,pos);
                	break;
				}
                case 5:
                {
                    printf("Exiting the program\n");
                    exit(0);
                    break;
                }
                default:
                      printf("Invalid input\n");

               }
            }
        return 0;
}
