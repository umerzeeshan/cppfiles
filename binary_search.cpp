#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int bin_search(int arr[], int l, int r, int num)
{
    if(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]== num)
            return mid;
        else if (num<arr[mid])
            return bin_search(arr, l, mid-1, num);
        else
            return bin_search(arr, mid+1, r, num);      
    }
    return -1;

}

int main()
{
    int array[] = {1, 5, 20, 33, 88, 100, 250, 400};
    int n = sizeof(array)/sizeof(array[0]);
    int num = 500;
    int idx = bin_search(array, 0, n-1, num);
    if(idx !=-1)
    cout<< num<< " exists at idx:"<<idx<<endl;
    else
    {
        cout<<num<<" doesn't exist in the array"<<endl;
    }
    return 0;

}