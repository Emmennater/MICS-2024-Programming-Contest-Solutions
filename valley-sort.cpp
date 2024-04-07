// Valley Sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int size;
    cin >> size;
    vector<int> values(size);

    for (int i = 0; i < size; ++i) {
        cin >> values[i];
    }
    
    sort(values.begin(), values.end());

    for (int i = size - 1; i >= 0; i -= 2) {
        cout << values[i] << "\n";
    }

    for (int i = size % 2; i < size; i += 2) {
        cout << values[i] << "\n";
    }

    return 0;
}