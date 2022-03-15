#include<stdio.h>
#include<stdlib.h>
int partition(int[],int,int);
void quicksort( int a[], int left,int right){
  int loc;
  if(left<right){
    loc=partition(a,left,right);
    quicksort(a,left,loc-1);
    quicksort(a,loc+1,right);
  }
}
int partition(int a[],int left,int right){
  int loc,temp;
  loc =left;
  while(left<right){
    while ((a[loc]<=a[right])&&(loc<right))
    right = right-1;
    if(a[loc]>a[right]){
      temp = a[loc];
      a[loc] = a[right];
      a[right] = temp;
      loc = right;
      left = left+1;
    }
    while ((a[loc]>=a[left])&&(loc>left))
      left = left+1;
      if (a[loc]<a[left]){
        temp = a[loc];
        a[loc] = a[left];
        a[left] = temp;
        loc = left;
        right = right-1;
      }
    }
    return (loc);
  }

void main(){
    int left=0,right,loc,low,high,A[10],i,n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    low = 0; high = n-1;
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
     scanf("%d",&A[i]);
    quicksort(A,low,high);
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
}
