#include<iostream>
#include<string.h>
using namespace std;

class personal
{
 public:
  string name;
  string address;
  string gender;
  string birthdate;
  string dob;
  void get_personal()
  {
    cout<<"Enter name: "<<endl;
    cin>>name;
    cout<<"Enter Address: "<<endl;
    cin>>address;
    cout<<"Enter Birthdate(dd/mm/yyyy): "<<endl;
    cin>>birthdate;
    cout<<"Enter gender(M/F): "<<endl;
    cin>>gender;
  }
};

class professional
{
 public:
  int total_exp;
  string name_project;
  string company_name;
  void get_professional()
  {
    cout<<"Enter total experience: "<<endl;
    cin>>total_exp;
    cout<<"Enter Project name: "<<endl;
    cin>>name_project;
    cout<<"Enter company name: "<<endl;
    cin>>company_name;
  }
};

class educational
{
 public:
  int ssc;
  int hsc;
  int grad_marks;
  void get_educational()
  {
    cout<<"Enter SSC marks: "<<endl;
    cin>>ssc;
    cout<<"Enter HSC marks: "<<endl;
    cin>>hsc;
    cout<<"Enter Graduation marks: "<<endl;
    cin>>grad_marks;
  }
};

class biodata: public personal,public educational,public professional
{
 public:
 void print_biodata()
 {
    cout<<endl;
    cout<<"*********************Employee Biodata*******************"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"________________Personal Details________________________"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"birthdate: "<<birthdate<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"--------------------------------------------------"<<endl;
    
    cout<<"________________Academic Details________________________"<<endl;
    cout<<"SSC marks: "<<ssc<<endl;
    cout<<"HSC marks: "<<hsc<<endl;
    cout<<"Graduation marks: "<<grad_marks<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    
    cout<<"_______________Professional Details____________________"<<endl;
    cout<<"Years of experience: "<<total_exp<<endl;
    cout<<"Project name: "<<name_project<<endl;
    cout<<"Company name: "<<company_name<<endl;
 }
};

int main()
{
 biodata b;
 b.get_personal();
 b.get_educational();
 b.get_professional();
 b.print_biodata();
}