#include <bits/stdc++.h>

using namespace std;

void print_iters(string word, vector<char> letters, ofstream &Myfile, int choice)
{
    int m = 0, n = 0;
    if (choice == 1)
        m = 2, n = 4;
    if (choice == 2)
        m = 1, n = 4;
    if (choice == 3)
        m = 1, n = 2;

    for (auto i = letters.begin(); i < letters.end(); i++)
    {
        word[m] = *i;
        for (auto j = letters.begin(); j < letters.end(); j++)
        {
            word[n] = *j;
            Myfile << word << "\n";
        }
    }
}
int main()
{
    vector<char> letters = {'Q', 'W', 'Y', 'O', 'A', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'V', 'B'};
    string word1 = "ALBOK";
    string word2 = "ABLOK";
    string word3 = "ABKOL";

    ofstream Myfile("Outfile.txt");
    print_iters(word1, letters, Myfile, 1);
    Myfile << "\n\n";
    print_iters(word2, letters, Myfile, 2);
    Myfile << "\n\n";
    print_iters(word3, letters, Myfile, 3);
    Myfile << "\n\n";

    Myfile.close();
}