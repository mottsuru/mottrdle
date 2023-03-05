#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "Word.h"
#include "wordsDatabase.hpp"

using namespace std;

Word::Word() {

    string thing = wordsDatabase[rand() % NUMBER_OF_WORDS];

    for(int i = 0; i < 5; i++) {
        letters[i] = thing.at(i);
    }

    wasntvalid = false;

}

Word::Word(string word) {
    wasntvalid = true;

    int i = 0;

    while (i < NUMBER_OF_WORDS) {

        if (wordsDatabase[i] == word) {
            for(int j = 0; j < 5; j++) {
                letters[j] = word.at(j);
            }
            wasntvalid = false;
            break;
        }

        i++;
    }

    if (wasntvalid)
        cout << "INVALID WORD GIVEN" << endl;
}

bool Word::invalid() {
    return wasntvalid;
}

char Word::getLetter(int at) {
    return letters[at];
}

string Word::asString() {
    if (wasntvalid)
        return "null";
    else {
        string dummy = "";
        for (int i = 0; i < 5; i++) {
            dummy = dummy + letters[i];
        }
        return dummy;
    }   
}

bool Word::sameAs(Word& otherword) {
    bool boolarray[5] = {false, false, false, false, false};
    for (int i = 0; i < 5; i++) {
        if(letters[i] == otherword.getLetter(i)) {
            boolarray[i] = true;
        }
    }

    if(boolarray[0] && boolarray[1] && boolarray[2] && boolarray[3] && boolarray[4])
        return true;
    else
        return false;

}