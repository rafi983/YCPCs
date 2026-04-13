#include <iostream>

using namespace std;

void solve() {
    unsigned long long A, B;
    cin >> A >> B;
    unsigned long long res = ((A % 100) * (B % 100)) % 100;
    cout << res << endl;
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

