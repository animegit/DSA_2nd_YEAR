#include <stdio.h>;
#define swap(x,y,t)((t)=(x),(x)=(y),(y)=(t));

void sort(int arr[],int n){
    int temp=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min],temp);
    }
}

void main(){
    int n;
   
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
     int arr[n];
    printf("Enter the elements in array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    printf("Array after performing selection sort is:- \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    
}
