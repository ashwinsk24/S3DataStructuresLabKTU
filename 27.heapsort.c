#include<stdio.h>
#include<stdlib.h>
void mheaping(int[],int,int);
void heapsort(int A[],int n){
 int i,temp;
 for (i = n/2; i >=1; i--)
    mheaping(A,n,i);
 for (i = n;i >= 1; i--) {
   temp = A[1];
   A[1] = A[i];
   A[i] = temp;
   mheaping(A,i-1,1);
 }
}
void mheaping(int A[],int n,int i){
  int temp;
  int largest = i;
  int l =(2*i);
  int r = (2*i)+1;
  if (l<=n && A[l]>A[largest])
    largest = l;
  if (r<=n && A[r]>A[largest])
    largest = r;
  if (largest != i){
    temp = A[largest];
    A[largest] = A[i];
    A[i] = temp;
    mheaping(A,n,largest);
   }
  }

void main(){
    int i,n,A[20];
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
    heapsort(A,n);
    printf("\nSorted Array: ");
    for(i=1;i<=n;i++)
        printf(" %d",A[i]);
}
