#include <iostream>
#include <vector>
#include <omp.h>
#include <ctime>

using namespace std;

void bubbleSort(vector<int> &arr)
{
  int n = arr.size();
  bool swapped = true;

  while (swapped)
  {
    swapped = false;
#pragma omp parallel for
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
  }
}

void bubbleSortSequential(vector<int> &arr)
{
  int n = arr.size();
  bool swapped = true;

  while (swapped)
  {
    swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
  }
}

void merge(vector<int> &arr, int l, int m, int r)
{
  vector<int> temp;
  int left = l;
  int right = m + 1;

  while (left <= m && right <= r)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= m)
  {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= r)
  {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = l; i <= r; i++)
  {
    arr[i] = temp[i - l];
  }
}

void mergeSort(vector<int> &arr, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      mergeSort(arr, l, m);
#pragma omp section
      mergeSort(arr, m + 1, r);
    }
    merge(arr, l, m, r);
  }
}

void mergeSortSequential(vector<int> &arr, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSortSequential(arr, l, m);
    mergeSortSequential(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()
{
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr1 = arr;
  clock_t bubbleStart = clock();
  bubbleSort(arr1);
  clock_t bubbleEnd = clock();
  cout << "Sorted array using Bubble Sort: ";
  for (int num : arr1)
    cout << num << " ";
  cout << endl;

  vector<int> arr2 = arr;
  clock_t bubbleSeqStart = clock();
  bubbleSort(arr2);
  clock_t bubbleSeqEnd = clock();
  cout << "Sorted array using Bubble Sort Sequential: ";
  for (int num : arr2)
    cout << num << " ";
  cout << endl;

  vector<int> arr3 = arr;
  clock_t mergeStart = clock();
  mergeSort(arr3, 0, n - 1);
  clock_t mergeEnd = clock();
  cout << "Sorted array using Merge Sort: ";
  for (int num : arr3)
    cout << num << " ";
  cout << endl;

  vector<int> arr4 = arr;
  clock_t mergeSeqStart = clock();
  mergeSort(arr4, 0, n - 1);
  clock_t mergeSeqEnd = clock();
  cout << "Sorted array using Merge Sort Squential: ";
  for (int num : arr4)
    cout << num << " ";
  cout << endl;

  double bubbleDuration = double(bubbleEnd - bubbleStart) / CLOCKS_PER_SEC;
  double bubbleSeqDuration = double(bubbleSeqEnd - bubbleSeqStart) / CLOCKS_PER_SEC;
  double mergeDuration = double(mergeEnd - mergeStart) / CLOCKS_PER_SEC;
  double mergeSeqDuration = double(mergeSeqEnd - mergeSeqStart) / CLOCKS_PER_SEC;

  cout << endl;

  cout << "Bubble sort parallel time in seconds: " << bubbleDuration << endl;
  cout << "Bubble sort sequential time in seconds: " << bubbleSeqDuration << endl;
  cout << "Merge sort parallel time in seconds: " << mergeDuration << endl;
  cout << "Merge sort sequential time in seconds: " << mergeSeqDuration << endl;

  return 0;
}
