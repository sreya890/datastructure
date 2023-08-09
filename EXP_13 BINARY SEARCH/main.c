#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[]={2,3,4,10,90,25,40};
  int n=5;
  int l=0;
  int r=n-1;
  int x=10;
  while(l<=r)
  {
      int n=l+(r-1)/2;
      if(arr[n]==x)
      {
          printf("element is present at index %d",n);
          exit(0);
      }
      if (arr[n]<x)
        l=n+1;
      else
        r=n-1;
  }
  printf("element is not present");
}
