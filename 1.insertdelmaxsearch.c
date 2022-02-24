#include<stdio.h>
void main()
{
    int i,j,n,A[10],ch,x,p,max;
    char a;
    printf(" Enter the no. of elements: ");
    scanf(" %d", &n);
    printf(" Enter the elements: ");
    for (i = 0; i < n; i++)
    {
      scanf(" %d", &A[i]);
    }

    do
    {
    printf(" Enter your choice \n 1.Insert an element \n 2.Delete an element \n 3.Search an element\n");
    scanf(" %d",&ch);

    switch (ch)
    {
      case 1:
      printf(" Enter the element to be inserted: ");
      scanf(" %d",&x);
      printf(" Enter the position for insertion: ");
      scanf(" %d",&p);

      for (i = n; i >= p-1; i--)
      {
        A[i]=A[i-1];
      }
      A[p-1]=x;
      n=n+1;
      printf(" Array after insertion ");
      for (i = 0; i < n ; i++)
      {
        printf(" %d ",A[i]);
      }

      break;

      case 2:

      printf(" Enter the position for deletion: ");
      scanf(" %d",&p);
      for (i = p-1; i < n ; i++)
      {
        A[i]=A[i+1];
      }
      n=n-1;
      printf(" Array after deletion ");
      for (i = 0; i < n ; i++)
      {
        printf(" %d ",A[i]);
      }

      break;


      case 3:
      printf(" Enter the element to be searched: ");
      scanf(" %d",&x);
      int c=0;
      for (i = 0; i <= n ; i++)
      {
        if(A[i]==x)
        {
          printf(" element '%d' is found at position '%d' ", x, i+1);
          c++;

        }


      }

     if(c==0) printf(" element %d NOT found",x);

      break;
      default:printf("Invalid input '%d'.Try again", ch);
      }
    printf("\nDo you want to continue(Y-yes/N-no) \n");
    scanf(" %c",&a);
    }
    while(a =='Y' || a =='y');
  }
