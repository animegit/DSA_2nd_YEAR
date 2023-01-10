#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int val;
}element;

typedef struct node{
    element data;
    struct node* link;
}node;
node* front[50];
node* rear[50];

void insert(element item,int i){
     node* temp;
     temp=(node*)malloc(sizeof(node));
     if(front[i]){
         rear[i]->link=temp;
     }
     else{
         front[i]=temp;
     }
     rear[i]=temp;
}

element delete(int i){
    node* temp;
    temp=front[i];
    element item;
    if(front[i]){
        item=front[i]->data;
        front[i]=front[i]->link;
        
    }
    else{
        item.val=-1;
    }
    free(temp);
    return item;
}

void display(int i){
    node* temp;
    temp=front[i];
    for(;temp;temp=temp->link){
        printf("%d\n",(temp->data).val);
    }
}


void main(){
    int op,i;
    while(op!=4){
        printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
        scanf("%d",&op);
        element add;
        if(op==1){
            printf("Enter the queue number to insert\n");
            scanf("%d",&i);
            printf("Enter the element to insert\n");
            scanf("%d",&add.val);
            insert(add,i);
        }
        if(op==2){
            printf("Enter the queue number to delete\n");
            scanf("%d",&i);
            delete(i);
        }
        if(op==3){
            printf("Enter te queue number to display\n");
            display(i);
        }
    }
}
