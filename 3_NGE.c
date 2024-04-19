#include<stdio.h>
void printNGE(int arr[], int n)
{
    int next,i,j;
    for(i=0;i<n;i++)    
    {
        next = -1;
        for(j= i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                next = arr[j];
                break;
            }
        }
        printf("\n%d-->%d",arr[i], next);

    }
}
void main()
{
    int arr[] = {4,5,2,25,7,6,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
}