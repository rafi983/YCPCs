#include <iostream>
#include <string>

using namespace std;

void solve() {
    string n;
    cin >> n;
    long long sum = 0;
    for (char c : n) {
        sum += (c - '0');
    }
    if (sum % 3 == 0) {
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

