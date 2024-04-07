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
        
        if (roll == 1) score += 100;
        if (roll == 5) score += 50;
    }

    if (occurences[1] == 3) score += 300;
    if (occurences[2] == 3) score += 200;
    if (occurences[3] == 3) score += 300;
    if (occurences[4] == 3) score += 400;
    if (occurences[5] == 3) score += 500;
    if (occurences[6] == 3) score += 600;

    bool allOnes = true;
    int countTwos = 0;
    int countThrees = 0;
    for (int i = 1; i <= 6; ++i) {
        if (occurences[i] != 1) allOnes = false;
        switch (occurences[i]) {
            case 2: ++countTwos; break;
            case 3: ++countThrees; break;
            case 6: score += 3000; break;
            case 5: score += 2000; break;
            case 4: score += 1000; break;
        }
    }

    if (allOnes) score += 1500;
    if (countTwos == 3) score += 1500;
    if (countThrees == 2) score += 2500;

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