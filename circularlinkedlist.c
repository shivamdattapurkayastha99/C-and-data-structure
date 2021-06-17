// Circular Linked List Deletion

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *addToEmpty(struct Node *last,int data)
{
    if(last!=NULL)
    return last;
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    last=temp;
    last->next=last;
    return last;
}
struct Node *addToBegin(struct Node *last,int data)
{
    if(last==NULL)
    return addToEmpty(last,data);
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    return last;
}
struct Node *addEnd(struct Node *last,int data)
{
    if(last==NULL)
    return addToEmpty(last,data);
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    last=temp;

    return last;
}
struct Node *addAfter(struct Node *last,int data,int item)
{
    if(last==NULL)
    return NULL;
    struct Node *temp,*p;
    p=last->next;
    do
    {
      if(p->data==item)
      {
          temp=(struct Node *)malloc(sizeof(struct Node));
          temp->data=data;
          temp->next=p->next;
          p->next=temp;
          if(p==last)
          last=temp;
          return last;

      }
      p=p->next;

    } while (p!=last->next);
    printf("%d not present in the list\n",item);
    return last;
}
void traverse(struct Node *last)
{
    struct Node *p;
    if(last==NULL)
    {
        printf("the list is empty\n");
        return;
    }
    p=last->next;
    do
    {
      printf("%d\n",p->data);
      p=p->next;


    } while (p!=last->next);
    
}
void deletenode(struct Node *head,int key)
{
    if(head==NULL)
    return;
    struct Node *curr=head,*prev;
    while(curr->data!=key)
    {
        if(curr->next==head)
        {
            printf("\nThe given node is not found in the list\n");
            break;
        }
        prev=curr;
        curr=curr->next;
     
    }
    if(curr->next==head)
    {
        head=NULL;
        free(curr);
        return;
    }
    if(curr==head)
    {
        prev=head;
        while(prev->next!=head)
        prev=prev->next;
        head=curr->next;
        prev->next=head;
        free(curr);

    }
    else if(curr->next==head)
    {
        prev->next=head;
        free(curr);

    }
    else
    {
        prev->next=curr->next;
        free(curr);

    }
}
int main(int argc, char const *argv[])
{
   struct Node *last=NULL;
   last=addToEmpty(last,6);
   last=addToBegin(last,4);
   last=addToBegin(last,2);
   last=addEnd(last,8);
   last=addEnd(last,12);
   last=addAfter(last,10,8);
   traverse(last);
   deletenode(last,4);
   printf("\nLinked list after deletion\n");
   traverse(last);

    return 0;
}
