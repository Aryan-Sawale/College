#include <iostream>

using namespace std;

struct Maxheap
{
	int *arr;
	int size, capacity;

	Maxheap(int capacity)
	{
		this->capacity = capacity;
		size = 0;
		arr = new int(capacity);
	}

	int parent(int i)
	{
		return ((i - 1) / 2);
	}

	void insert(int marks)
	{
		if (size == capacity)
		{
			cout << "overflow";
			return;
		}

		size++;
		arr[size - 1] = marks;

		int i = size - 1;
		while (i != 0 and (arr[parent(i)] < arr[i]))
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
};

int main()
{
	int n;
	cout << "Enter number of students: ";
	cin >> n;

	Maxheap heap(n);

	for (int i = 0; i < n; i++)
	{
		int marks;
		cout << "Enter marks: ";
		cin >> marks;
		heap.insert(marks);
	}

	cout << "\nMaxheap: ";
	for (int i = 0; i < n; i++)
	{
		cout << heap.arr[i] << " ";
	}

	cout << "\nHighest marks: " << heap.arr[0];
}