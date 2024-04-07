// Code Decyphering
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    string passphrase;
    getline(cin, passphrase);

    char sub[passphrase.length()][26];
    
    for (int i = 0; i < passphrase.length(); ++i) {
        char c = tolower(passphrase[i]);
        for (int j = 0; j < 26; ++j) {
            sub[i][(j + c - 'a') % 26] = 'a' + j;
        }
    }

    // Print substitution
    // for (int i = 0; i < passphrase.length(); ++i) {
    //     for (int j = 0; j < 26; ++j) {
    //         cout << sub[i][j];
    //     }
    //     cout << endl;
    // }

    int lines, row;
    cin >> lines;
    string out;
    cin.ignore();

    for (int i = 0; i < lines; ++i) {
        string in;
        getline(cin, in);

        for (char c : in) {
            bool isLetter = c >= 'A' && c <= 'z';
            if (!isLetter) {
                out += c;
                continue;
            }

            bool isUpper = c < 'a';
            char c2 = sub[row][tolower(c) - 'a'];
            out += isUpper ? toupper(c2) : c2;
            row = (row + 1) % passphrase.length();
        }

        out += '\n';
    }

    cout << out;

    return 0;
}