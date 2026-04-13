#include <iostream>

using namespace std;

void solve() {
    int X, D1, D2;
    cin >> X >> D1 >> D2;

    long long total_work = (long long)X * D1;
    long long needed_farmers = (total_work + D2 - 1) / D2;

    cout << needed_farmers << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

