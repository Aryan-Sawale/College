/*
Write a function template selection sort. Write a program that inputs, sorts, outputs an int array and float array
*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void selectionSort(T arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

template <typename T>
void printArray(T arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size_int, size_float;
    cout << "Enter size of integer array: ";
    cin >> size_int;
    int arr1[size_int];
    for (int i = 0; i < size_int; i++)
    {
        cout << "element: ";
        cin >> arr1[i];
    }
    selectionSort(arr1, size_int);
    cout << "Integer Sorted array: \n";
    printArray(arr1, size_int);

    cout << "Enter size of float array: ";
    cin >> size_float;
    float arr2[size_float];
    for (int i = 0; i < size_float; i++)
    {
        cout << "element: ";
        cin >> arr2[i];
    }
    selectionSort(arr2, size_float);
    cout << "Integer Sorted array: \n";
    printArray(arr2, size_float);
}