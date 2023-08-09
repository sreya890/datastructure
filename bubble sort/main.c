#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[100],n,i,j,temp;
   printf("enter the value of 'n':");
   scanf("%d",&n);
   printf("enter the array values");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
    for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
      }
    }
    for(i=0;i<n;i++)
    {
     printf("%d\n",a[i]);
    }
}
