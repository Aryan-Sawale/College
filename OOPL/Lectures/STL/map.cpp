// map<key_type , value_type> map_name;

#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main ()
{
    map<int,int> m{ {1,2} , {2,3} , {3,4} };
    /* creates a map m with keys 1,2,3 and 
        their corresponding values 2,3,4 */  
    
    map<string,int> map1; 
    /*  creates a map with keys of type character and 
      values of type integer */
    
    map1["abc"]=100;    // inserts key = "abc" with value = 100
    map1["b"]=200;      // inserts key = "b" with value = 200
    map1["c"]=300;      // inserts key = "c" with value = 300
    map1["def"]=400;    // inserts key = "def" with value = 400
    
    map<char,int> map2 (map1.begin(), map1.end());
    /* creates a map map2 which have entries copied 
        from map1.begin() to map1.end() */ 
    
    map<int,int> map3 (m);
    /* creates map map3 which is a copy of map m */

    //-------------------------------------------------------------------------------------

    map<int,string> map4{ {1,"nikhilesh"} , {2,"shrikant"} , {3,"ashish"} };
    
    
    cout << map4.at(1) ;  // prints value associated with key 1 ,i.e nikhilesh
    cout << map4.at(2) ;  // prints value associated with key 2 ,i.e shrikant
    
    /* note that the parameters in the above at() are the keys not the index */
    
    cout << map4[3] ; // prints value associated with key 3 , i.e ashish

    //--------------------------------------------------------------------------------------

    map<int,int> map5{{1,2} , {2,3} , {3,4} };
    
    map5.insert( pair<int,int> (4,5));
    /* inserts a new entry of key = 4 and value = 5 in map m */
    
    /* make_pair() can also be used for creating a pair */
    map5.insert( make_pair(5, 6));
    /* inserts a new entry of key = 5 and value = 6 */
    
    
    map<int, int>::iterator i , j;
    i = map5.find(2);    // points to entry having key =2
    j = map5.find(5);    // points to entry having key =5
    
    map<int,int> new_m;
    
    new_m.insert(i,j);
     /* insert all the entries which are pointed 
     by iterator i to iterator j*/ 
    
    map5.insert( make_pair(3,6));  
     // do not insert the pair as map m already contain key = 3 */ 
    
    // map5.insert_or_assign( make_pair(3,6));  // assign value = 6 to key =3   

    //------------------------------------------------------------------------
    // empty map container
    map<int, int> gquiz1;
  
    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(7, 10));
  
    // printing map gquiz1
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
  
    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
  
    // print all elements of the map gquiz2
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
  
    // remove all elements up to
    // element with key=3 in gquiz2
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
  
    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
  
    cout << endl;
  
    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << gquiz1.lower_bound(5)->second << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << gquiz1.upper_bound(5)->second << endl;
}