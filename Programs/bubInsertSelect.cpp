#include <assert.h>
#include <iostream>
#include <math.h> 
#include <stdio.h> 
#include <string.h>

using namespace std;
 

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
       
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}   

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 5, 1, 4, 2, 8};
    int arr2[] = { 1, 2, 8, 0, 5};
    int arr3[] = { 2, 4, 42, 25, 87};
    int N = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, N);
    insertionSort(arr2, N);
    selectionSort(arr3, N);


    cout << "Sorted array: \n";
    printArray(arr, N);
    printArray(arr2, N);
    printArray(arr3, N);

    return 0;
}