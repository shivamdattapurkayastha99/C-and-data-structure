#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left,*right;
};
struct node *newnode(int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->key);
        inorder(root->right);
    }
}
struct node *insert(struct node *root,int key)
{
    if(root==NULL)
    return newnode(key);
    if(key<root->key)
    root->left=insert(root->left,key);
    else
    root->right=insert(root->right,key);
    return root;
}
struct node *min(struct node *root)
{
    struct node *current=root;
    while(current&&current->left!=NULL)
    current=current->left;
    return current;
}
struct node *deletenode(struct node *root,int key)
{
    if(root==NULL)
    return root;
    if(key<root->key)
    root->left=deletenode(root->left,key);
    else if(key>root->key)
    root->right=deletenode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=min(root->right);
        root->key=temp->key;
        root->right=deletenode(root->right,temp->key);

    }
    return root;

}
int main(int argc, char const *argv[])
{
   int data,ch;
   struct node *root=NULL;
   
   while(1)
   {
       printf("Enter the choice 1 for insertion 2 for deletion 3 for inorder display 4 to exit\n");
        scanf("%d",&ch);
       switch(ch)
       {
           case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            case 2:
            printf("Enter the data to be deleted\n");
            scanf("%d",&data);
            root=deletenode(root,data);
            break;
            case 3:
            printf("Inorder traversal of bst is\n");
            inorder(root);
            break;
            case 4:
            exit(0);
            break;
       }
   }
    return 0;
}
