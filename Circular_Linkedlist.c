#include<stdio.h>
typedef struct node{
    int data;
    struct node* link;
    
}node;

struct node* head=0;

void insertFirst(int data){
    node *temp;
    temp=(node*)malloc(sizeof(temp));
    if(head==NULL){
        temp->data=data;
        temp->link=temp;
        head=temp;
    }
    else{
        temp->data=data;
        temp->link=head->link;
        head->link=temp;
    }
}

void insertafter(int data){
    int val;
    struct node *temp,*n;
    temp=head->link;
    printf("Enter the value to you want to inser after which element\n");
    scanf("%d",&val);
    do{
        if(temp->data==val){
            n=(struct node*)malloc(sizeof(struct node));
            n->data=data;
            n->link=temp->link;
            temp->link=n;
            if(temp==head){
                head=n;
                break;
            }
            else{
                temp=temp->link;
            }
        }
    }while(temp!=head->link);
}


void delete(){
    int pos,i=1;
    struct node *temp,*target;
    temp=head->link;
    if(head==NULL){
        printf("List is empty.\n");
    }else{
    printf("Enter the index\n");
    scanf("%d",&pos);
    while(i<=pos-1){
        temp=temp->link;
        i++;
    }
    target =temp->link;
    temp->link=target->link;
    free(target);
}}

void viewlist(){
    struct node *temp;
    temp=head->link;
    if(head==NULL){
        printf("List is empty.\n");
        
    }
    else{
        do{
            printf("%d->",temp->data);
            temp=temp->link;
        }while(temp!=head->link);
    }
}

void main(){
    while(1){
        printf("1.InsertFirst \n2.InsertAfter\n3.DeleteNode\n4.View\n5.Exit\n");
        int op,val;
        scanf("%d",&op);
        if(op==1){
            printf("Enter the element to insertFirst\n");
            scanf("%d",&val);
            insertFirst(val);
        }
        else if(op==2){
            printf("Enter the element to insert \n");
            scanf("%d",&val);
            insertafter(val);
            
        }
        else if(op==3){
            delete();
        }
        else if(op==4){
            viewlist();
        }
        else{
            break;
        }
        
    }
}
