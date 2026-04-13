#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int matched;
    int open;
    int close;
};

string s;
vector<Node> tree;

Node merge(const Node& left, const Node& right) {
    Node res;
    int new_matches = min(left.open, right.close);
    res.matched = left.matched + right.matched + new_matches;
    res.open = left.open + right.open - new_matches;
    res.close = left.close + right.close - new_matches;
    return res;
}

void build(int node, int start, int end) {
    if (start == end) {
        if (s[start - 1] == '0') {
            tree[node] = {0, 1, 0};
        } else {
            tree[node] = {0, 0, 1};
        }
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, 0, 0};
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    Node p1 = query(2 * node, start, mid, l, r);
    Node p2 = query(2 * node + 1, mid + 1, end, l, r);
    return merge(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> s) {
        int n = s.length();
        tree.resize(4 * n + 1);
        build(1, 1, n);

        int q;
        if (cin >> q) {
            while (q--) {
                int l, r;
                cin >> l >> r;
                Node res = query(1, 1, n, l, r);
                cout << res.matched * 2 << "\n";
            }
        }
    }
    return 0;
}

