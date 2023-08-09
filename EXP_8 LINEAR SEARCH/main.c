#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,size,key,find=0;
    printf("enter the size");
    scanf("%d",&size);
    printf("enter the value of arrray");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
       printf("enter the key value");
       scanf("%d",&key);
    for(i=0;i<5;i++)
    {

        if(a[i]==key)
            find=1;
    }
   if (find==1)
    printf("key value found");
    else
        printf("key value not found");
}

