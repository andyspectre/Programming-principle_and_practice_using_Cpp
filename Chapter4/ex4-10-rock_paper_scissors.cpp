// Andrea Cocco 2021
// Chapter 4 Exercise 10

/*
        Write a program that plays the game "Rock, paper, scissors." 
        If you are not familiar with the game do some research
        (e.g. on the web using Google). Research is a common task 
        for programmers. Use a switch statement to solve this exercise.
        Also, the machine should give random answers 
        (i.e., select the next Rock, paper, or scissors randomly). 
        Real randomness is too hard to provide just now, so just build 
        a vector with a sequence of values to be used as "the next value."
        If you build the vector into the program, it will always play 
        the same game, so maybe you should let the user enter some values).
        Try variations to make it less easy for the user to guess which 
        move the machine will do next.
        NOTE: This is Bjarne Stroustrup's solution. Zero credit to me for
        this one.
*/

#include<iostream>

int v1 = 1;
int v2 = 2;

int fib()
/*
        generate the next element of a (Fibonacci) series:
        1 2 3 5 8 13 21 34
*/
{
        int s = v1+v2;
        if (s<=0) {
                s = 1;  
        }
        v1 = v2;
        v2 = s;
        return s;
}

void generate(int seed)
        // use the seed to choose where in the sequence the game starts
{
                if (seed<0) {
                        seed = -seed;   // don't want a negative number
                }
                seed %=10;              // don't want a number larger than 9
                if (seed==0) {
                        return;         // don't bother: use the default
                }
                for (int i=0 ; i<seed; ++i) {
                        fib();          // move seed steps forward
                }
}

int next_play() 
        // generate a reasonably obscure sequence of 0s, 1s, and 2s
{
        return fib()%3; // we are only interested in a value 0, 1, or 2 
}

int main()
//try
{
        std::cout << "enter an integer \"seed\" to help me play: ";
        int seed = 0;
        std::cin >> seed;
        generate(seed); // get the computer ready to play
        // let's keep track of who's winning:
        int count1 = 0; // user's score
        int count2 = 0; // computer's score
        int draws = 0;  // number of draws/ties

        std::cout << "enter \"rock\", \"paper\", or \"scissors\"\n"
                << "(I'll do the same and promises not to cheat"
                << " by peeping at your input): ";
        std::string s = "";
       
        // we'll go as long as we get "good" input and then stop
        while(std::cin >> s) {  

        // the computer prefers numbers, so convert string representations 
        // to numbers. We prefer strings, so convert abbreviations to full words
                int x = 0;
                if (s=="scissors" || s=="s") {
                        x = 0;
                        s = "scissors";
                }
                else if (s=="rock" || s=="r") {
                        x = 1;
                        s = "rock";
                }
                else if (s=="paper" || s=="p") {
                        x = 2;
                        s = "paper";
                }
                else {
                        std::cout << "sorry: bad operator";
                }

                int xx = next_play();
                std::cout << xx;
                std::string ss = " ";   // computers play

                // convert numeric representations to strings
                switch(xx) {    
                case 0: 
                        ss = "scissors"; 
                        break;
                case 1: 
                        ss = "rock"; 
                        break;
                case 2: 
                        ss = "paper"; 
                        break;
                }
        
                if (x==xx) {
                        std::cout << "a draw!\n";
                        ++draws;
                }
                else {
                        std::string res = "I win!";
                        if (xx==0 && x==1) {
                                res = "You win!";       // rock beats sissors
                                ++count1;
                        }
                        else if (xx==1 && x==2) {
                                res = "You win!";       // paper beats rock
                                ++count1;
                        }
                        else if (xx==2 && x==0) {
                                res = "You win!";       // scissors beat paper
                                ++count1;
                        }
                        else
                                ++count2;

                        std::cout << "you said \"" << s << "\" I said \"" 
                                << ss << "\": " << res ;
                        std::cout << " score: you==" << count1 << " me==" 
                                << count2 << " same==" << draws << "\n";
                }
                std::cout << "Please try again: ";
        }
        std::cout << "exit because of bad input\n";
}
