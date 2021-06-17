#include<stdlib.h>
#include<stdio.h>
#define bool int
struct node
{
    char data;//the data in the node
    struct node *next;//pointer to the next node
};
void push(struct node **topref,int newdata);
int pop(struct node **topref);
bool ismatchingpair(char character1,char character2)
{
    if(character1=='('&&character2==')')
    return 1;
    else if(character1=='['&&character2==']')
    return 1;
    else if(character1=='{'&&character2=='}')
    return 1;
    else
    return 0;
    
}
bool isbalanced(char exp[])
{
    int i=0;
    struct node *stack=NULL;
    while(exp[i])
    {
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
        push(&stack,exp[i]);
        if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
        {
            if(stack==NULL)
            return 0;
            else if(!ismatchingpair(pop(&stack),exp[i]))
            return 0;
        }
        i++;

    }
    if(stack==NULL)
    return 1;
    else
    {
        return 0;
    }
  
}
void push(struct node **topref,int newdata)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("stack overflow\n");
        getchar();
        exit(0);
    }
    newnode->data=newdata;
    newnode->next=(*topref);
    (*topref)=newnode;

}
int pop(struct node **topref)
{
    char res;
    struct node *top;
    if(*topref==NULL)
    {
        printf("Stack overflow\n");
        getchar();
        exit(0);

    }
    else
    {
        top=*topref;
        res=top->data;
        *topref=top->next;
        free(top);
        return res;

    }
    
}
int main(int argc, char const *argv[])
{
    printf("Enter the expression\n");
    char exp[100];
    scanf("%s",exp);
    if(isbalanced(exp))
    printf("balanced\n");
    else
    printf("not balanced\n");
    
    return 0;
}
