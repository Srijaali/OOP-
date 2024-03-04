/*
Name : Syeda Rija Ali
ID : 23K-0057
DESC: making a constant string function to check if the sring only has alphabets
*/

/*
MAKING A FUNCTION CONSTANT BECAUSE: It could potentially modify member variables of validatestring class, also helps ensure thread safety
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class ValidateString{
    private:
    string checkChar;

    public:

     ValidateString() : checkChar() {}
     ValidateString(string alph) : checkChar(alph) {}

     void setString(string alph){
        checkChar = alph;
     }

     string getString(){
        return checkChar;
     }

    bool isalpha(char c) const {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

     void validatingString() const { 
        cout << checkChar << endl;
        bool valid = true;
        for(char c : checkChar){
            if(!isalpha(c)  && !isspace(c) ){
                valid = false;
                break;
            }
        }
        if(!valid){
            cout << "INVALID STRING! contains numbers or special characters" << endl;
        }
     
        else{
        cout << "The string is valid!" << endl;
        }
        cout << endl;
     }

};

int main(){

    ValidateString s1("abcde");
    ValidateString s2("12sr");
    ValidateString s3("1s5*32hjio");
    ValidateString s4("OOP is a programming paradigm");
    ValidateString s5("oop£");

    cout << "String 1: ";
     s1.validatingString();

     cout << "String 2: ";
     s2.validatingString();

     cout << "String 3: ";
     s3.validatingString();

    cout << "String 4: ";
    s4.validatingString();

    cout << "String 5: ";
    s5.validatingString();

    return 0;
}
