#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node*link;
} *start;
main()
{
 int choice,n,m,position,i;
 start=NULL;


 while(1)
 {
 printf("\n 1. Create List");
 printf("\n 2. Add at beginning");
 printf("\n 3. Add after");
 printf("\n 4. Delete");
 printf("\n 5. Display");
 printf("\n 6. Count");
 printf("\n 7. Reverse");
 printf("\n 8. Search");
 printf("\n 9. Quit");
 printf("\n Enter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf(" How many nodes you want: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf(" Enter the element: ");
 scanf("%d",&m);
 create_list(m);
 }
 break;
 case 2:
 printf("\n Enter the element: ");
 scanf("%d",&m);
 addatbeg(m);
 break;
 case 3:
 printf("\n Enter the element: ");
 scanf("%d",&m);
 printf("\n Enter the position after which this element is inserted: ");
 scanf("%d",&position);
 addafter(m,position);
 break;
 case 4:
 if(start==NULL)
 {
 printf("\n List is empty.");
 continue;
 }
 printf("\n Enter the element for deletion: ");
 scanf("%d",&m);
 del(m);
 break;
 case 5:
 display();
 break;

 case 6:
 count();
 break;
 case 7:

 break;
 case 8:
 printf("\n Enter the element to be searched : ");
 scanf("%d",&m);
 search(m);
 break;
 case 9:

 default:
 printf("\n Wrong Choice.");
 } // End of Switch
 } // End of while
} // End of main
create_list(int data)
{
 struct node *q,*tmp;
 tmp=malloc(sizeof(struct node));
 tmp->info=data;
 tmp->link=NULL;
 if(start==NULL) // If the List is empty
 start=tmp;
 else
 { // Elements inserted at end
 q=start;

 while(q->link!=NULL)
 q=q->link;
 q->link=tmp;
 }
} // End of create list
addatbeg(int data)
{
 struct node *tmp;
 tmp=malloc(sizeof(struct node));
 tmp->info=data;
 tmp->link=start;
 start=tmp;
} // End of addatbeg()
addafter(int data,int pos)
{
 struct node *tmp, *q;
 int i;
 q=start;
 for(i=0;i<(pos-1);i++)
 {
 q=q->link;
 if(q==NULL)
 {
 printf("\n There are less than %d elements.",pos);
 return;
 }
 } // End of for
 tmp=malloc(sizeof(struct node));

 tmp->link=q->link;
 tmp->info=data;
 q->link=tmp;
} // End of addafter()
del(int data)
{
 struct node *tmp,*q;
 if(start->info==data)
 {
 tmp=start;
 start=start->link; // first element deleted
 free(tmp);
 return;
 }
 q=start;
 while(q->link->link!=NULL)
 {
 if(q->link->info==data) // Element deleted in between
 {
 tmp=q->link;
 q->link=tmp->link;
 free(tmp);
 return;
 }
 q=q->link;
 } // end of while
 if(q->link->info==data) // Last element deleted
 {
 tmp=q->link;
 free(tmp);

 q->link=NULL;
 return;
 }
 printf("\n Element %d not found.",data);
} // end of del()
display()
{
 struct node *q;
 if(start==NULL)
 {
 printf("\n List is empty.");
 return;
 }
 q=start;
 printf("\n List is: ");
 while(q!=NULL)
{
 printf(" %d ",q->info);
 q=q->link;
 }
 printf("\n");
} // End of display
count()
{
 struct node *q=start;
 int cnt=0;
 while(q!=NULL)
 {
 q=q->link;

 cnt++;
 }
 printf("\n Number of elements are %d.",cnt);
} // End of count
\
search(int data)
{
 struct node *ptr=start;
 int pos=1;
 while(ptr!=NULL)
 {
 if(ptr->info==data)
 {
 printf("\n item %d found at position %d.\n",data,pos);
 return;
 }
 ptr=ptr->link;
 pos++;
 }
 if(ptr==NULL)
 printf("\n Item %d not found in list.",data);
} // End of search
