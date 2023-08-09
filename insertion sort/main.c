#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[100],n,i,j,temp;
   printf("enter the value of n: ");
   scanf("%d",&n);
   printf("enter the array value: ");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
        j=i-1;
        temp=a[i];
         while(j>=0 && a[j]>temp)
        {
          a[j+1]=a[j];
          j--;
          a[j+1]=temp;

        }

      }
      printf("the sorted array is:\n ");
       for(i=0;i<n;i++)
       {
           printf("%d\n",a[i]);
       }
}
