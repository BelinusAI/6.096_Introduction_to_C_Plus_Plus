#include <iostream>
#include "main.h"

const string vowels = " aeiou ";

int main(){
    cout << pigLatinify("beast") << '\n';

    return 0;
}

string pigLatinify(string s){
    if(s.size() == 0) {
    return s;
    }
    if(s. find ("qu") == 0) { // Starts with "qu"
        return s. substr(2, s.size() -2) + "-" + s.substr(0, 2) + "ay";
    } else if(vowels.find(s[0]) != -1) { // Starts with a vowel
        return s + " way";
    } else {
        return s.substr(1, s.size () -1) + "-" + s[0] + "ay";
    }
}
