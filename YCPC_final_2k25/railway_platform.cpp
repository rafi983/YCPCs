#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree;
int max_val;

void update(int idx, int val) {
    while (idx <= max_val) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void zaman() {
    int t;
    if (!(cin >> t)) return;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> sorted_a;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sorted_a.push_back(a[i]);
        }

        sort(sorted_a.begin(), sorted_a.end());
        sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

        max_val = sorted_a.size();
        tree.assign(max_val + 1, 0);

        long long valid_pairs = 0;
        for (int i = 0; i < n; ++i) {
            int rank = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;


            int count_smaller = query(rank - 1);
            int count_greater_equal = i - count_smaller;

            valid_pairs += count_greater_equal;

            update(rank, 1);
        }
        cout << valid_pairs << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zaman();
    return 0;
}
