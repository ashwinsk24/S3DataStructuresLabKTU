#include<stdio.h>

struct term
{
    int coef;
    int expo;

}p[10],q[10],s[10];

void main()
{
    int m,n,i,j,k=0,t;
    printf("Enter the size of the 1st polynomial: ");
    scanf("%d",&m);
    printf("Enter the '%d' coefficients and '%d' exponents of 1st polynomial: ",m,m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&p[i].coef);
        scanf("%d",&p[i].expo);
    }
    i=0;
    printf("Enter the size of the 2nd polynomial: ");
    scanf("%d",&n);
    printf("Enter the '%d' coefficients and '%d' exponents of 2nd polynomial: ",n,n);

    for(j=0;j<n;j++)
    {
        scanf("%d",&q[j].coef);
        scanf("%d",&q[j].expo);
    }
    j=0;
    if(m>n)
        t=m;
        else t=n;


    while(i<=m && j<=n)
    {
      if(p[i].expo == q[j].expo)
      {
          s[k].coef = p[i].coef + q[j].coef;
          s[k].expo = p[i].expo;
          i++;
          j++;
          k++;
      }
      else
        if(p[i].expo > q[j].expo)
      {
          s[k].coef = p[i].coef;
          s[k].expo = p[i].expo;
          i++;
          k++;
      }

       else
        if(q[j].expo > p[i].expo)
      {
          s[k].coef = q[j].coef;
          s[k].expo = q[j].expo;
          j++;
          k++;
      }
    }

    while(i<=m)
    {
          s[k].coef = p[i].coef;
          s[k].expo = p[i].expo;
          i++;
          k++;

    }

    while(j<=n)
    {
          s[k].coef = q[j].coef;
          s[k].expo = q[j].expo;
          j++;
          k++;
    }
    printf("\n p:");
    for(i=0;i<m;i++)
    {
        printf(" %d x^",p[i].coef);
        printf("%d +",p[i].expo);
    }
    printf("\n q:");
    for(j=0;j<n;j++)
    {
        printf(" %d x^",q[j].coef);
        printf("%d +",q[j].expo);
    }

    printf("\n Sum of polynomials: ");
    for(i=0;i<t;i++)
    {
        printf(" %d x^",s[i].coef);
        printf("%d +",s[i].expo);
    }



}
