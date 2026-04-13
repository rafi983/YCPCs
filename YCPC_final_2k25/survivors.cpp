#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zaman() {
    long long N, T;
    if (!(cin >> N >> T)) return;

    vector<long long> gaps;
    bool possible_immediate_fail = false;

    for (int i = 0; i < N; ++i) {
        long long r;
        cin >> r;
        if (r >= T) {
            possible_immediate_fail = true;
        } else if (r > 0) {
            gaps.push_back((T - 1) / r);
        }
    }

    if (possible_immediate_fail) {
        cout << 0 << endl;
        return;
    }


    long long left = 1, right = 200000000000000LL;
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long demand = 0;
        bool fail = false;
        for (long long g : gaps) {
            demand += (mid / g);
            if (demand > mid) {
                fail = true;
                break;
            }
        }

        if (fail) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zaman();
    return 0;
}
