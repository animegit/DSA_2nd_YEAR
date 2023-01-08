#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int key;
}element;
element *queue;
int front=-1,rear=-1;
int capacity=10;
//TO insert a element in queue
void insert(element item){
    if(front==capacity){
        queuefull(queue);
    }
    queue[++rear]=item;
}
//TO delete a element in queue
int delete(){
    if(front>rear){
        printf("Queue is Empty\n");
        exit(0);
    }
    return queue[++front].key;
}

void queuefull(element *q){
  q=realloc(q,2*capacity*sizeof(element));
  capacity*=2;
}
void display(){
    int r=rear;
    int f=front;
    for(int i=f+1;i<=r;i++){
        printf("%d\n",queue[i].key);
        
    }
}


 void main(){
    queue=(element*)malloc(10*sizeof(element));
    int op;
    while(op!=4){
        printf("Enter your choice:-\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        element add;
        scanf("%d",&op);
        if(op==1){
            printf("Enter the element to insert:-\n");
            scanf("%d",&add.key);
            insert(add);
        }
        else if(op==2){
            printf("Deleted element is:- %d\n",delete());
        }
        else if(op==3){
            printf("Elements in Queue are:-\n");
            display();
        }
    }
    free(queue);
}

