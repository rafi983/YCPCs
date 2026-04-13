#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    if (cin >> N >> W) {
        vector<int> w(N);
        for (int i = 0; i < N; ++i) {
            cin >> w[i];
        }

        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        vector<int> dp(W + 1, 0);

        for (int i = 0; i < N; ++i) {
            for (int j = W; j >= w[i]; --j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }

        cout << dp[W] << endl;
    }
    return 0;
}

