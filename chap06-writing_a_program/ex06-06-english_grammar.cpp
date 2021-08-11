// Andrea Cocco 2020 
// Chapter 6 exercise 6 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that checks if a sentence is correct according to the
 *      "English" grammar in §6.4.1 Assume that every sentence is terminated by
 *      a full stop (.) surrounded by whitespace. For each sentence entered,
 *      the program should simply respond "OK" or "not OK".
*/

#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;


// Initialize a "vocabulary" of nouns, verbs and conjunctions
vector<string> noun = {"fish", "bird"};
vector<string> verb = {"swim", "fly"};
vector<string> conjuction = {"and", "or"};

// Check input noun against "vocabulary"
bool is_noun(string s)
{
        for (int i=0; i<=noun.size(); ++i) {
                if (s == noun[i]) return true;
        }
        return false;
}

// Check input verb against "vocabulary"
bool is_verb(string v)
{
        for (int i=0; i<=verb.size(); ++i) {
                if (v == verb[i]) return true;
        }
        return false;
}

// Check input conjuction against "vocabulary"
bool is_conj(string c)
{
        for (int i=0; i<=conjuction.size(); ++i) {
                if (c == conjuction[i]) return true;
        }
        return false;
}

// Check input against grammar (first noun, then verb,
// then "." or another sentence)
bool is_sentence()
{
        string n;
        cin >> n;
        if (!is_noun(n)) return false;

        string v;
        cin >> v;
        if (!is_verb(v)) return false;

        string c;
        cin >> c;
        if (c == ".") return true;    // to end the sentence
        if (!is_conj(c)) return false;
        return is_sentence();
}

int main()
{
        cout << "Enter a sentence:\n";
        
        // If the grammar rules are met, print "OK" otherwise print "not OK"
        while (cin) {
                bool sentence = is_sentence();
                if (sentence) {
                        cout << "OK" << '\n';
                }
                else {
                        cout << "not OK" << '\n';
                }
                cout << "try again" << '\n';
        }
}
                        


