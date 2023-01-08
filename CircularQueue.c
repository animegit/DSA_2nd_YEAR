#include<stdio.h>
typedef struct{
    int key;
}element;
element *queue;
int front=0,rear=0;
int capacity=1;
void copy(element *start,element *end,element *newqueue){
    element *i;
    element *j;
    i=newqueue;
    j=start;
    for(;j<end;j++){
        *i=*j;
    }
}

void queuefull(){
    element *newqueue;
    newqueue=(element*)malloc(2*capacity*sizeof(element));
    int start=(front+1)%capacity;
    if(start<2){
        copy(queue+start,queue+start+capacity-1,newqueue);
        
    }
    else{
        copy(queue+start,queue+capacity,newqueue);
        copy(queue,queue+rear+1,newqueue+start-capacity);
    }
    front=2*capacity-1;
    rear=capacity-1;
    capacity*=2;
    free(queue);
    queue=newqueue;
}

void insert(element item){
    rear=(rear+1)%capacity;
    if(rear==front){
        queuefull();
    }
    queue[rear]=item;
}

int delete(){
    if(front==rear){
        printf("Queue is empty");
        exit(0);
    }
    front=(front+1)%capacity;
    return queue[front].key;
   
}
void display(){
    for(int i=(front+1)%capacity;i!=rear;i=(i+1)%capacity){
        printf("%d\n",queue[i].key);
    }
}

void main(){
    queue=(element*)malloc(10*sizeof(element));
    while(1){
        int op;
          printf("1.Enqueue\n2.dequeue\n3.display\n4.exit\n");
    element add;
    scanf("%d",&op);
    if(op==1){
        printf("Enter the element to insert\n");
        scanf("%d",&add.key);
        insert(add);
    }
    else if(op==2){
        printf("Deleted elemet from queue is\n:-%d",delete());
    }
    else if(op==3){
        printf("Elements in queue are:-\n");
        display();
    }
    else{
        break;
    }
    
}}
