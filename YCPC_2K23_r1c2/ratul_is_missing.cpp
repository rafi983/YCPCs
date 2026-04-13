#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    bool found = false;
    while (cin >> s) {
        if (s == "Ratul") {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

