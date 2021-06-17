// C program to make an  array from structure
// ADT 
# include<stdio.h>
#include<stdlib.h>
struct myarray
{
  int total_size;
  int used_size;
  int *ptr;

};
void createarray(struct myarray *a,int tSize,int uSize)
{
    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr=(int *)malloc(tSize*sizeof(int));

}
void show(struct myarray *a)
{
    for(int i=0;i<a->used_size;i++)
    printf("%d\n",a->ptr[i]);

}
void setVal(struct myarray *a)
{
    int n;
   for(int i=0;i<a->used_size;i++){
       printf("Enter element %d",i);
    scanf("%d",&n);
    a->ptr[i]=n;

   }
     
}
int main(int argc, char const *argv[])
{
   struct myarray marks;
   createarray(&marks,10,2);
   printf("We are running setval now\n");
   setVal(&marks);
    printf("We are running showval now\n");
   show(&marks);
    return 0;
}
