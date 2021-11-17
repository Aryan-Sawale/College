#include <iostream>
#define MAX 10
using namespace std;

class Dequeue
{  
    int data[MAX];
    int front, rear;
    public:
        Dequeue()
        {
            front = rear = -1;
        }
        int isempty();
        int isfull();
        void ins_front(int key);
        void ins_back(int key);
        void del_front();
        void del_back();
        void display();
};

int Dequeue::isempty()
{
	return (front == rear == -1) ? 1 : 0;
}

int Dequeue::isfull()
{   
    return (rear == MAX - 1) ? 1 : 0;
}

void Dequeue::ins_front(int key)
{
    if (isfull())
    {
        cout<<"\nError: overflow";
    }

    if (isempty())
    {
        rear = front = 0;
        data[front] = key;
    }

    front--;
    data[front] = key;
}

void Dequeue::ins_back(int key)
{
    if (isfull())
    {
        cout<<"\nError: overflow";
    }

    if (isempty())
    {
        rear = front = 0;
        data[rear] = key;
    }

    rear++;
    data[rear] = key;
}

void Dequeue::del_front()
{
    if (isempty())
    {
        cout<<"\nError: Underflow";
    }
    
    if (rear == front)
    {
        front = rear = 1;
    }

    front++;
}

void Dequeue::del_back()
{
    if (isempty())
    {
        cout<<"\nError: Underflow";
    }
    
    if (rear == front)
    {
        front = rear = 1;
    }

    rear--;
}

void Dequeue::display()
{
    cout<<"\n";
    if (isempty())
    {
        cout<<"Queue is empty";
    }
    
    for (int i = front; i <= rear; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<"\n";
}

int main()
{   
    Dequeue obj;
    int ch, ele;
    do
    {   
        cout<<"\n1.Insert at front\n2.Insert at end\n3.Delete from front\n4.Delete from end\n5.Display\n6.Exit\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {  
            case 1: 
                cout<<"\nEnter element: ";
                cin>>ele;
                obj.ins_front(ele);
                break;

            case 2: 
                cout<<"\nEnter element: ";
                cin>>ele;
                obj.ins_back(ele);
                break;

            case 3: 
                obj.del_front();
                break;

            case 4: 
                obj.del_back();
                break;

            case 5:
                obj.display();
                break;

            case 6:
                cout<<"\nExiting...";
                break;
            }
    }
    while (ch!=6);
    
    return 0;
}