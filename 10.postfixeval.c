#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int stack[15],tos=-1,del;

void push(int x)
{

      tos=tos+1;
      stack[tos]=x;

}

int pop()
{

    if(tos==-1)
        printf("\nStack underflow ");
    else
    {
        del=stack[tos];
        tos=tos-1;
        return(del);
    }
}
void main()
{
    char s[15];
    int i=0,y1,y2,z,n,result;
    printf("Enter Postfix Expression: ");
    scanf("%s",s);
    while(s[i]!='\0')
    {
        if(isdigit(s[i]))
        {
          n=s[i]-48;
          push(n);
        }

            else
            {
            y1=pop();
            y2=pop();
              switch(s[i])
              {

                case '+':
                z=y2+y1;
                break;

                case '-':
                z=y2-y1;
                break;


                case '*':
                z=y2*y1;
                break;

                case '/':
                z=y2/y1;
                break;

              }
            push(z);
           }
           i++;

       }
    result=stack[tos];
    printf("Result is : %d",result);
}
