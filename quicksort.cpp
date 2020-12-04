#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int arr[], int left, int right, int pivot)
{
    while(left <= right)
    {
        while(arr[left]< pivot)
            left ++;
        while(arr[right] > pivot)
            right --;

        if(left<=right)
        {
            swap(&arr[left], &arr[right]);
            left ++;
            right --;
        }
        
    }
    return left;
}
void quick_sort (int arr[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[(left + right)/2];
    int idx = partition(arr, left, right, pivot);
    quick_sort(arr, left, idx-1);
    quick_sort(arr, idx, right);
}

void mergeUtil(int arr[], int l, int m, int r)
{
    int n1 = m-l+1; 
    int n2 = r-m; 
    int L[n1];
    int R[n2];
    for (int i = 0; i<n1; i++)
    {
        L[i] = arr[l+i];
    }
    for (int j = 0; j<n2; j++)
    {
        R[j] = arr[j+m+1];
    }  

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++] = L[i++];
        else
        {
            arr[k++] = R[j++];
        }
        
    }
    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
    {
        arr[k++] = R[j++];
    }    
}
void mergeSort(int arr[], int l, int r)
{
    if(l>=r)
        return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    mergeUtil(arr, l, m, r);
}

int main()
{
    int arr[] = {5, 9, 1, 8, 20, 2, 3, 29};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for(int i = 0; i<n; i++)
    {
        cout<<"quick sorted "<<arr[i]<<endl;
    }

    int arr2[] = {9, 4, 8, 1, 20, 2, 3, 29, 6};
    n = sizeof(arr2)/sizeof(arr2[0]);
    mergeSort(arr2, 0, n-1);
    for(int i = 0; i<n; i++)
    {
        cout<<"merge sorted "<<arr2[i]<<endl;
    }
    return 0;
}