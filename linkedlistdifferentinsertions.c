#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *insertatFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;


}
struct Node *insertatIndex(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;


}
struct Node *insertatEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;


}
struct Node *insertAfterNode(struct Node *prevnode,struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;

    
    return head;


}
int main(int argc, char const *argv[])
{
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *second=(struct Node *)malloc(sizeof(struct Node));
    struct Node *third=(struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=41;
    third->next=fourth;

    fourth->data=66;
    fourth->next=NULL;
    printf("Linked List before insertion\n");

    linkedlisttraversal(head);
    // head=insertatFirst(head,56);
    // head=insertatIndex(head,56,1);
    printf("Linked List after insertion\n");
    // head=insertatEnd(head,56);
    head=insertAfterNode(second,head,45);
    linkedlisttraversal(head);
    return 0;
}
