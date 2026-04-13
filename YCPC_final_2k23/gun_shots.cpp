#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
int n;

long long get_cost(int i, int j, int k) {
    int left_idx = i - 1;
    int right_idx = j + 1;

    long long val_l = (left_idx >= 0) ? a[left_idx] : 0;
    long long val_r = (right_idx < n) ? a[right_idx] : 0;

    if (val_l > 0 && val_r > 0) {
        return val_l * val_r;
    } else if (val_l > 0) {
        return val_l;
    } else if (val_r > 0) {
        return val_r;
    } else {
        return a[k];
    }
}

void solve() {
    if (!(cin >> n)) return;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                long long current_cost = get_cost(i, j, k);
                long long left_part = (k > i) ? dp[i][k - 1] : 0;
                long long right_part = (k < j) ? dp[k + 1][j] : 0;
                dp[i][j] = max(dp[i][j], left_part + right_part + current_cost);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
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

