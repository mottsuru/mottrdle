#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "Word.h"

using namespace std;

string get_guessroster(Word guessword, Word actualword) {

    string rosterarray[5] = {"_","_","_","_","_",};

    // check to see if the letter at a point in guessword is anywhere in actual word

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (j != i) {
                if (guessword.getLetter(i) == actualword.getLetter(j))
                    rosterarray[i] = "X";
            }

        } 

    }

    // check if letters in guessword are in the same spots as in actualword

    for (int i = 0; i < 5; i++) {
        if(guessword.getLetter(i) == actualword.getLetter(i)) {
            rosterarray[i] = "O";
        }
    }

    // prepare and return the final guessroster string

    string guessroster = "";
    for(int i = 0; i < 5; i++) {
        guessroster = guessroster + rosterarray[i] + " ";
    }

    return guessroster;

}

int main () {

    srand(time(NULL));

    cout << "********** Welcome to mottrdle! **********" << endl << endl;
    cout << "This works exactly like normal Wordle, but with one key difference:" << endl << endl;
    cout << "Letters that are not in the same position BUT are in the word can be" << endl;
    cout << "highlighted more than once. That is, if your guess has two L's, but" << endl;
    cout << "the actual word only has one L, both the L's locations in your guess" << endl;
    cout << "will be highlighted as X." << endl << endl;

    cout << "also, yellow is represented as X, green as O." << endl << endl;
    
    cout << "********** Let's play! **********" << endl << endl;

    int numberofguesses = 6;

    bool notguessed = true;

    Word actualword = Word();

    while (notguessed && numberofguesses > 0) {

        string guess;
        cout << "Enter a five letter guess: ";
        cin >> guess;

        Word guessword = Word(guess);

        if (!guessword.invalid()) {

            numberofguesses--;
            string guessroster = get_guessroster(guessword, actualword);
            cout << guessword.asString() << " ::: " << guessroster << endl;

            if (guessword.sameAs(actualword)) {
                notguessed = false;
                break;
            }
            else if (numberofguesses == 0) {
                break;
            }
            else {
                cout << "Guesses remaining: " << numberofguesses << endl;
            }

        }

    }

    if (notguessed) {
        cout << "Sorry, You Lost! The Correct word was: " << actualword.asString() << endl;
    }
    else {
        cout << "Yay! You Won!" << endl;
    }

    return EXIT_SUCCESS;
}