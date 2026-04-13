#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
    int size;
    vector<int> tree;

public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void add(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    vector<long long> sorted_a;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted_a.push_back(a[i]);
    }

    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    auto get_rank = [&](long long val) {
        return lower_bound(sorted_a.begin(), sorted_a.end(), val) - sorted_a.begin() + 1;
    };

    int m = sorted_a.size();
    vector<int> compressed_a(n);
    for (int i = 0; i < n; ++i) {
        compressed_a[i] = get_rank(a[i]);
    }

    vector<long long> left_smaller(n, 0);
    vector<long long> right_larger(n, 0);

    FenwickTree ft_left(m);
    for (int i = 0; i < n; ++i) {
        left_smaller[i] = ft_left.query(compressed_a[i] - 1);
        ft_left.add(compressed_a[i], 1);
    }

    FenwickTree ft_right(m);
    for (int i = n - 1; i >= 0; --i) {
        right_larger[i] = ft_right.query(m) - ft_right.query(compressed_a[i]);
        ft_right.add(compressed_a[i], 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += left_smaller[i] * right_larger[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
