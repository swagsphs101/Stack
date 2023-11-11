#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* push(struct Node*top,int val){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Stack Overflow");
    }
    else{
        ptr->data=val;
        ptr->next=top;
        top=ptr;
        return top;
    }
}

struct Node* pop(struct Node*top){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        struct Node*ptr=top;
        top=top->next;
        free(ptr);
        return top;
    }
}

void peek(struct Node*top,int pos){
    struct Node* ptr=top;
    int i;
    for(i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL) printf("%d\n",ptr->data);
    else printf("The position you entered doen't exist\n");
}


void display(struct Node*top){
    if(top==NULL){
        printf("Nothing to display\n");
    }
    else{
        struct Node*ptr=top;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

int main(){
    struct Node* top=NULL;
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
                    top=push(top,val);
                    printf("Element has been pushed successfully\n");
                    break;
                }
                case 2:
                {
                    top=pop(top);
                    printf("Elemenet popped successfully\n");
                    break;
                }
                case 3:
                {   
                    display(top);
                    break;
                }
                case 4:
                {   int pos;
                    printf("Enter the postion to see the value");
                    scanf("%d",&pos);
                	peek(top,pos);
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
