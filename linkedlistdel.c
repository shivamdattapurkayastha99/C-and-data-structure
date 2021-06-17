#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void insert(struct node **head,int newdata)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=(*head);
    (*head)=newnode;

}
void deletenode(struct node **head,int pos)
{
    if(*head==NULL)
    return;
    struct node *temp=*head;
    if(pos==0)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp!=NULL&&i<pos-1;i++)
    temp=temp->next;
    if(temp==NULL||temp->next==NULL)
    return;
    struct node *next=temp->next->next;
    free(temp->next);
    temp->next=next;

}
void printlist(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
}
int main(int argc, char const *argv[])
{
   struct node *head=NULL;
   int ch,data,pos;
   printf("Enter 1 for insertion\n");
   printf("Enter 2 for deletion\n");
   printf("Enter 3 for display\n");
   printf("Enter 4 for exit\n");
   while(1)
   {
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
       case 1:
       printf("Enter the data to be inserted\n");
       scanf("%d",&data);
       insert(&head,data);
       break;
       case 2:
       printf("Enter the position of the  data to be deleted\n");
       scanf("%d",&pos);
       deletenode(&head,pos);
       break;
       case 3:
       printf("Linked list after deletion\n");
       printlist(head);

       break;
       case 4:
       exit(0);
       break;

       }

   }

    return 0;
}
