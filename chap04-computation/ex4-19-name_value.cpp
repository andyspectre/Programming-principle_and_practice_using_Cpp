// Andrea Cocco 2020 
// Chapter 4 exercise 19 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program where you first enter a set of name and value pairs,
 *      For each pair, add the name to a vector called names and the number to a
 *      vector called scores. Terminate input with NoName 0. Check that each name
 *      is unique and terminate with an error message if a name is enterd twice.
 *      Write out all the (name, score) pairs, one per line.
*/

#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::runtime_error;

void error(string s) {
        throw runtime_error(s);
}

int main()
try{
        cout << "Enter name and score:\n";
        string n;
        int s;
        vector<string> names;
        vector<int> scores;

        while (cin >> n >> s && n!="noname") {
                for (int i=0; i<names.size(); ++i) {
                        if (n==names[i]) {
                                error("duplicate");
                        }
                }
                names.push_back(n);
                scores.push_back(s);
        }
        for (int i=0; i<names.size(); ++i) {
                cout << names[i] << " " << scores[i] << '\n';
        }
}
catch (runtime_error e) {
        cout << e.what() << '\n';
}
                        


