/*
swap adjacent elements
if a[i] > a[i+1] swap, otherwise iterate forward
dry run:

1st pass
2 10 8 7
2 10 8 7
2 8 10 7
2 8 7 10

2nd pass
2 9 7 10
2 8 7 10
2 7 8 10

3rd pass
2 7 8 10
2 7 8 10

number of passes = n - 1

void bubble_sort(arr, n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[i])
                swap(arr[j], arr[j + 1]);
        }
    }
}

optimized:
we don't need to check the last elements again and again, we only need to check till (n - i - 1), so that is changed in second loop
e.g //add example here

void bubble_sort(arr, n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[i])
                swap(arr[j], arr[j + 1]);
        }
    }
}

complexity:
swaps = n-1 + n-2 .... 2 + 1
      = n(n-1)/2
      = O(n^2)

optimizing for sorted array:
we check if any swapping happened, if no: swapped flag is set to false and we can stop here

stable: yes

add implementations below...
*/