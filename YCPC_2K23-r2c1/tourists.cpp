#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(int n, int c, const vector<int>& floors, int minDist) {
    int count = 1;
    int last_pos = floors[0];
    for (int i = 1; i < n; ++i) {
        if (floors[i] - last_pos >= minDist) {
            count++;
            last_pos = floors[i];
            if (count == c) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> floors(N);
    for (int i = 0; i < N; ++i) {
        cin >> floors[i];
    }
    int C;
    cin >> C;

    sort(floors.begin(), floors.end());

    int low = 0;
    int high = floors[N - 1] - floors[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(N, C, floors, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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

