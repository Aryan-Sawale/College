#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file_out("test.txt");
    // ofstream file_out;           //alternate way
    // file_out.open("test.txt");
    file_out<<"Hello I am line 1\n";
    file_out<<"Hey there I am line 2\n";
    file_out<<"Sup I am line 3";
    file_out.close();

    ifstream file_in("test.txt");
    string s;
    int counter = 0;
    while (!file_in.eof())              //eof() returns 1 when eof is reached
    {
        getline(file_in, s);
        cout<<s<<"\n";
        counter++;
        cout<<"number of lines: "<<counter<<"\n";
    }
    file_in.close();
}

    /*
    3 ways to use getline
    getline( istream& is, string& str, char delim );  
    is: It is an object of the istream class that defines from where to read the input stream.
    str: It is a string object in which string is stored.
    delim: It is the delimiting character.
    e.g getline(file_in, str, '|') //will read till '|' character is reached

    getline( istream& is, string& str ); 
    here istream object can be cin, file_in etc. and string object is any string variable
    e.g getline(cin,name);

    istream& getline(char* , int size);
    char*: It is a character pointer that points to the array.
    Size: It acts as a delimiter that defines the size of the array means input cannot cross this size.
    e.g cin.getline(fruits, 50);
    */

/*
fstream opens with default (ios::out | ios::in)  //fstream doesn't create file if it doesn't exist unlike ofstream
ofstream opens with default (ios::out)
ifstream opens with default (ios::in)
*/


// int main( )   //program to display file contents
// { 
// 	ifstream fin; 
// 	fin.open("out.txt"); 
// 	char ch; 
// 	while(!fin.eof(  )) { 
// 		fin.get(ch); 
// 		cout << ch; 
// 	} fin.close( ); 
// 	return 0; 
// }


// int main( ) {    //count number of characters
// 	ifstream fin; 
// 	fin.open("out.txt"); 
// 	int count = 0; 
// 	char ch; 
// 	while(!fin.eof()) { 
// 		fin.get(ch); 
// 		count++; 
// 	} 
// 	cout << "Number of characters in file are " << count; 	fin.close( ); 
// 	return 0; 
// } 

// int main( )       //count number of words
// { 
// 	ifstream fin; 
// 	fin.open("out.txt"); 
// 	int count = 0; 
// 	char word[30]; 
// 	while(!fin.eof( )) {
// 	 fin >> word; 
// 	count++; 
// 	} 
// 	cout << "Number of words in file are " << count; 
// 	fin.close(); 
// 	return 0; 
// } 

// int main() {        //count number of lines 
// 	ifstream fin; 
// 	fin.open("out.txt"); 
// 	int count = 0; 
// 	char str[80]; 
// 	while(!fin.eof( )) { 
// 		fin.getline(str,80); 
// 		count++; 
// 	} 
// 	cout << "Number of lines in file are " << count; 
// 	fin.close( ); 
// 	return 0; 
// } 

// int main()       //copy file
// { 
// 	ifstream fin; 
// 	fin.open("out.txt"); 
// 	ofstream fout; 
// 	fout.open("sample.txt"); 
// 	char ch; 
// 	while(!fin.eof( )) { 
// 		fin.get(ch); 
// 		fout << ch; 
// 	} 
// 	fin.close( ); 
// 	fout.close( ); 
// 	return 0; 
// } 
