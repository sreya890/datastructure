#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[100],i,j,n,temp;
   printf("enter the value of n");
   scanf("%d",&n);
   printf("enter the array value");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
       for(j=j+1;j<n;j++)
       {
           if(a[i]>a[j])
           {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
           }
       }
   }

   printf("the sorted array is:");
   for (i=0;i<n;i++)
   {
       printf("%d\n",a[i]);
   }



}
