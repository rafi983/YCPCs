#include <iostream>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int H = 5 + (N + 1) / 2;

        // Top part
        for (int i = 1; i <= H; ++i) {
            for (int j = 0; j < H - i; ++j) {
                cout << " ";
            }
            for (int j = 0; j < 2 * i - 1; ++j) {
                cout << "*";
            }
            cout << endl;
        }

        // Trunk
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << " ";
            }
            for (int j = 0; j < N; ++j) {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}

