// Farkel roll
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int scoreRolls(vector<int>& rolls) {
    int score = 0;
    int occurences[7] = { 0 };
    
    for (int roll : rolls) {
        ++occurences[roll];
    }

    // Straight
    bool isStraight = true;
    for (int i = 1; i <= 6; ++i) {
        if (occurences[i] != 1) {
            isStraight = false;
            break;
        }
    }

    if (isStraight) return 1500;

    for (int i = 1; i <= 6; ++i) {
        // Six of a kind
        if (occurences[i] == 6) return 3000;
        
        // Five of a kind
        if (occurences[i] == 5) {
            occurences[i] -= 5;
            score += 2000;
        }

        // Four of a kind
        if (occurences[i] == 4) {
            occurences[i] -= 4;
            score += 1000;
        }
    }

    // Three pairs or two triplets
    int twos = 0;
    int threes = 0;
    for (int i = 0; i <= 6; ++i) {
        if (occurences[i] == 2) ++twos;
        if (occurences[i] == 3) ++threes;
    }

    if (twos == 3) return 1500;
    if (threes == 2) return 2500;

    // Three of a kind
    if (occurences[1] == 3) { occurences[1] -= 3; score += 300; }
    if (occurences[2] == 3) { occurences[2] -= 3; score += 200; }
    if (occurences[3] == 3) { occurences[3] -= 3; score += 300; }
    if (occurences[4] == 3) { occurences[4] -= 3; score += 400; }
    if (occurences[5] == 3) { occurences[5] -= 3; score += 500; }
    if (occurences[6] == 3) { occurences[6] -= 3; score += 600; }

    // Individuals
    score += occurences[1] * 100 + occurences[5] * 50;

    return score;
}

int main() {

    int times;
    cin >> times;
    cin.ignore();
    vector<int> rows[times];

    // Input data
    for (int i = 0; i < times; ++i) {
        string line;
        getline(cin, line);
        stringstream stream(line);
        vector<int> rolls;

        while (!stream.eof()) {
            int roll;
            stream >> roll;
            rolls.push_back(roll);
        }

        std::sort(rolls.begin(), rolls.end());

        rows[i] = rolls;
    }

    // Output data
    for (int i = 0; i < times; ++i) {
        for (int roll : rows[i]) {
            cout << roll << " ";
        }
        cout << "scores " << scoreRolls(rows[i]) << endl;
    }

    return 0;
}