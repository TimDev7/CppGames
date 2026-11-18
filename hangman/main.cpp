#include <iostream>
#include <set>
#include <ctime>

using namespace std;

string words[] = {"apple", "house", "accommodation", "code", "introduction", "omori"};
int tries = 6;
int chars_left = 0;

int main() {
    srand(time(0));

    // Save cursor position
    //cout << "\033[s";

    cout << "### Hangman ###\nGuess the word in 6 tries or you will lose!\n";

    string word = words[rand()%(size(words))];
    chars_left = word.size();
    set<char> correct_letters = {};

    while (tries > 0) {
        // Print word
        cout << "Word: ";
        for (int i = 0; i < word.size(); i++)
        {
            if (correct_letters.find(word.at(i)) != correct_letters.end())
            {
                cout << word.at(i);
            }
            else 
            {
                cout << "*";
            }
        }
        cout << "\tChars left: " << chars_left << "\n";

        // Input
        char letter;
        cin >> letter;

        // Move cursor to first program ouput row and clear all rows below
        //cout << "\033[u" << "\033[J";

        // Check if letter in word
        if ((word.find(letter) != string::npos) && (correct_letters.find(letter) == correct_letters.end()))
        {
            correct_letters.insert(letter);    
        } 
        else 
        {
            tries--;
        }

        chars_left = word.size();
        for (int i = 0; i < word.size(); i++) {
            if (correct_letters.find(word.at(i)) != correct_letters.end()){
                chars_left --;
            }
        }
        if (chars_left == 0){
            cout << "You won!!!";
            return 0;
        }
        
    }

    cout << "You lost...";

    return 0;
}