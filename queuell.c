#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *f=NULL;
struct Node *r=NULL;
void linkedlisttraversal(struct Node *ptr)
{
    printf("Linked list traversal is\n");
    while(ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int value)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("Queue is full\n");

    }
    else
    {
        n->data=value;
        n->next=NULL;
        if(f==NULL)
        f=r=n;
        else
        {
            r->next=n;
            r=n;

        }
        
    }
}
int dequeue()
{
    int val=-1;

    struct Node *ptr=f;
    if(f==NULL)
    {
        printf("Queue is Empty\n");

    }
    else
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
        
    }
    return val;
}
int main(int argc, char const *argv[])
{
    
    linkedlisttraversal(f);
    enqueue(34);
    enqueue(4);
    enqueue(7);
    linkedlisttraversal(f);
    printf("Dequeuing element %d",dequeue());
    linkedlisttraversal(f);


    return 0;
}
