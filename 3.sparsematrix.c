#include<stdio.h>

void main()
{
    int i,j,m,n,x,A[10][10];
    printf(" Enter the no. of rows ");
    scanf("%d",&m);
    printf(" Enter the no. of columns ");
    scanf("%d",&n);
    printf(" Enter the elements \n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    int k=0,sp_mat[10][3];
    sp_mat[0][0]=m;
    sp_mat[0][1]=n;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                k++;
                sp_mat[k][0]=i;
                sp_mat[k][1]=j;
                sp_mat[k][2]=A[i][j];
            }
        }
    }

    sp_mat[0][2]=k;
    printf("Sparse Matrix \n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf(" %d",sp_mat[i][j]);

        }
        printf(" \n");
    }

}


