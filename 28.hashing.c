#include<stdio.h>
#include<stdlib.h>
int n,i,ch,p,e,A[10];
void main(){
    printf(" Enter the size of the array ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        A[i] = -1;
    }
    do{
    printf(" \nEnter your choice: \n1.Insertion \n2.Deletion \n3.Display \n4.Search \n5.Exit \n: ");
    scanf(" %d",&ch);
    switch(ch){
    case 1:
        insert();
        break;
      case 2:
        delete();
        display();
        break;
      case 3:
        display();
        break;
    case 4:
        search();
        break;
    case 5:
        printf(" \nExited Successfully. ");
    exit(0);
    default: printf("\nInvalid choice. Try Again.");
    }
  }while(ch<6);
}
void insert(){
    int e;
    printf("\nEnter the element: ");
    scanf("%d",&e);
        p = e%n;
        if(A[p] == -1)
            A[p] = e;
        else
        printf(" Collision Occurs ");
}
void display(){
    printf("\nHash Table:");
    for(i=0;i<n;i++){
        printf(" %d",A[i]);
    }
}
void search(){
    int s;
    printf("\nEnter the element to be searched: ");
    scanf(" %d",&s);
        for(i=0;i<n;i++){
        if(A[i] == s)
        printf("\nElement '%d' found at '%d'.",s,i+1);
        }
}
void delete(){
    int d,f;
    printf("\nEnter the element to be deleted: ");
    scanf(" %d",&d);
        for(i=0;i<n;i++){
        if(A[i] == d){
           A[i] = -1; int f=1;
           break;
           }
        }
        if(f == 0) printf("\nElement '%d' NOT found.",d);
}
