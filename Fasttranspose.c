#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
    
}sparse;
sparse matrix[100];
sparse trans[100];
int avail=1;
int col;
void create(int r,int c,int arr[][col]){
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j!=0]){
                matrix[avail].row=i;
                matrix[avail].col=j;
                matrix[avail++].val=arr[i][j];
                cnt++;
            }
        }
        matrix[0].row=r;
        matrix[0].col=c;
        matrix[0].val=cnt;
    }
}


void display(sparse m[]){
    int n=m[0].val;
    for(int i=1;i<=n;i++){
        printf("Row:- %d\n",m[i].row);
          printf("Col:- %d\n",m[i].col);
            printf("Val:- %d\n",m[i].val);
        
    }
}

void ftranspose(sparse a[],sparse b[]){
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    if(a[0].val){
        int index[a[0].col+1];
        int count[a[0].col];
        for(int i=0;i<a[0].col;i++){
            count[i]=0;
        }
        for(int i=1;i<=a[0].val;i++){
            count[a[i].col]++;
        }
        index[0]=1;
        for(int i=1;i<=a[0].val;i++){
            index[i]=index[i-1]+count[i-1];
        }
        for(int i=1;i<=a[0].val;i++){
            int j=index[a[i].col]++;
            b[j].col=a[i].row;
            b[j].row=a[i].col;
            b[j].val=a[i].val;
        }
    }
    
}

void main(){
    int row;
    printf("Enter the number of row:-\n");
    scanf("%d",&row);
    printf("Enter the number of  col:-\n");
    scanf("%d",&col);
    int arr[row][col];
    printf("Enter the elements of array\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter the %d and %d element of matrix\n:-",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    
    create(row,col,arr);
    ftranspose(matrix,trans);
    display(trans);
    
    
    
}
