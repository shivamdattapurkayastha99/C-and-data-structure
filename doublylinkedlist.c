#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
void push(struct Node **head,int newdata)
{
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
    (*head)->prev=newnode;
    (*head)=newnode;
    


}
void insertBefore(struct Node **head,struct Node *nextnode,int newdata)
{
    if(nextnode==NULL)
    {
        printf("The given next node cannot be NULL");
        return;
    }
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->prev=nextnode->prev;
    nextnode->prev=newnode;
    newnode->next=nextnode;
    if(newnode->prev!=NULL)
    newnode->prev->next=newnode;
    else
    (*head)=newnode;
    
}
void printlist(struct Node *node)
{
    struct Node *last;
    printf("\nTraversal in forward direction\n");
    while(node!=NULL)
    {
        printf("%d ",node->data);
        last=node;
        node=node->next;

    }
    printf("\nTraversal in reversed direction\n");
    while(last!=NULL)
    {
        printf("%d ",last->data);
        
        last=last->prev;
        
    }
}
int main(int argc, char const *argv[])
{
  struct Node *head=NULL;
  push(&head,7);
  push(&head,1);
  push(&head,4);
  
  insertBefore(&head,head->next,8);
  printf("Created DLL is\n");
  printlist(head);
    

    return 0;
}
