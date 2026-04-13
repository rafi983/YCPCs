#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int counts[10] = {0};
    for (int i = 0; i < n; ++i) {
        int digit = (a[i] % 10 + 10) % 10;
        counts[digit]++;

        int current_size = i + 1;
        int median_idx = (current_size - 1) / 2;

        int current_count = 0;
        int median = -1;
        for (int d = 0; d < 10; ++d) {
            current_count += counts[d];
            if (current_count > median_idx) {
                median = d;
                break;
            }
        }

        cout << median << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}

