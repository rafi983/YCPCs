#include <iostream>

using namespace std;

void zaman() {
    int T;
    if (!(cin >> T)) return;

    while(T--) {
        long long N;
        cin >> N;

        if (N == 0) {
            cout << 1 << "\n";
            continue;
        }


        long long combinations = 1;

        int msb = -1;
        for(int i = 62; i >= 0; i--) {
            if((N >> i) & 1) {
                msb = i;
                break;
            }
        }

        for(int i = 0; i < msb; i++) {
            if((N >> i) & 1) {
                combinations *= 2;
            }
        }

        cout << combinations << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zaman();
    return 0;
}

