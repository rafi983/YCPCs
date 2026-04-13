#include <iostream>
#include <vector>

using namespace std;

void zaman() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    vector<int> h(N + 2, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
    }

    vector<int> next_drop(N + 2, N + 1);


    for (int i = N; i >= 1; --i) {
        if (h[i] > h[i+1]) {
            next_drop[i] = i;
        } else {
            next_drop[i] = next_drop[i+1];
        }
    }

    vector<int> prev_rise(N + 2, 0);

    for (int i = 2; i <= N; ++i) {
        if (h[i-1] < h[i]) {
            prev_rise[i] = i - 1;
        } else {
            prev_rise[i] = prev_rise[i-1];
        }
    }

    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;


        int u = next_drop[l];
        if (u > r) u = r;

        int v = prev_rise[r] + 1;
        if (v < l) v = l;

        if (u == v) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zaman();
    return 0;
}

