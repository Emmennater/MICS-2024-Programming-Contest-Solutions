// Weather Forcast
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Month {
    float avgMax;
    float avgMin;
    int monthIdx;
};

vector<string> getTokenVector(string userLine, char sep = ' '){
    vector<string> tmpVec;
    stringstream streamObj = stringstream (userLine);
    string currentToken;
    while(getline(streamObj, currentToken, sep)) {
        tmpVec.push_back(currentToken);
    }
    return tmpVec;
}

int main() {

    int entries;
    cin >> entries;
    cin.ignore();

    vector<Month> months;
    int pMonthIdx = -1;
    int totalMax = 0;
    int totalMin = 0;
    int maxCount = 0;
    int minCount = 0;

    for (int i = 0; i < entries; ++i) {
        string line;
        getline(cin, line);
        vector<string> tokens = getTokenVector(line, ',');
        
        stringstream date(tokens[0]);
        int month, day, year;
        date >> month;
        date.ignore();
        date >> day;
        date.ignore();
        date >> year;

        // Skip dates not March or April
        if (month != 3 && month != 4) continue;

        int monthIdx = year * 12 + month;
        if (pMonthIdx != -1 && monthIdx != pMonthIdx) {
            float avgMax = maxCount == 0 ? 0 : (float) totalMax / maxCount;
            float avgMin = minCount == 0 ? 0 : (float) totalMin / minCount;
            months.push_back(Month{avgMax, avgMin, pMonthIdx});
            totalMax = 0;
            totalMin = 0;
            maxCount = 0;
            minCount = 0;
        }

        // Read min max data
        if (tokens[1].length() > 0) {
            totalMax += stof(tokens[1]);
            ++maxCount;
        }
        if (tokens.size() == 3 && tokens[2].length() > 0) {
            totalMin += stof(tokens[2]);
            ++minCount;
        }

        pMonthIdx = monthIdx;
    }

    // Push remaining data
    if (maxCount && minCount) {
        months.push_back(Month{(float) totalMax / maxCount, (float) totalMin / minCount, pMonthIdx});
    }

    // Print data
    for (Month m : months) {
        string month = ((m.monthIdx - 1) % 12 == 2) ? "March" : "April";
        int year = m.monthIdx / 12;
        cout << month << " " << year << ": " <<
            "Average daily high temperature " << round(m.avgMax * 10) / 10 <<
            " and Average daily low temperature " << round(m.avgMin * 10) / 10 << endl;
    }

    return 0;
}