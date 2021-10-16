// reverse an array 
#include<iostream>
using namespace std;
void reverseArray(int arr[],int start,int end)
{
    int temp;
    while (start<=end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;

    }
    
}
void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ",arr[i]);

    }
    printf("\n");

}
int main(){
    int arr[]={1,2,3,4};
    int n=4;
    printArray(arr,n);
    reverseArray(arr,0,n-1);
    printArray(arr,n);
    return 0;
}