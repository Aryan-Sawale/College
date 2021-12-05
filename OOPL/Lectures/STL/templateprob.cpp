/*
create a function template for finding max value contained in the array by using linear search
*/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T max_val(vector<T> &arr)
{
    T max_ele;
    int i, j;
    T size_arr = arr.size();
    max_ele = arr[0];
    for (i = 1; i < size_arr; i++)
    {
        if (arr[i] > max_ele)
        {
            max_ele = arr[i];
        }
    }

    return max_ele;
}

// template <typename T>
// T max_val(T *arr)
// {
//     T max_ele;
//     int i, j;
//     auto size_arr = sizeof(arr);
//     cout << "size: " << size_arr << "\n";
//     max_ele = arr[0];
//     for (i = 1; i < size_arr; i++)
//     {
//         if (arr[i] > max_ele)
//         {
//             max_ele = arr[i];
//         }
//     }

//     return max_ele;
// }

int main()
{
    vector<float> array = {22.5, 65.87, 33.89, 77.2, 8};
    // float array[] = {22.5, 65.87, 33.89, 77.2, 8};
    cout << "Max: " << max_val(array);
}