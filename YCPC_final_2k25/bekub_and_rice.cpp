#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool zaman_check_segment(int n, const vector<int>& weights, long long target_weight) {
    long long current_segment_weight = 0;
    int start_ptr = 0;

    for (int end_ptr = 0; end_ptr < n; ++end_ptr) {
        current_segment_weight += weights[end_ptr];

        while (current_segment_weight > target_weight && start_ptr <= end_ptr) {
            current_segment_weight -= weights[start_ptr];
            start_ptr++;
        }

        if (current_segment_weight == target_weight) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long w;

    if (cin >> n >> w) {
        vector<int> weights(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }

        vector<long long> divisors;
        for (long long i = 1; i * i <= w; ++i) {
            if (w % i == 0) {
                divisors.push_back(i);
                if (i * i != w) {
                    divisors.push_back(w / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());

        bool possible = false;
        for (long long d : divisors) {
            if (zaman_check_segment(n, weights, d)) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

