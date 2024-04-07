// Highly recursive function
#include <iostream>
#include <unordered_map>
#include <stdint.h>
using namespace std;

struct Result {
    int64_t m;
    int64_t n;
    int64_t v;
};

int64_t F(int64_t m, int64_t n) {
    static unordered_map<string, int64_t> dict;
    string key = to_string(m) + "," + to_string(n);
    if (dict.find(key) != dict.end())
        return dict[key];
    
    int64_t res;
    if (m >= n && n > 10) res = 10;
    else if (n <= 10) res = m + n;
    else if (m < n && n > 10) res = F(m + 1, n - 2) + F(m + 3, n) - F(m + 4, n - 1);
    dict[key] = res;
    return res;
}

int main() {

    int times;
    cin >> times;
    Result results[times];

    for (int i = 0; i < times; ++i) {
        int64_t m, n;
        cin >> m >> n;
        results[i] = { m, n, F(m, n) };
    }

    for (int i = 0; i < times; ++i) {
        cout << "Case " << (i + 1) << ": F(" << results[i].m << "," << results[i].n << ") = " << results[i].v << endl;
    }

    return 0;
}
