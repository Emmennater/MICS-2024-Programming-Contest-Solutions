// Kudok 16
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
using std::cout;

vector<string> getTokenVector(string userLine, char sep = ' '){
    vector<string> tmpVec;
    stringstream streamObj = stringstream (userLine);
    string currentToken;
    while(getline(streamObj, currentToken, sep)) {
        if (currentToken != "") tmpVec.push_back(currentToken);
    }
    return tmpVec;
}

void printPuzzle(int puzzle[5][5]) {
    cout << "   ";
    for (int j = 1; j < 5; ++j) {
        cout << puzzle[0][j] << " ";
    }
    cout << endl;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int n = puzzle[i][j];
            if (n < 10) cout << " ";
            cout << n << " ";
        }
        cout << endl;
    }
}

void loadPuzzle(int puzzle[5][5]) {
    vector<string> tokenRows[5];
        
    for (int j = 0; j < 5; ++j) {
        string row;
        getline(cin, row);
        tokenRows[j] = getTokenVector(row);
    }

    puzzle[0][0] = 0; // Unused
    for (int k = 0; k < tokenRows[0].size(); ++k) {
        string token = tokenRows[0][k];
        puzzle[0][k + 1] = stoi(token);
    }

    for (int j = 1; j < 5; ++j) {
        for (int k = 0; k < tokenRows[j].size(); ++k) {
            string token = tokenRows[j][k];
            puzzle[j][k] = (token == "?") ? 0 : stoi(token);
        }
    }
}

int getUsedNumbers(int puzzle[5][5], int used[16]) {
    int remaining = 16;
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            int idx = puzzle[i][j] - 1;
            if (idx != -1) {
                used[idx] = 1;
                --remaining;
            }
        }
    }

    return remaining;
}

pair<int, int> getNextEmptySlot(int puzzle[5][5]) {
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (puzzle[i][j] == 0) return pair<int, int>(i, j);
        }
    }

    // This should never occure because of base case check in "solvePuzzleHelper"
    return pair<int, int>(0, 0);
}

bool verifyMove(int puzzle[5][5], int row, int col) {
    // Verify row
    int total = 0;
    bool anyZero = false;
    for (int j = 1; j < 5; ++j) {
        if (!puzzle[row][j]) { anyZero = true; break; }
        total += puzzle[row][j];
    }

    if (!anyZero && total != puzzle[row][0]) return false;

    // Verify col
    total = 0;
    anyZero = false;
    for (int i = 1; i < 5; ++i) {
        if (!puzzle[i][col]) return true;
        total += puzzle[i][col];
    }
    return anyZero || total == puzzle[0][col];
}

bool solvePuzzleHelper(int puzzle[5][5], int used[16], int remaining) {
    // 1) Pick a number from remaining and fill next spot
    // 2) Check if illegal move, if so backtrack
    // 3) Repeat until puzzle is solved

    if (remaining == 0) return true;

    pair<int, int> idx = getNextEmptySlot(puzzle);

    for (int n = 1; n <= 16; ++n) {
        if (used[n - 1]) continue;

        puzzle[idx.first][idx.second] = n;
        used[n - 1] = 1;

        if (verifyMove(puzzle, idx.first, idx.second) &&
            solvePuzzleHelper(puzzle, used, remaining - 1)) {
            return true;
        }

        puzzle[idx.first][idx.second] = 0;
        used[n - 1] = 0;
    }

    return false;
}

void solvePuzzle(int puzzle[5][5]) {
    int used[16] = { 0 };
    int remaining = getUsedNumbers(puzzle, used);
    bool res = solvePuzzleHelper(puzzle, used, remaining);
}

int main() {

    int numPuzzles;
    cin >> numPuzzles;
    cin.ignore();
    int puzzles[numPuzzles][5][5];

    for (int i = 0; i < numPuzzles; ++i) {
        loadPuzzle(puzzles[i]);
    }

    for (int i = 0; i < numPuzzles; ++i) {
        solvePuzzle(puzzles[i]);
    }

    for (int i = 0; i < numPuzzles; ++i) {
        printPuzzle(puzzles[i]);
        cout << endl;
    }

    return 0;
}