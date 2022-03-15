#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i,j,k,temp,A[10];
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("\nInserted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
    for(i=0;i<n-1;i++){ //sort
       k=i;
       for(j=i+1;j<n;j++){
           if(A[j]<A[k])
              k=j;
       }
       temp = A[k];
       A[k] = A[i];
       A[i] = temp;
    }
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
}
