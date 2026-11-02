#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int arr[], int n)
{
    int i,j,temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[100];
    int n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d integers:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    printf("Sorted array:");
    printArr(arr,n);

    system("pause");
    return 0;
}