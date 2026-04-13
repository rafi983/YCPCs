#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &v : a) cin >> v;

        vector<int> blocks;
        blocks.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] != a[i - 1]) blocks.push_back(a[i]);
        }

        vector<int> tails;
        tails.reserve(blocks.size());
        for (int v : blocks) {
            auto it = upper_bound(tails.begin(), tails.end(), v);
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }

        int ops = static_cast<int>(blocks.size() - tails.size());
        cout << ops << '\n';
    }

    return 0;
}

