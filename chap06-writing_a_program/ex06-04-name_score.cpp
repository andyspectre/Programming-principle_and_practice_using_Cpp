// Andrea Cocco 2020 
// Chapter 6 exercise 4
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
*      Define a class Name_value that holds a string and a value.
*      Rework exercise 19 in chapter 4 to use a vector<Name_value>
*      instead of two vectors.
*/

#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::runtime_error;

struct Name_value {
        Name_value(string n, int s)    // constructor
                :name{n}, score{s}    // member initializer list
        {
        }
        string name;
        int score;
};

void error(string s) {
        throw runtime_error(s);
}

int main()
try{
        vector<Name_value> nameVal;
        string n;
        int v;

        cout << "Enter some names and values:\n";

        while (cin>>n>>v && n!="noname") {
                for (int i=0; i<nameVal.size(); ++i) {
                        if (n==nameVal[i].name) {
                                error("duplicate");
                        }
                }
                nameVal.push_back(Name_value(n,v)); 
        }
        
        for (int i=0; i<nameVal.size(); ++i)
                cout << nameVal[i].name << ',' << nameVal[i].score << '\n';
}
catch (runtime_error e) {
        cout << e.what() << '\n';
}
