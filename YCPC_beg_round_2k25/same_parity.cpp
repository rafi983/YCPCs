#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;

        int oddVals = 0, evenVals = 0;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            if (v & 1) ++oddVals;
            else ++evenVals;
        }

        int oddPos = (n + 1) / 2;
        int evenPos = n / 2;

        bool allEvenSums = (oddVals >= oddPos) && (evenVals >= evenPos);
        bool allOddSums = (oddVals >= evenPos) && (evenVals >= oddPos);

        cout << ((allEvenSums || allOddSums) ? "YES" : "NO") << '\n';
    }

    return 0;
}

