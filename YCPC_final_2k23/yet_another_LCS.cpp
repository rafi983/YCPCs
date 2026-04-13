#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    long long lcs = dp[n][m];
    long long cost_to_merge = n + m - 2 * lcs;

    if (k >= cost_to_merge) {
        cout << (k + n + m) / 2 << endl;
    } else {
        cout << lcs + k << endl;
    }
}

int main() {
    solve();
    return 0;
}

