#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidProvider(string code) {

    if (code == "17" || code == "13" ||
        code == "19" || code == "14" ||
        code == "15" || code == "11" ||
        code == "18" || code == "16") {
        return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;

    if (s.length() != 14) {
        cout << "NO" << endl;
        return;
    }

    if (s.substr(0, 4) != "+880") {
        cout << "NO" << endl;
        return;
    }

    for (int i = 4; i < 14; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            cout << "NO" << endl;
            return;
        }
    }

    string providerCode = s.substr(4, 2);
    if (isValidProvider(providerCode)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

