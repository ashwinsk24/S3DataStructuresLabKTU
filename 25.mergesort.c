#include<stdio.h>
#include<stdlib.h>
int A[10],C[10];
void merge(int,int,int);
void mergesort(int l,int r){
  int mid;
  if(r<=l)
    return;
  else{
    mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
  }
}
void merge(int l,int mid,int r){
  int i,j,k,m;
  i=l; j=mid+1; k=0;
  while((i<=mid)&&(j<=r)){
    if(A[i] <= A[j]){
      C[k] = A[i];
      i++; k++;
    }
    else{
      C[k]=A[j];
      j++; k++;
    }
  }
  if ((i>mid)&&(j<=r)){
    for (m = j;m <= r; m++){
      C[k]=A[m];
      k++;
    }
  }
  else if ((i<=mid)&&(j>r)){
     for (m = i;m <= mid; m++){
      C[k]=A[m];
      k++;
    }
  }
for(i=i,j=0;i<=r;i++,j++)
   A[i]=C[j];
 }

void main(){
    int i,n,l=0,r;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    r = n-1;
    mergesort(l,r);
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
        printf(" %d",A[i]);
}
