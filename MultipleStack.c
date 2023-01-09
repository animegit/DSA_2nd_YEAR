#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int val;
}element;

typedef struct node{
    element data;
    struct node* link;
}node;

node* top[50];

void push(element item,int i){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=item;
    temp->link=top[i];
    top[i]=temp;
    
}

element pop(int i){
    node* temp=top[i];
    element item;
    if(temp==NULL){
        item.val=-1;
        return item;
    }
    else{
        top[i]=temp->link;
        item=temp->data;
        free(temp);
        return item;
    }
}


void display(int i){
node* temp=top[i];
for(;temp;temp=temp->link){
    printf("%d\n",(temp->data).val);
}
printf("\n");
}

void main(){
    
    for(int i=0;i<50;i++){
        top[i]=0;
    }
    int op,i;
    while(op!=4){
        printf("Enter your choice \n");
        printf("1.push\n2.pop\n3.display\n4.exit");
        scanf("%d",&op);
        element add;
        if(op==1){
            printf("Enter the stack number\n");
            scanf("%d",&i);
            printf("Enter the element to push\n");
            scanf("%d",&add.val);
            push(add,i);
        }
        else if(op==2){
              printf("Enter the stack number\n");
              scanf("%d",&i);
              printf("Popped out element is:-%d",pop(i).val);
              
        }
        else if(op==3){
            printf("Enter the stack to display\n");
            scanf("%d",&i);
            display(i);
        }
    }
}
