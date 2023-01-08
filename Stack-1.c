#include<stdio.h>
typedef struct{
    int key;
}element;
element *stack;
int top=-1;
int capacity=10;
void push(element item){
    if(top==capacity){
        stackfull(stack);
    }
    else{
        stack[++top]=item;
    }
}
stackfull(element *stk){
    stk=realloc(stk,2*capacity*sizeof(element));
    capacity*=2;
}
int pop(){
    if(top==-1){
        printf("Stack is empty\n");
        exit(0);
    }
    return stack[top--].key;
}
void display(){
    int n=top;
    while(n!=-1){
        printf("%d\n",stack[n--].key);
    }
}

void main(){
    stack=(element*)malloc(10*sizeof(element));
    int op;
    while(op!=4){
        printf("Enter your choice:-\n");
        printf("1.Push\n2.pop\n3.Display\n4.Exit\n");
        element add;
        scanf("%d",&op);
        if(op==1){
            printf("Enter the element to push:-\n");
            scanf("%d",&add.key);
            push(add);
        }
        else if(op==2){
            printf("Popped element is:- %d\n",pop());
        }
        else if(op==3){
            printf("Elements in stack are:-\n");
            display();
        }
    }
    free(stack);
}
