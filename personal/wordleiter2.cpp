#include <bits/stdc++.h>

using namespace std;

void print_iters(string word, vector<char> letters, ofstream &Myfile, int choice)
{
    // int m = 0, n = 0;
    // if (choice == 1)
    //     m = 3;
    // if (choice == 2)
    //     m = 2;
    // if (choice == 3)
    //     m = 0;

    // for (auto i = letters.begin(); i < letters.end(); i++)
    // {
    //     word[m] = *i;
    //     Myfile << word << "\n";
    // }

    for (auto i = letters.begin(); i < letters.end(); i++)
    {
        word[0] = *i;
        for (auto j = letters.begin(); j < letters.end(); j++)
        {
            word[4] = *j;
            Myfile << word << "\n";
        }
    }
}
int main()
{
    vector<char> letters = {'Q', 'W', 'Y', 'U', 'O', 'P', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'V', 'B', 'N', 'M'};
    string word1 = "COUNT";
    string word2 = "GUPRE";
    string word3 = "PURGE";

    ofstream Myfile("Outfile.txt");
    print_iters(word1, letters, Myfile, 1);
    Myfile << "\n\n";
    // print_iters(word2, letters, Myfile, 2);
    // Myfile << "\n\n";
    // print_iters(word3, letters, Myfile, 3);
    // Myfile << "\n\n";

    Myfile.close();
}