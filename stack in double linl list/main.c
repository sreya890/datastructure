#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node*next;
struct node*prev;
} *start = NULL,
  *top = NULL;

int isEmpty()
{

    if (start == NULL)
        return 1;
    return 0;

}
void push(int val)
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    if(isEmpty())
    {
        temp->next=NULL;
        temp->prev=NULL;
        start=temp;
        top=temp;
    }
    else
    {
        top->next =temp;
        top->prev = NULL;
        temp->next=NULL;
        top=temp;
    }
}
void pop()
 {
     struct node*temp;
     temp=top;
     if(isEmpty())
     {
         printf("stack is empty");
     }
     else if(top==start)
     {
         top =NULL;
         start = NULL;
         free(temp);
     }
     else{
        top->prev=NULL;
        top->next=NULL;
        top=temp->prev;
        free(temp);
        }
     printf("Poped");
 }
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct node* ptr = top;
        printf("Stack: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


int main()
{
    int choice,value;

    while(choice!=4)
    {
        printf("\nmenu\n");
        printf("1)push\n2)pop\n3)display\n4)exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("enter your value:");
                scanf("%d",&value);
                push(value);
                break;
            }
        case 2:
            {
                pop();
                break;

            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                exit(0);
            }
        }
    }


}

