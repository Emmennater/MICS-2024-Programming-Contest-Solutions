// Letter Banner
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string generateA(int scl) {
    string out;

    int size = 5 * scl;
    int topheight = size / 2 - (size + 1) % 2;

    // Top
    for (int i = 0; i < topheight; ++i) {
        int maxletters = i * 2 + 1 + (size + 1) % 2;
        int leftletters = min(scl, maxletters);
        out += string(topheight - i, ' ');
        out += string(leftletters, 'A');

        int diff = i * 2 - scl + (size + 1) % 2;
        if (diff > 0) {
            int numSpaces = (i - scl) * 2 + 1 + (size + 1) % 2;
            if (numSpaces > 0) out += string(numSpaces, ' ');
            
            // Use remaining letters up to scl
            out += string(min(scl, maxletters - leftletters), 'A');
        }

        out += '\n';
    }

    // Middle
    for (int I = 0; I < scl; ++I) {
        for (int J = 0; J < scl; ++J) {
            out += "AAAAA";
        }
        out += '\n';
    }

    // Bottom
    int bottomheight = size - topheight - scl;
    for (int i = 0; i < bottomheight; ++i) {
        out += string(scl, 'A');
        out += string(scl * 3, ' ');
        out += string(scl, 'A');
        out += "\n";
    }

    return out;
}

string generateU(int scl) {
    string out;

    const char* letter[5] = {
        "U   U",
        "U   U",
        "U   U",
        "U   U",
        "UUUUU"
    };

    for (int i = 0; i < 5; ++i) {
        for (int I = 0; I < scl; ++I) {
            for (int j = 0; j < 5; ++j) {
                for (int J = 0; J < scl; ++J) {
                    out += letter[i][j];
                }
            }
            out += '\n';
        }
    }

    return out;
}

string generateE(int scl) {
    string out;

    const char* letter[5] = {
        "EEEEE",
        "E    ",
        "EEEEE",
        "E    ",
        "EEEEE"
    };

    for (int i = 0; i < 5; ++i) {
        for (int I = 0; I < scl; ++I) {
            for (int j = 0; j < 5; ++j) {
                for (int J = 0; J < scl; ++J) {
                    out += letter[i][j];
                }
            }
            out += '\n';
        }
    }

    return out;
}

int main() {

    int times;
    cin >> times;
    string out;

    for (int i = 0; i < times; ++i) {
        int scl;
        cin >> scl;
        out += generateA(scl) + '\n';
        out += generateU(scl) + '\n';
        out += generateE(scl) + '\n';
    }

    cout << out;

    return 0;
}