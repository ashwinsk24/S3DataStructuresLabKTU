#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i,j,k,temp=0,A[10];
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    for(i=0;i<n-1;i++){  //sort
       for(j=0;j<n-i-1;j++){
         if(A[j]>A[j+1]){
           temp = A[j];
           A[j] = A[j+1];
           A[j+1] = temp;
         }
       }
     }
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
}
