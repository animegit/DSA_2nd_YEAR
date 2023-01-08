 
#include<stdio.h>
int search(int arr[],int s,int e,int key){
    if(s>e){
        return -1;
    }
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            return search(arr,mid+1,e,key);
        }
        else{
            return search(arr,s,mid-1,key);
        }
    }
    
}
void main(){
    int n,key;
    printf("Enter the number of elements in array");
    scanf("%d",&n);
     int arr[n];
     printf("Enter the elements of array:-");
     for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
     }
     printf("Enter the key element to perform bs");
     scanf("%d",&key);
     int res=search(arr,0,n,key);
     if(res>=0){
         printf("Element found in postion %d",res+1);
         
     }
     else{
         printf("Element not found");
     }
     
}
