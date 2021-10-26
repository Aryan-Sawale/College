#include <iostream>
using namespace std;

class publication
{
    public:
    string title;
    float price;
    publication(string T, float P)
    {
        title = T;
        price = P;
    }
};

class book: public publication
{
    public:
    int page_count;
    book(string T, float P, int C): publication(T, P) //passing values to base constructor
    {
        page_count = C;
    }
    void display()
    {
        cout<<"Title of the book is: "<<title<<endl;
        cout<<"Price of the book is: "<<price<<endl;
        cout<<"No. of Pages of the book are: "<<page_count<<endl;
    }
    
};

class tape: public publication
{
    public:
    float time_min;
    tape(string T, float P, float tt): publication(T, P) //passing values to base constructor
    {
        time_min = tt;
    }
    void display()
    {
        cout<<"Title of the tape is: "<<title<<endl;
        cout<<"Price of the tape is: "<<price<<endl;
        cout<<"Time of the tape are: "<<time_min<<endl;
    }
};

int main()
{
    string t;
    float p;
    float tt;
    int c;
    char choice;
    char option;
    do
    {
        cout<<"Welcome to Publication company \nPress B for Book \npress T for Tape"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 'B':
            {                                                      //curly braces are put to avoid the error "Transfer of control
                cout<<"Enter title of Book: "<<endl;               //bypasses variable initialization" 
                cin>>t;
                cout<<"Enter Price of Book: "<<endl;
                cin>>p;
                cout<<"Enter the no. of pages of Book: "<<endl;
                cin>>c;
                book b(t, p, c);
                b.display();
                break;
            }
            
            case 'T':
            {
                cout<<"Enter title of Tape: "<<endl;
                cin>>t;
                cout<<"Enter Price of Tape: "<<endl;
                cin>>p;
                cout<<"Enter time of Tape: "<<endl;
                cin>>tt;
                tape tp(t, p, tt);
                tp.display();
                break;
            }
            
            default:
            {
                cout<<"Incorrect input"<<endl;
                break;
            }
        }
        cout<<"Press Y to continue: ";
        cin>>option;
    }
    while (option == 'y' || option == 'Y');

return 0;
}