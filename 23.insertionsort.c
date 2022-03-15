#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i,j,k,temp,A[10];
    printf("Enter the no. of elements ");
    scanf("%d",&n);
    printf("\nEnter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("\nInserted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);

    for(i=1;i<n;i++){  //sort
       k = A[i];
       j = i-1;
       while((j>=0) && (A[j]>k)){
        A[j+1] = A[j];
        j--;
       }
       A[j+1]=k;
    }
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
}
