#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    string palindrome = "";
    string middleChar = "";

    for (auto it = charCount.begin(); it != charCount.end(); ++it) {
        char c = it->first;
        int count = it->second;

        if (count % 2 == 1) {
            // If there's a character with an odd frequency, store it for the middle.
            if (middleChar.empty()) {
                middleChar = c;
            } else {
                // If there's already a character for the middle, it's impossible to create a palindrome.
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }

        // Append half of the characters to the beginning and half to the end.
        for (int i = 0; i < count / 2; i++) {
            palindrome = c + palindrome;
            palindrome = palindrome + c;
        }
    }

    if (!middleChar.empty()) {
        // If there's a character for the middle, place it in the middle of the palindrome.
        palindrome = palindrome.substr(0, palindrome.size() / 2) + middleChar + palindrome.substr(palindrome.size() / 2);
    }

    cout << palindrome << endl;

    return 0;
}
