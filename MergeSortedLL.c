//Programme to do the merging of two sorted linked list
#include<stdio.h>
#include<stdlib.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
//create function to create the linked list
void create(struct node **start1,int num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if((*start1)==NULL)
    {
        (*start1)=temp;
    }
    else
    {
        curr=(*start1);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
//merging function to merge the lists
/*struct node *merge(struct node *start1,struct node *start2,struct node *curr)
{
    struct node *newhead=NULL;

    if(start1==NULL)  return start2;
    if(start2==NULL)  return start1;

    if(start1&&start2)
    {
        if(start1->data<=start2->data)
        {
            curr=start1;
            start1=curr->next;
        }
        else
        {
            curr=start2;
            start2=curr->next;
        }
    }
    newhead=curr;

    while(start1&&start2)
    {
        if(start1->data<=start2->data)
        {
            curr->next=start1;
            curr=start1;
            start1=curr->next;
        }
        else
        {
            curr->next=start2;
            curr=start2;
            start2=curr->next;
        }
    }
    if(start1==NULL) curr->next=start2;
    if(start2==NULL) curr->next=start1;

    return newhead;
}*/
struct node *merge(struct node *start1, struct node *start2)
{
   struct node *start3, *temp1, *temp2;
    start3=(struct node *)malloc(sizeof(struct node));

     while(start1&&start2)
     {
         if(start1->data<=start2->data)
         {
             start3->data=start1->data;
             start1=start1->next;
             temp1=(struct node *)malloc(sizeof(struct node));
             temp1->next=NULL;
             start3->next=temp1;
             start3=start3->next;
         }
         else
         {
             start3->data=start2->data;
             start2=start2->next;
             temp2=(struct node *)malloc(sizeof(struct node));
             temp2->next=NULL;
             start3->next=temp2;
             start3=start3->next;
         }
     }
     while(start1!=NULL)
     {
             start3->data=start1->data;
             start1=start1->next;
             temp1=(struct node *)malloc(sizeof(struct node));
             temp1->next=NULL;
             start3->next=temp1;
             start3=start3->next;
     }
     start3=(struct node *)malloc(sizeof(struct node));

     while(start2!=NULL)
     {
             start3->data=start2->data;
             start2=start2->next;
             temp2=(struct node *)malloc(sizeof(struct node));
             temp2->next=NULL;
             start3->next=temp2;
             start3=start3->next;
     }
     return start3;
}
//display function to print the list
void display(struct node *start1)
{

    struct node *curr=start1;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main()
{
    struct node *start1=NULL,*start2=NULL,*curr=NULL;
  //1st Link list:10->50->70->90->100
    create(&start1,10);
    create(&start1,50);
    create(&start1,70);
    create(&start1,90);
    create(&start1,100);
//2nd link list: 20->30->40->60->80->95
    create(&start2,20);
    create(&start2,30);
    create(&start2,40);
    create(&start2,60);
    create(&start2,80);
    create(&start2,95);

   printf("\nThe two lists are:-\n");
     display(start1);
     display(start2);

   struct node *newhead;
   newhead=merge(start1,start2);

   printf("\nThe merged list is:-");
   display(newhead);

}
