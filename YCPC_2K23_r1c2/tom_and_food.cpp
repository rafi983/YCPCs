#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long current_sum = 0;
    for (int i = 0; i < K; ++i) {
        current_sum += A[i];
    }

    long long max_sum = current_sum;

    for (int i = K; i < N; ++i) {
        current_sum += A[i] - A[i - K];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

