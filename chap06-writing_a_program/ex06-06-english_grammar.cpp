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
        cout << "Enter a sentence (type 'q' to quit):\n";
        char q; 
        // If the grammar rules are met, print "OK" otherwise print "not OK"
        while (cin) {
                cin >> q;
                if (q == 'q' || q == 'Q') {    // to quit the program
                        cout << "Goodbye.\n";
                        break;
                }
                else {
                        cin.putback(q);
                        bool sentence = is_sentence();
                        if (sentence) {
                                cout << "OK" << '\n';
                        }
                        else {
                                // if the sentence is "false" e.g. there is
                                // something wrong with the grammar
                                // or with the vocabulary, print "not OK"
                                // ignore bad input so that we get only one
                                // "not OK" message
                                cin.ignore(256,'\n');
                                cout << "not OK" << '\n';
                        }
                        cout << "try again\n";
                }
        }
}

/*
 *      "We must always make sure that such relatively thoughtless and
 *      unplanned 'coding' doesn't steal too much time." Bjarne at page 186.
 *
 *      I feel I spent way too much time with this exercise. Something around 
 *      two days. The main part wasn't much of a problem, also because Bjarne 
 *      gave us his solution from which of course I took inspiration.
 *      The thing is that every time the is_sentence() function returned false,
 *      it kept printing "not OK" and I wanted to fix that. 
 *      For example if I were to input "snake fly ." I would have gotten 
 *      three "not OK". That is because after is_noun() returns false the first 
 *      time, we return and then call is_sentence() again which in turn
 *      calls is_noun() (again) using "fly" as input, and then same thing with 
 *      the "." resulting in three "not OK". 
 *      I found the solution in cin.ignore() which I am not even sure it was
 *      explained in the book up until this chapter. I love C++, this book and
 *      all Bjarne's work, he is a true inspiration. I sometimes whish 
 *      that the book was more straightforward with regards to C++ facilities
 *      and less prone to hide implementation details, like it does with the
 *      custom header file that uses up until chapter 8/9 or so. Nevertheless 
 *      we must keep in mind that it is not a "quickreference guide" on C++, 
 *      rather is a scientific introduction to programming in general.
*/
                        


