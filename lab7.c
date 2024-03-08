#include <stdio.h>
#include <math.h>

void swap(int *xp, int*yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// Bubble for order
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i=0; i < n - 1; i++)
    for(j = 0; j < n - i - 1;j++) 
    if (arr[j] > arr[j+1])
    swap(&arr[j], &arr[j+1]); 
}

void insertionSort(int arr[], int n)
{
int i, item, j;
for (i = 1; i < n; i++)
{
item = arr[i];
for(j=i-1; j>=0; j--)
{
if(arr[j]>item)
arr[j+1] = arr[j];
else
break;
}
arr[j+1] = item;
}
}

void selectionSort(int arr[], int n)
{
int i, j, min_idx, temp;
for (i = 0; i < n-1; i++) {
printf("\nIteration# %d\n",i+1);
min_idx = i;
for (j = i+1; j < n; j++)
if (arr[j] < arr[min_idx])
min_idx = j;
temp = arr[i];
arr[i] = arr[min_idx];
arr[min_idx] = temp;
}
}


void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}


int main ()
{
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = 9;
    printf("\nSorted Array 1: \n");
    bubbleSort(arr, n);
    printArray(arr, n);
    selectionSort(arr, n);
     


    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int p = 9;
     printf("\nSorted Array 2: \n");
    bubbleSort(arr2, n);
    printArray(arr2, p);
    selectionSort(arr2, n); 
    

    
    return 0;
}