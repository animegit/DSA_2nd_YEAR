#include<stdio.h>
typedef struct{
    int row;
    int col;
    int val;
    
}sparse;
sparse matrix[100];
int col;
sparse trans[100];
int avail=1;
// create a triplet form of matrix
void create(int arr[][col],int r,int c){
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0){
                matrix[avail].row=i;
                matrix[avail].col=j;
                matrix[avail++].val=arr[i][j];
                cnt++;
            }
        }
    }
    matrix[0].row=r;
    matrix[0].col=c;
    matrix[0].val=cnt;
    
}

void transpose(sparse a[],sparse b[]){
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    if(a[0].val>0){
           int ptr=1;
    for(int i=0;i<a[0].col;i++){
     
        for(int j=1;j<=a[0].val;j++){
            if(a[j].col==i){
                b[ptr].row=a[j].col;
                b[ptr].col=a[j].row;
                b[ptr++].val=a[j].val;
               
            }
        }
    }
    }
}


void display(sparse r[]){
    int n=r[0].val;
    for(int i=1;i<=n;i++){
        printf("ROW:-%d\n",r[i].row);
         printf("COL:-%d\n",r[i].col);
          printf("VAL:-%d\n",r[i].val);
    }
}
void main(){
    int row;
    printf("Enter the no of rows\n");
    scanf("%d",&row);
    printf("Enter the no of col\n");
    scanf("%d",&col);
    int arr[row][col];
  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
              printf("Enter the element in %d and %d ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    create(arr,row,col);
    transpose(matrix,trans);
    display(trans);
    
}


