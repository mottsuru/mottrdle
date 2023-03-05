#include <string>

using namespace std;

class Word {

    public:

    // constructors
        Word();
        Word(string);

    // accessors
        char getLetter(int);
        bool invalid();

    // mutators

    // other
        
        string asString();
        bool sameAs(Word&);

    private:
        char letters[5];
        bool wasntvalid;
};